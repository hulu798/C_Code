/*
    回文数判断
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPal(char *, int);

int main()
{
    char *ch = (char *)calloc(128, sizeof(char));
    fgets(ch, 128, stdin);
    int len = 0;
    for (len = 0; ch[len] != '\0'; len++)
        ;
    ch[len - 1] = '\0';
    len--;
    if (isPal(ch, len))
        printf("Yes\n");
    else
        printf("No\n");
    free(ch);
    ch=NULL;
    return 0;
}

bool isPal(char *ch, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (ch[i] != ch[len - 1 - i])
            return false;
    }
    return true;
}