#include "DList.h"


//尾插尾删测试
void TestList1() {
	DLNode* plist = ListInit();
	//初始化后进行尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);

	ListPrint(plist);
}

//头插头删测试
void TestList2() {
	DLNode* plist = ListInit();
	//初始化后进行头插
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);

	ListPrint(plist);

	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);

	ListPrint(plist);
}

//查找修改,pos前插入测试
void TestList3() {
	DLNode* plist = ListInit();
	//初始化后进行尾插
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);

	ListPrint(plist);
	DLNode* pos = ListFind(plist, 2);
	if (pos != NULL) {
		pos->data = 30;
	}
	ListPrint(plist);
	ListInsert(pos, 666);
	ListPrint(plist);
	//pos位置删除
	ListErase(pos);
	ListPrint(plist);

}


int main() {
	TestList1();
	//TestList2();
	//TestList3();
	return 0;
}