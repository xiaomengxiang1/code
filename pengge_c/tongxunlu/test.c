#define _CRT_SECURE_NO_WARNINGS 1
// 实现一个通讯录：
// 人的信息：
// 名字+年龄+性别+电话+地址1.存放100个人的信息
// 2.增加联系人 
// 3.删除指定联系人 
// 4.查找联系人 
// 5.修改联系人 
// 6.排序 
// 7.显示联系人 

// <contact.h> 是找系统头文件路径的，
// "contact.h" 是找当前目录或者设置的 includePath里的，


// g++ E:\vscode_project\C_project\pengge_c\tongxunlu\test.c E:\vscode_project\C_project\pengge_c\tongxunlu\contact.c -o E:\vscode_project\C_project\output\test.exe
// 部分	含义
// g++	用 g++编译器 编译程序。（虽然是 C 文件，g++也能编，兼容C，默认以C++标准，问题不大）
// E:\...\test.c	第一个源文件：test.c（你的主程序，里面写了 main()）
// E:\...\contact.c	第二个源文件：contact.c（里面实现了函数，比如 Initcon(Contact*)）
// -o E:\...\test.exe	指定输出文件的名字，生成一个 test.exe 可执行程序
#include "contact.h"

void menu() {
    printf("*************************************\n");
    printf("****** 1.add        2.del       *****\n");
    printf("****** 3.search     4.modify    *****\n");
    printf("****** 5.show       6.sort      *****\n");
    printf("****** 0.exit                   *****\n");
    printf("*************************************\n");
}

enum {
    //枚举常量
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
};

int main() {

    int input = 0;

    Contact con; //通讯录
    //初始化通讯录
    Initcon(&con);

    do {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input) {
        case ADD:
            Addcontact(&con);
            break;
        case DEL:
            Delcontact(&con);
            break;
        case SEARCH:
            Searchcontact(&con);
            break;
        case MODIFY:
            Modifycontact(&con);
            break;
        case SHOW:
            Showcontact(&con);
            break;
        case SORT:
            Sortcontact(&con);
            break;
        case EXIT:
            Save_contact(&con);
            Destroy_contact(&con);
            printf("退出程序\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);

    return 0;
}