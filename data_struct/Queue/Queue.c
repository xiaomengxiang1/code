#include "Queue.h"

//初始化队列
void QueueInit(Queue* pq) {
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
}

//销毁队列
void QueueDestory(Queue* pq) {
	assert(pq);

	QueueNode* cur = pq->head;
	while (cur != NULL) {
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//入队列
void QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QueueNode* new_node = (QueueNode*)malloc(sizeof(QueueNode));
	new_node->data = x;
	new_node->next = NULL;

	//入队时应该是尾插
	//如果开始时tail为为NULL
	if (pq->tail == NULL) {
		pq->head = pq->tail = new_node;
	}
	else {
		pq->tail->next = new_node;
		pq->tail = new_node;
	}
}

//出队列
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq)); // 防止对空队列调用

	//如果只有一个节点
	if (pq->head == pq->tail) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//队头的值
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

//队尾的值
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

//队列的大小
int QueueSize(Queue* pq) {
	assert(pq);

	QueueNode* cur = pq->head;
	int count = 0;
	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

//队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);

	return pq->head == NULL;
}