#include "game.c"

void menu() {
    printf("******************************\n");
    printf("***    1. play  0. exit    ***\n");
    printf("******************************\n");
}

void game() {
    char mine[ROWS][COLS] = {0};    //放布置好的雷的信息
    char show[ROWS][COLS] = {0};    //存放排查出的雷的信息

    //初始化
    //mine 没布置雷的时候都是'0'
    InitBoard(mine, ROWS, COLS, '0');
    
    //show 没排查雷的时候都是'*'
    InitBoard(show, ROWS, COLS, '*');

    
    //设置雷
    Setmine(mine, ROW, COL);
    Display(mine, ROW, COL);
    Display(show, ROW, COL);

    //排查雷
    Findmine(mine, show, ROW, COL);
}

int main() {
    int  input = 0;
    //设置随机数的生成起点

    srand((unsigned int)time(NULL));

    do {
        menu();
        printf("请选择>");
        scanf("%d", &input);

        switch (input) {
            case 1:
                printf("扫雷\n");
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

    return 0;
}