#include "game.h"

int main()
{
    SetConsoleOutputCP(65001);
    srand((unsigned)time(NULL));
    int choose = -1;
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &choose);
        // 清空缓冲区,避免错误输入非数字导致死循环
        while (getchar() != '\n')
            ;
        switch (choose)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏.\n");
            break;
        default:
            printf("输入错误,请重新输入.\n");
            break;
        }
    } while (choose);
    system("pause");
    return 0;
}