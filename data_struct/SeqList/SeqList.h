#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDataType;

//动态顺序表
typedef struct SeqList {
    SLDataType* a;
    int size; //表示存储的数据的个数
    int capacity; //可以存储的数据的个数(总的容量)
}SL;

//静态的插入满了就不能继续插入了 对比通讯录
//接口函数

//初始化
void SeqListInit(SL* ps);

//销毁
void SeqListDestory(SL* ps);

//打印顺序表
void SeqListPrint(SL* ps);
//扩容函数
void new_memory(SL* ps);
//尾部插入
void SeqListPushBack(SL* ps, SLDataType x);
//尾部删除
void SeqListPopBack(SL* ps);
//头部插入
void SeqListPushFront(SL* ps, SLDataType x);
//头部删除
void SeqListPopFront(SL* ps);

//找数据是否存在，没有返回-1
int SeqListFind(SL* ps, SLDataType x);
//指定pos位置插入数据
void SeqListInsert(SL* ps, int pos, SLDataType x);
//删除pos位置的数据 
void SeqListErase(SL* ps, int pos);
