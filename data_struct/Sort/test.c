#include "Sort.h"

void test_insert_sort() {
	int a[] = {3,4,6,5,2,7,8,0,9,1};
	int n = sizeof(a) / sizeof(a[0]);
	InsertSort(a, n);
	print_arr(a, n);
}

void test_shell_sort() {
	int a[] = { 3,4,6,5,2,7,8,0,9,1 };
	int n = sizeof(a) / sizeof(a[0]);
	ShellSort(a, n);
	print_arr(a, n);
}

void test_select_sort() {
	int a[] = { 3,4,6,5,2,7,8,0,9,1 };
	int n = sizeof(a) / sizeof(a[0]);
	SelectSort(a, n);
	print_arr(a, n);
}

void test_heap_sort() {
	int a[] = { 3,4,6,5,2,7,8,0,9,1 };
	int n = sizeof(a) / sizeof(a[0]);
	HeapSort(a, n);
	print_arr(a, n);
}

void test_bubble_sort() {
	int a[] = { 3,4,6,5,2,7,8,0,9,1,23,3,5,6,};
	int n = sizeof(a) / sizeof(a[0]);
	BubbleSort(a, n);
	print_arr(a, n);
}

void test_quick_sort() {
	int a[] = { 3,4,6,5,2,3333,4444,2323,54656,76868,453453,1,1,1,2,2,2,3,3,3,4};
	int n = sizeof(a) / sizeof(a[0]);
	QuickSort(a, 0, n - 1);
	print_arr(a, n);
}

void test_quick_sort_nor() {
	int a[] = { 3,4,6,5,2,3333,4444,2323,54656,76868,453453,1,1,1,2,2,2,3,3,3,4 };
	int n = sizeof(a) / sizeof(a[0]);
	QuickSortNonR(a, 0, n - 1);
	print_arr(a, n);
}

void test_merge_sort() {
	int a[] = { 3,4,6,5,2,3333,4444,2323,54656,76868,453453,1,1,1,2,2,2,3,3,3,4 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSort(a,n);
	print_arr(a, n);
}

void test_merge_sort_nor() {
	int a[] = { 3,4,6,5,2,3333,4444,2323,54656,76868,453453,1,1,1,2,2,2,3,3,3,4 };
	int n = sizeof(a) / sizeof(a[0]);
	MergeSortNonR(a, n);
	print_arr(a, n);
}

void test_count_sort() {
	int a[] = { 3,4,6,5,2,7,8,0,9,1 };
	int n = sizeof(a) / sizeof(a[0]);
	CountSort(a, n);
	print_arr(a, n);
}

int main() {
	//test_insert_sort();
	//test_shell_sort();
	//test_select_sort();
	//test_heap_sort();
	//test_bubble_sort();
	//test_quick_sort();
	//test_quick_sort_nor();
	//test_merge_sort();
	//test_merge_sort_nor();
	//MergeSortFile("paixu.txt");
	test_count_sort();

	return 0;
}

