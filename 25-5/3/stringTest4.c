#include <stdio.h>
#include <string.h>

char *findSubstr(char *, char *, char *);

int main()
{
    char str1[128];
    char str2[128];
    scanf("%s %s", str1, str2);
    char dst[128];
    findSubstr(str1, str2, dst);
    printf("%s\n", dst);
    return 0;
}

char *findSubstr(char *str1, char *str2, char *dst)
{
    size_t maxLen = 0;
    char *maxStr = NULL;
    for (char *pStr1 = str1; *pStr1; pStr1++)
    {
        char *pt1, *pt2;
        for (char *pStr2 = str2; *pStr2; pStr2++)
        {
            size_t len = 0;
            pt1 = pStr1, pt2 = pStr2;
            for (pt1 = pStr1, pt2 = pStr2; pt1 && pt2 && *pt1 == *pt2; pt1++, pt2++, len++)
                ;
            if (len > maxLen)
            {
                maxLen = len;
                maxStr = pStr1;
            }
        }
    }

    // 返回结果
    if (maxLen == 0)
        return NULL;
    else
    {
        strncpy(dst, maxStr, maxLen);
        dst[maxLen] = '\0';
        return dst;
    }
}
