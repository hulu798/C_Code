#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>

// 定义不同游戏难度棋盘大小
#define ROW_LEVEL_1 9
#define COL_LEVEL_1 ROW_LEVEL_1
#define ROW_LEVEL_2 13
#define COL_LEVEL_2 ROW_LEVEL_2
#define ROW_LEVEL_3 17
#define COL_LEVEL_3 ROW_LEVEL_3
#define ROWS_LEVEL_1 ROW_LEVEL_1 + 2
#define COLS_LEVEL_1 COL_LEVEL_1 + 2
#define ROWS_LEVEL_2 ROW_LEVEL_2 + 2
#define COLS_LEVEL_2 COL_LEVEL_2 + 2
#define ROWS_LEVEL_3 ROW_LEVEL_3 + 2
#define COLS_LEVEL_3 COL_LEVEL_3 + 2
#define MINE_NUMBER_LEVER_1 10
#define MINE_NUMBER_LEVEL_2 30
#define MINE_NUMBER_LEVEL_3 50

// 打印游戏开始菜单
void menu();

// 游戏进行函数
void game();

// 初始化棋盘
void initBoard(int rows, int cols, char set, char (*arr)[cols]);

// 打印数组
void print(int rows, int cols, char (*arr)[cols]);

// 设置雷
void setMine(int cols, int rows, char (*arr)[cols], int mineNum);

// 排雷
void findMine(int rows, int cols, char (*mine)[cols], char (*printBoard)[cols], int mineNum, time_t startTime);

// 检查周围位置雷数量
void countMine(int rows, int cols, int x, int y, char (*mine)[cols], char (*printBoard)[cols]);