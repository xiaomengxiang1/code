#include "Stack.h"

//压栈
void TestStack1() {
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	int a = StackTop(&st);
	printf("%d\n", a);

	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	StackDestory(&st);
}


void TestStack2() {
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//依次打印栈内数据
	while (!StackEmpty(&st)) {
		printf("%d ", st.top);
		StackPop(&st);
	}

	StackDestory(&st);
}

int main() {
	//TestStack1();
	TestStack2();
	return 0;
}