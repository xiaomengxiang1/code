#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListTypeData;

typedef struct SListNode {
	SListTypeData data;
	struct SListNode* next;
}SLNode;

//打印链表
void SListPrint(SLNode* phead);
//开辟一个节点函数
SLNode* NewSListNode(SListTypeData x);
//尾插
void SListPushBack(SLNode** pphead, SListTypeData x);
//头插
void SListPushFront(SLNode** pphead, SListTypeData x);
//头删
void SListPopFront(SLNode** pphead);
//尾删
void SListPopBack(SLNode** pphead);

//查找x
SLNode* SListFind(SLNode* phead, SListTypeData x);
//在pos位置之前插入一个节点
void SListInsert(SLNode** pphead, SLNode* pos, SListTypeData x);
//在pos位置之后插入一个节点
void SListInsertAfter(SLNode* pos, SListTypeData x);
//在pos位置删除节点
void SListErase(SLNode** pphead, SLNode* pos);
//在pos位置之后删除一个节点
void SListEraseAfter(SLNode* pos);
//删除链表
void SListDestory(SLNode** pphead);

