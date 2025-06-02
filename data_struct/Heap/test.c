#include "Heap.h"

void Test1() {
	Heap hp;
	int a[] = { 5, 3, 8, 4, 6, 2, 7, 1 };
	HeapInit(&hp, a, sizeof(a) / sizeof(a[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 1);
	HeapPrint(&hp);

	HeapDestory(&hp);
}

void HeapSort(int* a, int n) {
	//堆排序时间复杂度为N * logN
	//向下调整算法复杂度为树的高度，为logN

	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	//将堆顶的最小值和数组的最后的值进行交换，将前面n - 1个数据视为新的堆，
	//然后直接利用向下调整算法就可以选出次小的值，并切重复这个动作直到排序完所有数据，
	//此时这边的时间复杂度为O(N)
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

int main() {
	//int a[] = { 5, 3, 8, 4, 6, 2, 7, 1 };
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	Test1();
	return 0;
}