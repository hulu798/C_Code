#include "game.h"

// 打印游戏开始菜单
void menu()
{
    printf("**********************\n");
    printf("*******  1.play ******\n");
    printf("*******  0.exit ******\n");
    printf("**********************\n");
}

// 游戏进行函数
void game()
{

    int row, col, mineNum;
    // 记录游戏开始时间
    time_t startTime = time(NULL);

    // 是否有效输入判断变量
    int effective = 1;
    while (1)
    {
        effective = 1;
        // 确定游戏模式
        printf("请选择游戏模式(1.简单 2.中等 3.困难 4.自定义模式):>");
        int mode = -1;
        scanf("%d", &mode);
        // 清空缓冲区
        while (getchar() != '\n')
            ;
        switch (mode)
        {
        case 1:
            row = ROW_LEVEL_1, col = COL_LEVEL_1, mineNum = MINE_NUMBER_LEVER_1;
            printf("已选择简单模式,游戏开始!(共10个雷).\n");
            break;
        case 2:
            row = ROW_LEVEL_2, col = COL_LEVEL_2, mineNum = MINE_NUMBER_LEVEL_2;
            printf("已选择中等模式,游戏开始!(共30个雷).\n");
            break;
        case 3:
            row = ROW_LEVEL_3, col = COL_LEVEL_3, mineNum = MINE_NUMBER_LEVEL_3;
            printf("已选择困难模式,游戏开始!(共50个雷).\n");
            break;
        case 4:
            while (1)
            {
                printf("已选择自定义模式,请输入行,列和地雷数(空格隔开).\n");
                printf("请保证行列均小于100:>\n");
                scanf("%d %d %d", &row, &col, &mineNum);
                if (row * col >= mineNum)
                    break;
                else
                    printf("输入数据有误!\n");
            }
            break;
        default:
            printf("输入数据错误请重新输入!\n");
            effective = 0;
            break;
        }
        if (effective)
            break;
    }
    int rows = row + 2, cols = col + 2;
    char mine[rows][cols], printBoard[rows][cols];

    // 初始化数组
    initBoard(rows, cols, '0', mine);
    initBoard(rows, cols, '*', printBoard);

    // 布置地雷
    setMine(rows, cols, mine, mineNum);

    // 打印数组
    print(rows, cols, printBoard);

    // 排雷
    findMine(rows, cols, mine, printBoard, mineNum, startTime);
}

// 初始化棋盘
void initBoard(int rows, int cols, char set, char (*arr)[cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = set;
    }
}

// 打印数组
void print(int rows, int cols, char (*arr)[cols])
{
    for (int i = 0; i <= cols - 2; i++)
        printf("%2d ", i);
    printf("\n");
    for (int i = 1; i <= rows - 2; i++)
    {
        printf("%2d ", i);
        for (int j = 1; j <= cols - 2; j++)
            printf("%2c ", arr[i][j]);
        printf("\n");
    }
}

// 设置雷
void setMine(int cols, int rows, char (*arr)[cols], int mineNum)
{
    while (mineNum != 0)
    {
        // 生成1~row,1~col随机数
        int x = rand() % (rows - 2) + 1, y = rand() % (cols - 2) + 1;
        if (arr[x][y] == '0')
        {
            arr[x][y] = '1';
            mineNum--;
        }
    }
}

