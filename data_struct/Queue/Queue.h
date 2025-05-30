#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//使用的是链表的结构,数组的结构进行出队时候还要调整每一个数据的位置，不方便
//这里增加了头尾指针，方便进行操作(没有哨兵位的，不要记错了)
typedef int QDataType;

typedef struct QueueNode {
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue {
	QueueNode* head;
	QueueNode* tail;
}Queue;

//初始化队列
void QueueInit(Queue* pq);
//销毁队列
void QueueDestory(Queue* pq);


//入队列
void QueuePush(Queue* pq, QDataType x);
//出队列
void QueuePop(Queue* pq);
//队头的值
QDataType QueueFront(Queue* pq);
//队尾的值
QDataType QueueBack(Queue* pq);
//队列的大小
int QueueSize(Queue* pq);
//队列是否为空
bool QueueEmpty(Queue* pq);