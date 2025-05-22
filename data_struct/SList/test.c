#include "SList.h"


void Test_1() {
	//一级指针的变量，函数内部应该用二级指针接受,否则会出现形参改变不了实参的问题
	SLNode* Plist = NULL;
	SListPrint(Plist);

	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 5);

	SListPrint(Plist);

	SListPushFront(&Plist, 6);
	SListPushFront(&Plist, 7);

	SListPrint(Plist);

}

void Test_2() {
	//一级指针的变量，函数内部应该用二级指针接受,否则会出现形参改变不了实参的问题
	SLNode* Plist = NULL;
	SListPrint(Plist);

	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 5);

	SListPopBack(&Plist);
	SListPopBack(&Plist);
	SListPopBack(&Plist);
	SListPopBack(&Plist);
	SListPopBack(&Plist);
	SListPopBack(&Plist);

	SListPrint(Plist);
}

void Test_3() {
	//一级指针的变量，函数内部应该用二级指针接受,否则会出现形参改变不了实参的问题
	SLNode* Plist = NULL;


	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 5);
	SListPrint(Plist);

	SListPopFront(&Plist);
	SListPopFront(&Plist);
	SListPopFront(&Plist);
	SListPopFront(&Plist);
	SListPopFront(&Plist);
	SListPopFront(&Plist);

	SListPrint(Plist);
}

void Test_4() {
	//一级指针的变量，函数内部应该用二级指针接受,否则会出现形参改变不了实参的问题
	SLNode* Plist = NULL;


	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 5);
	SListPushBack(&Plist, 2);
	SListPrint(Plist);
	//多次查找
	SLNode* pos = SListFind(Plist, 2);
	int i = 1;
	while (pos) {
		printf("这是第%d个pos节点，%p->%d\n", i++, pos, pos->data);
		pos = SListFind(pos->next, 2);
	}
	//找到位置可以进行修改
	pos = SListFind(Plist, 3);
	if (pos) {
		pos->data = 333;
	}

	SListPrint(Plist);
}

void Test_5() {
	SLNode* Plist = NULL;

	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPushBack(&Plist, 2);
	SListPrint(Plist);

	SLNode* pos = SListFind(Plist, 1);
	if (pos) {
		SListInsert(&Plist, pos, 40);
	}

	SListPrint(Plist);

	//找到第一个pos位置，在该位置之前插入一个新的节点
	pos = SListFind(Plist, 2);
	//逐个找到
	while (pos) {
		SListInsert(&Plist, pos, 30);
		pos = SListFind(pos->next, 2);
	}

	SListPrint(Plist);
}

void Test_6() {
	SLNode* Plist = NULL;

	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPrint(Plist);

	SLNode* pos = SListFind(Plist, 1);
	SListErase(&Plist, pos);
	SListPrint(Plist);


}

void Test_7() {
	SLNode* Plist = NULL;

	SListPushBack(&Plist, 1);
	SListPushBack(&Plist, 2);
	SListPushBack(&Plist, 3);
	SListPushBack(&Plist, 4);
	SListPrint(Plist);

	SLNode* pos = SListFind(Plist, 2);
	SListEraseAfter(pos);
	SListPrint(Plist);

	SListDestory(&Plist);
	SListPrint(Plist);
}

int main() {
	//Test_1();
	//Test_2();
	//Test_3();
	//Test_4();
	//Test_5();
	//Test_6();
	Test_7();
	return 0;
}