void findMine(int rows, int cols, char (*mine)[cols], char (*printBoard)[cols], int mineNum, time_t startTime)
{
    // 记录标记使用数量,防止使用标记数量超过地雷数量
    int flag = mineNum;
    while (mineNum)
    {
        // 显示当前游戏时间
        time_t currentTime = time(NULL);
        int gameTime = (int)difftime(currentTime, startTime);
        printf("游戏时间: %02d:%02d:%02d\n", gameTime / 3600, (gameTime % 3600) / 60, gameTime % 60);

        // 初始化为-1可以排除输入非数字导致scanf不能读取的情况
        int x = -1, y = -1, choose = -1;

        // 选择标记还是排雷
        while (1)
        {
            choose = -1;
            printf("0.标记\n");
            printf("1.排雷\n");
            scanf("%d", &choose);
            // 清除缓冲区
            while (getchar() != '\n')
                ;
            if (choose == 0 || choose == 1)
                break;
            else
                printf("输入有误,请重新输入!\n");
        }

        // 排雷
        if (choose)
        {
            printf("请排雷(用空格隔开):>");
            scanf("%d %d", &x, &y);
            // 清空缓冲区
            while (getchar() != '\n')
                ;
            if (!(x >= 1 && x <= rows - 2) || !(y >= 1 && y <= cols - 2))
            {
                printf("输入错误,请重新输入!\n");
                continue;
            }
            else
            {
                // 排除已经排雷的情况
                if (printBoard[x][y] != '*')
                {
                    printf("重复输入,请重新输入!\n");
                    continue;
                }
                else if (mine[x][y] == '1')
                {
                    printf("踩雷了很遗憾,游戏失败!\n");
                    // 显示总用时
                    time_t endTime = time(NULL);
                    int totalTime = (int)difftime(endTime, startTime);
                    printf("游戏总用时: %02d:%02d:%02d\n", totalTime / 3600, (totalTime % 3600) / 60, totalTime % 60);
                    print(rows, cols, mine);
                    break;
                }
                else
                {
                    // 递归排雷
                    countMine(rows, cols, x, y, mine, printBoard);

                    print(rows, cols, printBoard);
                }
            }
        }
        else // 标记
        {

            int x = -1, y = -1;
            while (1)
            {
                printf("请标记(用空格隔开):>");
                scanf("%d %d", &x, &y);
                // 清除缓冲区
                while (getchar() != '\n')
                    ;
                if (!(x >= 1 && x <= rows - 2) || !(y >= 1 && y <= cols - 2))
                {
                    printf("输入错误,请重新输入!\n");
                }
                else if (printBoard[x][y] == '#') // 取消标记
                {
                    printf("取消标记(%d,%d)位置\n", x, y);
                    flag++;
                    printBoard[x][y] = '*';
                    if (mine[x][y] == '1')
                        mineNum++;
                    print(rows, cols, printBoard);
                    break;
                }
                else if (flag == 0)
                {
                    printf("标记数量过多,标记失败!\n");
                    break;
                }
                else
                {
                    printf("标记(%d,%d)位置\n", x, y);
                    flag--;
                    printBoard[x][y] = '#';
                    if (mine[x][y] == '1')
                        mineNum--;
                    print(rows, cols, printBoard);
                    break;
                }
            }
        }
        if (!mineNum)
        {
            printf("恭喜你游戏胜利!\n");
            // 显示总用时
            time_t endTime = time(NULL);
            int totalTime = (int)difftime(endTime, startTime);
            printf("游戏总用时: %02d:%02d:%02d\n", totalTime / 3600, (totalTime % 3600) / 60, totalTime % 60);
        }
    }
}

// 检查周围8个位置共几个雷,递归排雷
void countMine(int rows, int cols, int x, int y, char (*mine)[cols], char (*printBoard)[cols])
{
    if (!(x >= 1 && x <= rows - 2) || !(y >= 1 && y <= cols - 2))
        return;
    if (printBoard[x][y] != '*')
        return;
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (mine[i][j] == '1')
                count++;
        }
    }
    if (count != 0)
        printBoard[x][y] = count + '0';
    if (count == 0)
    {
        printBoard[x][y] = ' ';
        for (int i = x - 1; i <= x + 1; i++)
        {
            for (int j = y - 1; j <= y + 1; j++)
            {
                if (i == x && j == y)
                    continue;
                else
                    countMine(rows, cols, i, j, mine, printBoard);
            }
        }
    }
}