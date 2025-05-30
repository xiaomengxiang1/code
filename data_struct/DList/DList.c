#include "DList.h"
//带哨兵位的

//初始化
DLNode* ListInit() {
	//创建带哨兵位的头结点
	DLNode* phead = (DLNode*)malloc(sizeof(DLNode));
	phead->next = phead;
	phead->prev = phead;
	return	phead;
}

//删除链表
void ListDestory(DLNode* phead) {
	assert(phead);
	DLNode* cur = phead->next;
	while (cur != phead) {
		DLNode* del = cur;
		cur = cur->next;
		free(del);
	}
	//phead->next = phead;
	//phead->prev = phead;
	free(phead);  // 如果你之后不打算再用这个phead，可以free它
}

//打印
void ListPrint(DLNode* phead) {
	assert(phead);

	DLNode* cur = phead->next;
	printf("head->");
	while (cur != phead) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//开辟新的节点
DLNode* NewListNode(SLDateType x) {
	DLNode* new_node = (DLNode*)malloc(sizeof(DLNode));
	new_node->data = x;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}

//尾插
void ListPushBack(DLNode* phead, SLDateType x) {
	assert(phead);
	////phead->prev这个就是尾部节点,链接尾部节点和new节点
	//DLNode* tail = phead->prev;
	//DLNode* new_node = NewListNode(x);

	//tail->next = new_node;
	//new_node->prev = tail;
	////头结点和尾部节点链接
	//new_node->next = phead;
	//phead->prev = new_node;
	ListInsert(phead, x);
}


//尾删
void ListPopBack(DLNode* phead) {
	assert(phead);
	////确保只剩哨兵位的时候不要把哨兵干掉了
	assert(phead != phead->next);

	//DLNode* tail = phead->prev; 
	//DLNode* tail_prev = tail->prev;
	//free(tail);

	//tail_prev->next = phead;
	//phead->prev = tail_prev;
	ListErase(phead->prev);
}

//头插
void ListPushFront(DLNode* phead, SLDateType x) {
	assert(phead);

	//DLNode* new_node = NewListNode(x);
	////保存哨兵位的下一个节点
	//DLNode* head_next = phead->next;
	//new_node->prev = phead;
	//new_node->next = head_next;

	//phead->next = new_node;
	//head_next->prev = new_node;
	ListInsert(phead->next, x);
}


//头删
void ListPopFront(DLNode* phead) {
	assert(phead);
	assert(phead != phead->next);

	//DLNode* del_next = phead->next->next;

	//free(phead->next);
	//phead->next = del_next;
	//del_next->prev = phead;
	ListErase(phead->next);
}

//查找x
DLNode* ListFind(DLNode* phead, SLDateType x) {
	assert(phead);
	//哨兵位下一个
	DLNode* cur = phead->next;
	while (cur != phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

//在pos位置之前插入一个节点
void ListInsert(DLNode* pos, SLDateType x) {
	assert(pos);

	DLNode* new_node = NewListNode(x);
	DLNode* pos_prev = pos->prev;

	pos_prev->next = new_node;
	new_node->prev = pos_prev;

	new_node->next = pos;
	pos->prev = new_node;
}


//在pos位置删除节点
void ListErase(DLNode* pos) {
	assert(pos);

	DLNode* pos_prev = pos->prev;
	DLNode* pos_next = pos->next;

	pos_prev->next = pos_next;
	pos_next->prev = pos_prev;
	free(pos);
	pos = NULL;
}