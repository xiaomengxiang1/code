#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//实现的是数组栈

typedef int STDataType;

typedef struct Stack {
	STDataType* a;
	int top; //栈顶
	int capacity; //容量
}ST;

//初始化
void StackInit(ST* ps);
//销毁栈
void StackDestory(ST* ps);


//压栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//取出栈顶元素
STDataType StackTop(ST* ps);
//栈的大小
int StackSize(ST* ps);
//栈是否为空
bool StackEmpty(ST* ps);