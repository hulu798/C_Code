/** 
 * 字符串函数自己实现,紧凑高效的方法,剔除冗余代码
*/

#include<stdio.h>
#include<assert.h>

size_t myStrlen(const char *str)
{
    assert(str);
    const char *p=str;
    while(*p++);
    return p-str-1;
}

char *myStrcpy(char *destination,const char *source)
{
    assert(destination && source);
    char *p=destination;
    while((*p++=*source++));
    return destination;
}

char *myStrcat(char *destination,const char *source)
{
    assert(destination && source);
    char *p=destination-1;
    while(*++p);
    while((*p++=*source++));
    return destination;
}

int myStrcmp(const char *str1,const char *str2)
{
    assert(str1 && str2);
    while(*str1++==*str2++)
        if(!*(str1-1)) return 0;
    return *--str1-*--str2;
}

char *myStrncpy(char* destination,const char *source,size_t n)
{
    assert(destination && source);
    char *p=destination;
    for(n++;--n && (*p++=*source++););
    while(n--) *p++=0;
    return destination;
}

char *myStrncat(char *destination,const char *source,size_t n)
{
    char *p=destination;
    while(*p++);
    for(n++,p--;--n && (*p++=*source++););
    return destination;
}

int myStrncmp(const char *str1,const char *str2,size_t n)
{
    assert(str1 && str2);
    for(n++;--n && (*str1++==*str2++);)
        if(!*(str1-1)) return 0;
    return *--str1-*--str2;
}

char *myStrstr(const char *str1,const char *str2)
{
    assert(str1 && str2);
    const char *p1=str1,*p2=str2;
    while(*str1)
    {
        p1=str1;
        p2=str2;
        while(*p1++==*p2++)
            if(!*p2) return (char*)str1;
        str1++;
    }
    return NULL;
}

char *myStrtok(char *str,const char *delim)
{
    assert(delim);
    static char *end=NULL;
    if(str) end=str;
    else str=end;

    //字符串结尾
    if(!str || !*str) return NULL;

    for(;*end;end++)
    {
        for(const char *p=delim;*p;p++)
            if(*end==*p)
            {
                *end++='\0';
                return str;
            }
    }

    //字符串末尾
    end=NULL;
    return str;
}


int main()
{
    char arr[128]="你好世界";
    char a[]="hello world";
    printf("%s\n",my_strncat(arr,a,7));
    return 0;
}