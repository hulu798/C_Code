/**
 * find.c - 文件内容查找程序
 * 运行方式：./find.exe 文件名(路径) "搜索内容" [-i]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 512 // 最大行长度

// 查找模式函数指针类型定义
typedef int (*SearchFunction)(const char *line, const char *pattern);

// 精确匹配模式
int exact_match(const char *line, const char *pattern)
{
    return strstr(line, pattern) != NULL ? 1 : 0;
}

// 不区分大小写模式
int case_insensitive_match(const char *line, const char *pattern)
{
    char line_lower[MAX_LINE];
    char pattern_lower[MAX_LINE];
    int i;

    // 将line转换为小写
    for (i = 0; line[i] && i < MAX_LINE - 1; i++)
    {
        line_lower[i] = tolower(line[i]);
    }
    line_lower[i] = '\0';

    // 将pattern转换为小写
    for (i = 0; pattern[i] && i < MAX_LINE - 1; i++)
    {
        pattern_lower[i] = tolower(pattern[i]);
    }
    pattern_lower[i] = '\0';

    return strstr(line_lower, pattern_lower) != NULL ? 1 : 0;
}

// 查找文件函数
int search_file(const char *filename, const char *pattern, SearchFunction search_func)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("无法打开文件: %s\n", filename);
        return 0;
    }

    char line[MAX_LINE];
    int line_number = 0;
    int match_count = 0;

    printf("\n开始搜索文件: %s\n", filename);
    printf("搜索内容: \"%s\"\n\n", pattern);

    // 逐行读取文件
    while (fgets(line, sizeof(line), file))
    {
        line_number++;

        // 移除换行符
        char *newline = strchr(line, '\n');
        if (newline)
            *newline = '\0';

        if (search_func(line, pattern))
        {
            printf("匹配行 %2d: %s\n", line_number, line);
            match_count++;
        }
    }

    fclose(file);
    return match_count;
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("文件内容查找:\n");
        printf("用法: %s <文件名> <搜索内容> [-i]\n", argv[0]);
        printf("选项(可选):\n");
        printf("  -i  不区分大小写搜索\n");
        return 1;
    }

    char *filename = argv[1];
    char *pattern = argv[2];
    int case_insensitive = 0;

    // 检查模式
    if (argc > 3 && strcmp(argv[3], "-i") == 0)
    {
        case_insensitive = 1;
        printf("已启用不区分大小写搜索\n");
    }

    SearchFunction search_func;
    if (case_insensitive)
    {
        search_func = case_insensitive_match;
        printf("使用不区分大小写匹配函数\n");
    }
    else
    {
        search_func = exact_match;
        printf("使用精确匹配函数\n");
    }

    SearchFunction search_functions[] = {exact_match, case_insensitive_match};

    int match_count = search_file(filename, pattern, search_func);

    if (match_count > 0)
    {
        printf("\n搜索完成,共找到%3d处匹配内容\n", match_count);
    }
    else
    {
        printf("\n未找到匹配内容\n");
    }

    return 0;
}