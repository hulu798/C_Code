/*
    字符串第一个不重复字符
*/

#include <stdio.h>

void findChar(char *, int, char *);

int main()
{
    char arr[128];
    fgets(arr, 128, stdin);
    int len = sizeof(arr) - 2;
    arr[len] = '\0';
    char target;
    findChar(arr, len, &target);
    printf("%c\n", target);
    return 0;
}

void findChar(char *arr, int len, char *target)
{
    *target = *arr;
    for (char *p = arr + 1; p < arr + len; p++)
    {
        if (*p == *target)
        {
            *target = *(p + 1);
            p++;
        }
    }
}