#pragma once
//声明的头文件
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_PEO 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 20
#define MAX_ADDR 30
//类型的声明
//人的信息
typedef struct PeoInfo {
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    int tele[MAX_TELE];
    char addr[MAX_ADDR];
}PeoInfo;


//整个通讯录信息
typedef struct Contact {
    PeoInfo data[MAX_PEO];//存放人的信息
    int count;//记录人的个数
}Contact;

//初始化函数
void Initcon(Contact* con);

//添加联系人函数
void Addcontact(Contact* con);

//展示联系人信息函数
void Showcontact(const Contact* con); 

//删除指定联系人
void Delcontact(Contact* con);

//查找联系人
void Searchcontact(const Contact* con);

//修改联系人信息
void Modifycontact(Contact* con);

//排序联系人的信息
//按名字排序
void Sortcontact(Contact* con);
