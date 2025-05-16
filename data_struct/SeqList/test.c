#include "SeqList.h"

void TestSeqList1() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPrint(&sl);


	SeqListDestory(&sl);
}

void TestSeqList2() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrint(&sl);


	SeqListDestory(&sl);
}

void TestSeqList3() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 2, 10);
	SeqListPrint(&sl);

	SeqListErase(&sl, 3);
	SeqListPrint(&sl);

	SeqListDestory(&sl);
}

int main() {
	
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}