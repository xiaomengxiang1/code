#include "SList.h"

//打印链表
void SListPrint(SLNode* phead) {
	if (phead == NULL) {	
		printf("链表没东西可以打印\n");
		return;
	}
	SLNode* cur = phead;
	while (cur != NULL) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//开辟一个节点函数
SLNode* NewSListNode(SListTypeData x) {
	//开辟空间,直接在该空间存好值，等一下将尾部节点指向这边就好了
	SLNode* tem = (SLNode*)malloc(sizeof(SLNode));
	if (tem == NULL) {
		printf("开辟失败\n");
		exit(-1);
	}

	tem->data = x;
	tem->next = NULL;

	return tem;
}

//尾插
void SListPushBack(SLNode** pphead, SListTypeData x) {
	//开辟新的节点
	SLNode* tem = NewSListNode(x);

	if (*pphead == NULL) {
		*pphead = tem;
	}
	else {
		//找到尾部的节点
		SLNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}

		tail->next = tem;
	}
}

//头插
void SListPushFront(SLNode** pphead, SListTypeData x) {
	//开辟新的节点
	SLNode* tem = NewSListNode(x);

	//若*phead为空指针，则tem->next = NULL，然后*pphead改为新开辟的节点的地址，说明了*phead为空指针也是可以的没问题
	//头部节点换成新开辟的节点同时改变tem->next的值为原来第一个节点的地址
	//存储值
	tem->next = *pphead;
	*pphead = tem;

}

//尾删
void SListPopBack(SLNode** pphead) {
	//一个节点都没有的情况
	if (*pphead == NULL) {
		printf("没有节点可以删除\n");
		return;
	}

	//if剩下一个节点 else多个节点
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		//SLNode* prev = NULL;
		//SLNode* tail = *pphead;
		//// //while (tail->next != NULL)
		////等价的写法
		//while (tail->next) {
		//	prev = tail;
		//	tail = tail->next;
		//}

		//free(tail);
		//prev->next = NULL;

		//另一种写法
		SLNode* tail = *pphead;
		while (tail->next->next) {
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;
	}

}


//头删
void SListPopFront(SLNode** pphead) {
	//没有节点的情况
	if (*pphead == NULL) {
		printf("没有节点可以删除\n");
		return;
	}

	//1个或者多个节点
	//SLNode* to_delete = *pphead;
	//*pphead = to_delete->next;
	//free(to_delete);

	SLNode* to_new_node = (*pphead)->next;
	free(*pphead);
	*pphead = to_new_node;
}

//查找x,找不到返回null
SLNode* SListFind(SLNode* phead, SListTypeData x) {
	SLNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//在pos位置之前插入一个节点
void SListInsert(SLNode** pphead, SLNode* pos, SListTypeData x) {
	SLNode* new_node = NewSListNode(x);

	if (*pphead == pos) {
		//说明在第一个位置之前进行插入
		new_node->next = *pphead;
		*pphead = new_node;
	}
	else {
		//找到pos的前一个位置
		SLNode* pos_prev = *pphead;
		while (pos_prev->next != pos) {
			pos_prev = pos_prev->next;
		}
		pos_prev->next = new_node;
		new_node->next = pos;
	}
}


//在pos位置之后插入一个节点
void SListInsertAfter(SLNode* pos, SListTypeData x) {
	SLNode* new_node = NewSListNode(x);
	new_node->next = pos->next;
	pos->next = new_node;
}


//在pos位置删除节点
void SListErase(SLNode** pphead, SLNode* pos) {
	SLNode* cur = *pphead;
	//第一个为pos,删除头 
	if (pos == cur) {
		*pphead = pos->next;
		free(cur);
	}
	else {
		//找到pos前一个节点
		while (cur->next != pos) {
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}

//在pos位置之后删除一个节点
void SListEraseAfter(SLNode* pos) {
	SLNode* next = pos->next;
	pos->next = next->next;
	free(next);
}

//删除链表
void SListDestory(SLNode** pphead) {
	assert(*pphead);

	SLNode* cur = *pphead;
	while (cur) {
		SLNode* del = cur;
		cur = cur->next;
		free(del);
	}
	*pphead = NULL;
}
