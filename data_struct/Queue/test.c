#include "Queue.h"

QueueTest1() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);

	printf("%d\n", QueueFront(&q));

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	printf("%d\n", QueueBack(&q));
	printf("%d\n", QueueSize(&q));

	QueueDestory(&q);
}

QueueTest2() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q)) {
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}
	printf("\n");

	QueueDestory(&q);
}


int main() {
	//QueueTest1();
	QueueTest2();
	return 0;
}