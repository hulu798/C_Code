/*
    洛谷B2118: 验证字串
*/

#include <stdio.h>
#include <string.h>

int isSubstring(char *, int, char *, int);

int main()
{
    char str1[22], str2[22];

    //不能使用fgets读取,因为fgets读取依赖于换行符或者确定读取的字符个数,在洛谷OJ环境中可能边界有问题,比如第二个字符串没有换行符结束,这个时候也需要保证程序正常运行
/*     fgets(str1, sizeof str1, stdin);
    fgets(str2, sizeof str2, stdin);
    int len1 = strlen(str1), len2 = strlen(str2);
    if (str1[len1 - 1] == '\n')
        str1[len1 - 1] = '\0', len1--;
    if (str2[len2 - 1] == '\n')
        str2[len2 - 1] = '\0', len2--; */
    scanf("%s %s", str1, str2);
    int len1 = strlen(str1), len2 = strlen(str2);

    int flag = 0;

    // 当两个字符串长度相等时
    if (len1 == len2)
    {
        // 检查是否完全相同
        if (strcmp(str1, str2) == 0)
        {
            printf("%s is substring of %s\n", str1, str2);
            return 0;
        }
        // 如果不同且长度相等，需要继续检查是否为子串
    }

    if (len1 <= len2)
    {
        flag = isSubstring(str1, len1, str2, len2);
        if (flag)
            printf("%s is substring of %s\n", str1, str2);
    }
    else if (len1 > len2)
    {
        flag = isSubstring(str2, len2, str1, len1);
        if (flag)
            printf("%s is substring of %s\n", str2, str1);
    }

    if (!flag)
        printf("No substring\n");
    return 0;
}

int isSubstring(char *str1, int len1, char *str2, int len2)
{
    for (int i = 0; i <= len2 - len1; i++)
    {
        int judge = 0;
        int j = 0;
        if (*(str2 + i) == *str1)
        {
            for (j = 0; j < len1; j++)
            {
                if (*(str1 + j) != *(str2 + i + j))
                    break;
                if (j == len1 - 1)
                    judge = 1;
            }
        }
        if (judge)
            return 1;
    }
    return 0;
}