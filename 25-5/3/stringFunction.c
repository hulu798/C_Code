/** 
 * 字符串函数自己实现,紧凑高效的方法,剔除冗余代码
*/

#include<stdio.h>
#include<assert.h>

//字符串长度strlen
size_t my_strlen(const char *destination)
{
    assert(destination);
    const char *begin=destination;
    while(*destination++);
    return (size_t)(--destination-begin);
}

//字符串拼接strcat
char* my_strcat(char* destination,const char *source)
{
	assert(destination && source);
    char *p1=destination-1;
    while(*++p1);
    while((*p1++=*source++));
    return destination;
}

//字符串复制strcpy
char *my_strcpy(char *destination,const char *source)
{
	assert(destination && source);
    char *p1=destination;
    while((*p1++=*source++));	
    return destination; 
}

//字符串比较strcmp
int my_strcmp(const char *str1,const char *str2)
{
    assert(str1 && str2);
    while(*str1++==*str2++)
        if(!*--str1) return 0;
    return *str1-*str2;
}

//字符串复制strncpy
char *my_strncpy(char* destination,const char*source,size_t n)
{
    assert(destination && source);
    char *p=destination;
    while(n-- && (*destination++=*source++));
    while(n-->0) *destination++='\0';
    return p;
}

//字符串拼接strncat
char *my_strncat(char* destination,const char* source,size_t n)
{
    assert(destination && source);
    char *p=destination;
    while(*destination++);
    destination--;
    while(n-- && (*destination++=*source++));
    *destination='\0';
    return p;
}

//字符串比较strncmp
int my_strncmp(const char *p1,const char *p2,int count)
{
    assert(p1 && p2);
    while(count-- && *p1++==*p2++)
        if(!*--p1) return 0;
    return *--p1-*--p2;

}

//字符串查找
char *my_strstr(const char *str1, const char *str2)
{
    assert(str1 && str2);
    const char *str1p = str1, *str2p = str2;
    const char *ret = str1;
    while (*ret)
    {
        str1p=ret;
        str2p=str2;
        while (*str1p++ == *str2p++)
            if(!*str2p) return (char*)ret;
        ret++;
    }
    return NULL;
}


int main()
{
    char arr[128]="你好世界";
    char a[]="hello world";
    printf("%s\n",my_strncat(arr,a,7));
    return 0;
}