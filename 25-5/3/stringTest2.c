/*
    去除字符串的空格&统计单词个数
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

void rmSpace(char *ch, int len);
size_t countWords(char *ch, int len);
int main()
{
    char *ch = calloc(128, sizeof(char));
    assert(ch != NULL);
    fgets(ch, 128, stdin);
    int len = 0;
    for (len = 0; ch[len] != '\0'; len++)
        ;
    printf("%d\n", countWords(ch, len));
    rmSpace(ch, len);
    printf("%s", ch);

    return 0;
}

void rmSpace(char *ch, int len)
{
    int j = 0, i = 0;
    for (j = 0, i = 0; i < len - 1; i++)
    {
        if (ch[i] != ' ')
            ch[j++] = ch[i];
    }
    ch[j] = '\0';
}

size_t countWords(char *ch, int len)
{
    int count = 0;
    for (int i = 1; i < len; i++)
    {
        if (isspace(ch[i]) && isalpha(ch[i - 1]))
            count++;
    }
    return count;
}