//声明的头文件
#include <stdio.h>
#include <string.h>


//类型的声明
//人的信息
typedef struct PeoInfo {
    char name[20];
    int age;
    char sex[10];
    int tele[20];
    char addr[30];
}PeoInfo;


//整个通讯录信息
typedef struct Contact {
    PeoInfo data[100];//存放人的信息
    int count;//记录人的个数
}Contact;

void Initcon(Contact* con);
