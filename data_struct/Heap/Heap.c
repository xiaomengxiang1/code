#include "Heap.h"

//交换数据
void Swap(HpDataType* e1, HpDataType* e2) {
	HpDataType tem = *e1;
	*e1 = *e2;
	*e2 = tem;
}


//向上调整算法,时间复杂度logN
//若子数据小于父亲则上浮
AdjustUp(HpDataType* a, int n, int child) {
	int parent = (child - 1) / 2;
	//while (parent >= 0) 错的
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}


//向下调整算法, 这里是将小的向下调整
//使用的前提是,左右子树都是小堆
void AdjustDown(HpDataType* a, int n, int root) {
	//定义根节点和孩子节点
	int parent = root;
	int child = parent * 2 + 1;	//左孩子

	while (child < n) {
		//找到较小的孩子,并且保证最后一个节点不会越界
		if (child + 1 < n && a[child + 1] < a[child]) {
			++child;
		}
		//如果孩子小于父节点，则上浮(交换位置),如果孩子大于父节点则说明结构调整完毕
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//若要改成大堆,改变一下这个判断逻辑即可
//if (child + 1 < n && a[child + 1] > a[child])
//if (a[child] > a[parent])

//int n	给的数组元素个数
void HeapInit(Heap* php, HpDataType* a, int n) {
	assert(php);
	php->a = (HpDataType*)malloc(sizeof(HpDataType) * n);
	//复制给的数组数据到开辟的空间
	//void* memcpy(void* destination, const void* source, size_t num);
	memcpy(php->a, a, sizeof(HpDataType) * n);
	php->size = n;
	php->capacity = n;

	//构建堆,时间复杂度是O(N)
	//从完全二叉树的最后一个节点的父节点开始进行向下调整，减减遍历每一个父节点
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(php->a, php->size, i);
	}
}

void HeapDestory(Heap* php) {
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void HeapPush(Heap* php, HpDataType x) {
	assert(php);
	//扩容
	if (php->size == php->capacity) {
		int new_capacity = php->capacity * 2;
		HpDataType* new_memory = (HpDataType*)realloc(php->a, sizeof(HpDataType) * new_capacity);
		if (new_memory == NULL) {
			printf("fail realloc\n");
			exit(-1);
		}
		php->a = new_memory;
		php->capacity = new_capacity;
	}
	//插入数据到末尾
	php->a[php->size] = x;
	php->size++;
	//向上调整算法
	AdjustUp(php->a, php->size, php->size - 1);
}

//删除堆顶的数据
void HeapPop(Heap* php) {
	assert(php);
	assert(php->size == 0);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

//堆顶
HpDataType HeapTOP(Heap* php) {
	assert(php);
	assert(php->size == 0);

	return php->a[0];
}

void HeapPrint(Heap* php) {
	int level = 0;          // 当前是第几层（从0开始）
	int count = 0;          // 当前层已打印数量
	int elements_in_level = 1;  // 当前层应有多少个元素
	
	int i = 0;
	for (i = 0; i < php->size; ++i) {

		printf("%d ", php->a[i]);
		count++;

		// 如果当前层满了，就换行
		if (count == elements_in_level) {
			printf("\n");
			++level;
			count = 0;
			elements_in_level = 1 << level; //2^level
		}
	}
	// 最后一层不满也要换行
	if (count != 0) {
		printf("\n");
	}
}