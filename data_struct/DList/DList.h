#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Doubly Linked List	双链表

typedef int SLDateType;

typedef struct ListNode {
	SLDateType data;
	struct ListNode* next;
	struct ListNode* prev ;
}DLNode;

//初始化
DLNode* ListInit();
//打印
void ListPrint(DLNode* phead);
//开辟新的节点
DLNode* NewListNode(SLDateType x);
//删除链表
void ListDestory(DLNode* phead);

//尾插
void ListPushBack(DLNode* phead, SLDateType x);
//尾删
void ListPopBack(DLNode* phead);
//头插
void ListPushFront(DLNode* phead, SLDateType x);
//头删
void ListPopFront(DLNode* phead);


//查找x
DLNode* ListFind(DLNode* phead, SLDateType x);
//在pos位置之前插入一个节点
void ListInsert(DLNode* pos, SLDateType x);
//在pos位置删除节点
void ListErase(DLNode* pos);