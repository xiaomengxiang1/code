#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

#define EASY_COUNT 10

//初始化
void InitBoard(char board[ROWS][COLS], int row, int col, char set) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            board[i][j] = set;
        } 
    }
}

//打印棋盘
void Display(char board[ROWS][COLS], int row, int col) {
    int i = 0;
    int j = 0;

    printf("------扫雷游戏-----\n");
    for (j = 0; j <= col; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (i = 1; i <= row; i++) {
        printf("%d ", i);
        for(j = 1; j <= col; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n"); 
    }
    printf("------扫雷游戏-----\n");
}

//设置雷
void Setmine(char board[ROWS][COLS], int row, int col) {
    int count = EASY_COUNT;
    while (count) {
        int x = rand() % row + 1;
        int y = rand() % col + 1;

        if (board[x][y] == '0') {

            board[x][y] = '1';
            count--;
        }
    }
}

//一个坐标周围的雷
int get_my_count(char board[ROWS][COLS], int x, int y) {
    return (board[x - 1][y] + 
        board[x -1][y - 1] + 
        board[x][y - 1] + 
        board[x + 1][y - 1] + 
        board[x + 1][y] + 
        board[x + 1][y + 1] + 
        board[x][y + 1] + 
        board[x - 1][y + 1] - 8 * '0');
}

//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
    int x = 0;
    int y = 0;
    int win = 0;    //找到非雷的个数

    //判断坐标的合法性
    while (win < row * col - EASY_COUNT) {
        printf("请输入要排查的坐标:>");
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= 10 && y >= 1 && y <= 10) {
            if (show[x][y] != '*') {
                printf("这个位置已经排查过了\n");
            }

            else {
                            //如果是雷
                if (mine[x][y] == '1') {
                    printf("你被炸死了\n");
                    Display(mine, ROW, COL);
                    break;
                }

                //不是雷
                else {

                    win++;
                    //统计mine数组xy坐标周围的雷的个数
                    int count = get_my_count(mine, x, y);
                    show[x][y] = count + '0'; //装换成字符存储
                    Display(show, ROW, COL);
                }
            }
        }
        else {
            printf("输入的坐标非法,请重新输入\n");
        }
    }
    if (win = row * col - EASY_COUNT) {
        printf("恭喜你排雷成功\n");
        Display(show, ROW, COL);
    }
}
