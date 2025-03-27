#include "game.c"
// #include "game.h"

void menu() {
    printf("******************************\n");
    printf("***    1. play  0. exit    ***\n");
    printf("******************************\n");
}

void game() {

    char board[ROW][COL] = {0};

    //初始化棋盘的函数
    InitBoard(board, ROW, COL);
    DisplayBoard(board, ROW, COL);

    //下棋
    while (1) {
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断输赢
        ComputerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断输赢

    }

}


int main() {

    srand((unsigned int)time(NULL));    //设置随机数的生成起点

    int input = 0;

    do {
        menu();     //打印菜单
        printf("请选择>");
        scanf("%d", &input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
            printf("退出游戏\n");
                break;
            default:
            printf("选择错误\n");
                break;
        }
    } while (input);



}