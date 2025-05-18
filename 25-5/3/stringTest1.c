/*
    字符串小写换大写
*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>

void toUpper(char *ch, int len);

int main()
{
    char *ch = (char *)calloc(128, sizeof(char));
    assert(ch != NULL);
    fgets(ch, 128, stdin);
    size_t len = 0;
    for (size_t i = 0; i < 128; i++)
    {
        if (ch[i] == '\0')
        {
            len = i;
            break;
        }
    }
    toUpper(ch, len);
    printf("%s", ch);

    free(ch);
    ch = NULL;
    return 0;
}

void toUpper(char *ch, int len)
{
    for (char *p = ch; p < ch + len; p++)
    {
        if (islower(*p))
            *p = toupper(*p);
    }
}