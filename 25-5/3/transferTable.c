/*
    转移表:函数指针实现简易计算器
*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*pf_t)(int, int);

int Add(int, int);
int Sub(int, int);
int Mul(int, int);
int Div(int, int);

int main()
{
    pf_t pArr[4] = {Add, Sub, Mul, Div};
    int input = 0, x, y;
    do
    {
        printf("1.add\n2.sub\n3.mul\ndiv\n0.exit\n");
        scanf("%d", &input);
        if (input)
        {
            printf("请输入操作数:>\n");
            scanf("%d %d", &x, &y);
            printf("计算结果为:%d\n", pArr[input - 1](x, y));
        }
    } while (input);
    system("pause");
    return 0;
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}