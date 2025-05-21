/* 
    字符串向左旋转
*/

#include <stdio.h>
#include <string.h>

void move(char *, int, int);
int main()
{
    char arr[128];
    fgets(arr, 128, stdin);
    int len = strlen(arr) - 1;
    arr[len] = '\0';
    int mvBitsNum;
    scanf("%d", &mvBitsNum);
    move(arr, len, mvBitsNum);
    printf("%s\n", arr);
    return 0;
}

void move(char *arr, int len, int mvBitsNum)
{
    char temp[mvBitsNum];
    for (int i = 0; i < mvBitsNum; i++)
        temp[i] = arr[i];
    int j = 0, i;
    for (j = 0, i = mvBitsNum; i < len; i++)
        arr[j++] = arr[i];
    for (i = 0; i < mvBitsNum; i++)
        arr[len - mvBitsNum + i] = temp[i];
}