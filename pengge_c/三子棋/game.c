#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "game.h"


#define ROW 3
#define COL 3


// //初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            board[i][j] = ' ';
        }
    }
}

//打印棋盘
//版本1
// void DisplayBoard(char board[ROW][COL], int row, int col) {
//     int i = 0;
//     for (i = 0; i < row; i++) {
//         //打印数据
//         printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//         //打印分隔符
//         if (i < row - 1) {
//             printf("---|---|---\n");
//         }
//     }
// }

//版本2
void DisplayBoard(char board[ROW][COL], int row, int col) {
    int i = 0;
    for (i = 0; i < row; i++) {
        // //打印数据
        // printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        int j = 0;
        for (j = 0; j < col; j++) {
            printf(" %c ", board[i][j]);

            if (j < col - 1) {
                printf("|");
            }
        }
        printf("\n");
        //打印分隔符
        // printf("---|---|---\n");
        //最后一行没打印
        //每一行的第三个没打印
        if (i < row - 1) {
            int j = 0;
            for (j = 0; j < col; j++) {
                printf("---");
                if (j < col -1) {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}


//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col) {
    int x = 0;
    int y = 0;
    printf("玩家下棋>\n");

    while (1){

        printf("请输入坐标>");
        scanf("%d %d", &x, &y);

        //坐标合法性的判断
        if (x >= 1 && x <= row && y >= 1 && y <= col) {
            if (board[x-1][y-1] == ' ') {
                board[x-1][y-1] = '*';
                break;
            }
            else {
                printf("坐标被占用,请选择其他的位置\n");
            }
        }
        else {
            printf("坐标非法,请重新输入\n");
        }
    }
    
    
}

//电脑下棋
//找没下棋的位置随机下
void ComputerMove(char board[ROW][COL], int row, int col) {
    printf("电脑下棋>\n");

    int x = 0;
    int y = 0;

    while (1) {

        x = rand() % row;   //0 ~ 2
        y = rand() % col;   //0 ~ 2

        if (board[x][y] == ' ') {
            board[x][y] = '#';
            break;
        }
    } 
}

//满了返回1
//不满返回0
int Isfull(char board[ROW][COL], int row, int col) {
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}
//玩家赢-"*"
//电脑赢-"#"
//平局-"q"
//继续-"c"
char Iswin(char board[ROW][COL], int row, int col) {
    //行
    int i = 0;
    for (i = 0; i < row; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
            return board[i][1];
        }
    }
    //列
    int j = 0;
    for (j = 0; j < col; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
            return board[1][j];
        }
    }    

    //对角线
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
        return board[1][1];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
        return board[1][1];
    }
    //平局
    if (Isfull(board, row, col)) {
        //满了
        return 'q';
    }

    // 游戏继续
    return 'c';
}