/* 
    找到最大公共子串
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    //分配内存,读入字符串
    char *str1=calloc(128,sizeof(char));
    char *str2=calloc(128,sizeof(char));
    fgets(str1,128,stdin);
    fgets(str2,128,stdin);
    //找到公共子串

    //释放内存
    free(str1),free(str2);
    str1=str2=NULL;
    return 0;
}