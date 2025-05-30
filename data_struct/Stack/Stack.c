#include "Stack.h"

//初始化
void StackInit(ST* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	//初始化时，top 给的是 0，意味着 top 指向栈顶数据的下一个
	//初始化时，top 给的是 - 1，意味着 top 指向栈顶数据
	ps->capacity = 0;
}

//销毁栈
void StackDestory(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;

	ps->top = 0;
	ps->capacity = 0;
}

//压栈
void StackPush(ST* ps, STDataType x) {
	assert(ps);
	//开辟空间
	if (ps->top == ps->capacity) {
		int new_capacity = ps->capacity == 0 ? 4 : (ps->capacity) * 2;
		//扩容的是数组的内存，不要写错了
		STDataType* new_memory = (STDataType*)realloc(ps->a, new_capacity * sizeof(STDataType));
		if (new_memory == NULL) {
			printf("realloc fail");
			exit(-1);
		}
		ps->a = new_memory;
		ps->capacity = new_capacity;
	}
	//入栈
	ps->a[ps->top] = x;
	ps->top++;
}


//出栈
void StackPop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--; //让该空间失效就好了，其他的不用管了
}

//取出栈顶元素
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

//栈的大小
int StackSize(ST* ps) {
	assert(ps);

	return ps->top;
}

//栈是否为空
bool StackEmpty(ST* ps) {
	assert(ps);
	//if (ps->top > 0) {
	//	return false;
	//}
	//return true; 

	return ps->top == 0;	
}