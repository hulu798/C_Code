/*
    P1010 [NOIP 1998 普及组] 幂次方
*/

#include <stdio.h>

int between_bin(int);
int main()
{
    int num;
    scanf("%d", &num);
    
    return 0;
}

int between_bin(int num)
{
    int ret = 0;
    while (num > 1)
    {
        num /= 2;
        ret += 1;
    }
    return ret;
}