#include "SeqList.h"

//初始化
void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//销毁
void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//打印顺序表
void SeqListPrint(SL* ps) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//扩容函数
void new_memory(SL* ps) {
	//如果没有空间或者空间不足，那么我们就扩容
	if (ps->size == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//若扩容的指针为空，则realloc相当于malloc
		SLDataType* tem = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tem == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}

		ps->a = tem;
		ps->capacity = newcapacity;
	}
}

//尾部插入
void SeqListPushBack(SL* ps, SLDataType x) {
	new_memory(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//尾部删除
void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		printf("没东西可以删除\n");
		return;
	}
	//ps->a[ps->size - 1] = 0; //这一步可以不用的，只需要让a访问不到后面的内存就好了，数据放那边不用管
	ps->size--;
}

//头部插入
void SeqListPushFront(SL* ps, SLDataType x) {
	new_memory(ps);
	int i = 0;
	int end = ps->size;
	for (i = 0; i < ps->size; i++) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//头部删除
void SeqListPopFront(SL* ps) {
	if (ps->size == 0) {
		printf("没东西可以删除\n");
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size - 1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}


//找数据是否存在，没有返回-1,找到返回下标
int SeqListFind(SL* ps, SLDataType x) {
	if (ps->size == 0) {
		printf("没东西可以找\n");
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			printf("找到该数据,下标%d\n", i);
			return i;
		}
	}
	printf("没找到\n");
	return -1;
}


//指定pos位置插入数据
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	new_memory(ps);
	int end = ps->size;
	while (end > pos) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//删除pos位置的数据 
void SeqListErase(SL* ps, int pos) {
	if (ps->size == 0) {
		printf("没东西可以删除\n");
		return;
	}
	if (pos < 0) {
		printf("请输入正确的下标\n");
		return;
	}
	int begin = pos;
	while (begin < ps->size - 1) {
		ps->a[begin] = ps->a[begin + 1];
		begin++;
	}
	ps->size--;
}