#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void print_arr(int* a, int n);

//排序的接口的实现

//插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void AdjustDown(int* a, int n, int root);
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int* a, int left, int right);
//快排非递归
void QuickSortNonR(int* a, int left, int right);

//归并排序
void MergeSort(int* a, int n);
//归并排序非递归
void MergeSortNonR(int* a, int n);

//排序大量文件数据(假如1000亿)
void MergeSortFile(const char* file);

//计数排序
void CountSort(int* a, int n);
