#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

//数组实现小堆

typedef int HpDataType;

typedef struct Heap {
	HpDataType* a;
	int size;
	int capacity;
}Heap;

//交换数据
void Swap(HpDataType* e1, HpDataType* e2);
//向下调整算法
void AdjustDown(HpDataType* a, int n, int root);

void HeapInit(Heap* php, HpDataType* a, int n);
void HeapDestory(Heap* php);
void HeapPrint(Heap* php);

void HeapPush(Heap* php, HpDataType x);
//删除堆顶的数据
void HeapPop(Heap* php);
//堆顶
HpDataType HeapTOP(Heap* php);