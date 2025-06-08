#include "Sort.h"
#include "Stack.h"

void print_arr(int* a, int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* e1, int* e2) {
	int temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

//插入排序
//类似拿牌
void InsertSort(int* a, int n) {
	assert(a);

	//外层是总排序次数，从第一个数据开始排到下标为n - 2(n个数据排序n - 1次)的数据
	int i = 0;
	for (i = 0; i < n - 1; i++) {
		//单趟排序
		//[0,end]有序，将end + 1插入该区间，(按升序或降序)保持有序
		int end = i;
		int temp = a[end + 1];
		while (end >= 0) {
			if (temp < a[end]) {
				//将数据往后挪
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;
			}
		}
		//将拿到的牌插入该位置
		a[end + 1] = temp;
	}
}


//希尔排序
void ShellSort(int* a, int n) {

	//间距为gap
	int gap = n;
	while (gap > 1) {
		//gap > 1相当于预排序,gap == 1相当于插入排序
		gap = gap / 3 + 1; // + 1保证最后结果一定是1
		int i = 0;
		for (i = 0; i < n - gap; i++) {
			int end = i;
			int temp = a[end + gap];
			//while里一次只排一个数
			while (end >= 0) {
				if (temp < a[end]) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = temp;
		}
		print_arr(a, n);
	}
}


//选择排序
void SelectSort(int* a, int n) {
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end) {
		int max_index = begin;
		int min_index = begin;
		//遍历一次确定最大最小的数的下标，并且分别交换两头的数据
		for (int i = begin + 1; i < end; i++) {
			if (a[i] > a[max_index]) {
				max_index = i;
			}
			if (a[i] < a[min_index]) {
				min_index = i;
			}
		}
		//小的放头
		Swap(&a[begin], &a[min_index]);
		//若max和begin重叠，则min和begin进行互换的时候会将最大值换到min下标上，max需要重新定位
		if (max_index == begin) {
			max_index = min_index;
		}
		//大的放尾巴
		Swap(&a[end - 1], &a[max_index]);


		--end;
		++begin;
	}
}


//堆排序(此处为升序)
//向下调整算法
void AdjustDown(int* a, int n, int root) {
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		//选大的孩子
		if (child + 1 < n && a[child + 1] > a[child]) {
			++child;
		}
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			//更新位置
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}


void HeapSort(int* a, int n) {
	//建堆
	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	//最大的挪到后面，重新进行调整
	int end = n - 1;
	while (end > 0) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);

		--end;
	}
}


//冒泡排序
void BubbleSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int flag = 1; //默认排序好了
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				Swap(&a[j], &a[j + 1]);

				flag = 0;
			}
		}
		if (flag) {
			return;
		}
	}
}

//三竖取中法
int MidIndex(int* a, int begin, int end) {
	int mid = (begin + end) / 2;
	if (a[begin] > a[end]) {
		if (a[mid] < a[end]) {
			return end;
		}
		else if (a[mid] > a[begin]) {
			return begin;
		}
		else {
			return mid;
		}
	}
	else {
		if (a[mid] < a[begin]) {
			return begin;
		}
		else if (a[mid] > a[end]) {
			return end;
		}
		else {
			return mid;
		}
	}
}


//快速排序

//单趟排序(此处升序)
//左右指针法
//[begin, end]为闭区间
//为什么要对边的先走：begin先走，相遇的时候有两种情况，1.是begin停下来，end遇到begin，
//此时begin停下的位置是比key来的大的，2.是begin主动碰到了end，end脚下的是已经互换过的数据，是比begin大的
//此时也保证了相遇的位置是比key来的大

//为什么一定要使相遇的位置比key来的大，因为最后还要将key和（begin，end）重合点交换，保证放在右边的值是比较大的
//假如key那一边先走，又可能使相遇点是比key小的，最后交换数据的时候将小的放到了右边,使数据顺序变乱

int PartSort1(int* a, int begin, int end) {

	int mid = MidIndex(a, begin, end);
	Swap(&a[mid], &a[end]);

	int key_index = end;
	while (begin < end) {
		//begin大的
		while (begin < end && a[begin] <= a[key_index]) {
			++begin;
		}
		//end找小的
		while (begin < end && a[end] >= a[key_index]) {
			--end;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key_index]);

	return begin;
}

//填坑法
int PartSort2(int* a, int begin, int end) {
	//三竖取中，排除最坏
	int mid = MidIndex(a, begin, end);
	Swap(&a[mid], &a[end]);

	//相当于挖了一个坑(不是将值真的挖掉)
	int hole = a[end];
	while (begin < end) {
		//左边找比hole大的来填坑
		while (begin < end && a[begin] <= hole) {
			++begin;
		}
		//填一个坑，begin产生新的坑
		a[end] = a[begin];
		//右边找比hole小的来填坑
		while (begin < end && a[end] >= hole) {
			--end;
		}
		a[begin] = a[end];
	}
	a[begin] = hole;

	return begin;
}


//前后指针法
//相当于放了两个火车头在左边，一个火车头cur遇找比key小的，找到后就++prev再把数据互换
//不断的将小的数据甩到prev火车上，最后走出边界后++prev然后将key和prev的数据互换，这样就分开了两边的数据
int PartSort3(int* a, int begin, int end) {
	//三竖取中，排除最坏
	int mid = MidIndex(a, begin, end);
	Swap(&a[mid], &a[end]);

	int key = a[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur < end) {
		//找小于key的
		if (a[cur] < key) {
			++prev;
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&a[prev], &a[end]);

	return prev;
}


//void QuickSort(int* a, int left, int right) {
//	assert(a);
//	
//	//if (left < right) {
//	//	int div = PartSort(a, left, right);
//	//	QuickSort(a, left, div - 1);
//	//	QuickSort(a, div + 1, right);
//	//}
//	if (left >= right) {
//		return;
//	}
//	int div = PartSort3(a, left, right);
//	QuickSort(a, left, div - 1);
//	QuickSort(a, div + 1, right);
//}

//优化版
void QuickSort(int* a, int left, int right) {
	assert(a);

	if (left >= right) {
		return;
	}
	//确保每层的递归数据大于10，小于10可以采用插入排序，避免栈区内存开辟过多
	if (right - left + 1 > 10) {
		int div = PartSort3(a, left, right);
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else {
		InsertSort(a + left, right - left + 1);
	}
}

//递归改非递归 1、改循环(斐波那契数列求解) 一些简单递归才能改循环 2、栈模拟存储数据非递归
//非递归：1、提高效率（递归建立栈帧还是有消耗的，但是对于现代的计算机，这个优化微乎其微可以忽略不计
//2、递归最大缺陷是，如果栈帧的深度太深，可能会导致栈溢出。因为系统栈空间一般不大在 M 级别
//数据结构栈模拟非递归，数据是存储在堆上的，堆是 G 级别的空间

//不用递归的写法
void QuickSortNonR(int* a, int left, int right) {
	//用栈实现
	ST st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st)) {
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort3(a, begin, end);
		//[begin, div-1] div [div+1, end]

		//右边先入栈，左边先出来，先处理左边的数据，相当于二叉树的遍历
		if (div + 1 < end) {
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (div - 1 > begin ) {
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}
	StackDestory(&st);
}

//归并排序，两段区间排序处理部分
void MergeArr(int* a, int* temp, int begin1, int end1, int begin2, int end2) {
	//归并[left, mid] [mid + 1, right]有序
	int left = begin1;
	int right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			temp[index++] = a[begin1++];
		}
		else {
			temp[index++] = a[begin2++];
		}
	}
	//处理没排序完的数据
	while (begin1 <= end1) {
		temp[index++] = a[begin1++];
	}
	while (begin2 <= end2) {
		temp[index++] = a[begin2++];
	}
	//复制到原数组
	for (int i = left; i <= right; i++) {
		a[i] = temp[i];
	}
}

void Part_MergeSort(int* a, int* temp, int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	//[left, mid] [mid + 1, right] 有序则可以合并，但是现在还是无序,所以一直往下递归，直到一个数组中只剩一个数
	Part_MergeSort(a, temp, left, mid);
	Part_MergeSort(a, temp, mid + 1, right);

	MergeArr(a, temp, left, mid, mid + 1, right);
}

//归并排序
//本质上是将两端有序数组合并在一起，那怎么创造有序数组，和堆排序类似，从后往前将大单位拆成单个数，
//这时就可以视为有序，然后就可以合并，再从下往上合并
void MergeSort(int* a, int n) {
	assert(a);

	int* temp = (int*)malloc(sizeof(int) * n);
	Part_MergeSort(a, temp, 0, n - 1);

	free(temp);
}

//归并排序非递归
void MergeSortNonR(int* a, int n) {
	assert(a);

	int* temp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	//[i, i+gap-1] [i+gap, i+2*gap-1] 按间距gap分隔数组
	while (gap < n) {
		//[i, i+gap-1] [i+gap, i+2*gap-1]
		for (int i = 0; i < n; i += gap * 2) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			//修正边界
			//1.合并的数据为两组，第二组的begin2超出边界,直接跳过就好了
			if (begin2 >= n) {
				break;
			}
			//2.第二组的end2超出边界
			if (end2 >= n) {
				end2 = n - 1;
			}
			MergeArr(a, temp, begin1, end1, begin2, end2);
		}
		print_arr(a, n);
		gap *= 2;
	}


	free(temp);
}


void _MergeFile(char* file1, char* file2, char* mfile) {
	//打开各个文件
	FILE* file1_out = fopen(file1, "r");
	if (file1_out == NULL) {
		printf("file1打开文件失败\n");
		exit(-1);
	}
	FILE* file2_out = fopen(file2, "r");
	if (file2_out == NULL) {
		printf("file2打开文件失败\n");
		exit(-1);
	}
	FILE* mfile_in = fopen(mfile, "w");
	if (mfile_in == NULL) {
		printf("mfile打开文件失败\n");
		exit(-1);
	}
	//设置num1，num2分别储存一个个在文件中读取到的值
	int num1,num2;
	//记录返回值是否为EOF，正常为读取到的元素个数
	int ret1 = fscanf(file1_out, "%d\n", &num1);
	int ret2 = fscanf(file2_out, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF) {
		if (num1 < num2) {
			fprintf(mfile_in, "%d\n", num1);
			ret1 = fscanf(file1_out, "%d\n", &num1);
		}
		else {
			fprintf(mfile_in, "%d\n", num2);
			ret2 = fscanf(file2_out, "%d\n", &num2);
		}
	}
	while (ret1 != EOF) {
		fprintf(mfile_in, "%d\n", num1);
		ret1 = fscanf(file1_out, "%d\n", &num1);
	}
	while (ret2 != EOF) {
		fprintf(mfile_in, "%d\n", num2);
		ret2 = fscanf(file2_out, "%d\n", &num2);
	}

	fclose(file1_out);
	fclose(file2_out);
	fclose(mfile_in);

}

//排序大量文件数据(假如1000亿)
void MergeSortFile(const char* file) {
	FILE* pf_r = fopen(file, "r");
	if (pf_r == NULL) {
		printf("打开文件失败\n");
		exit(-1);
	}

	//分割成小段的数据读取出来，在数组中排序好，然后重新写入到各个文件块
	int n = 10; //10个数据一组
	int a[10];
	int i = 0; // 数组下标
	int num = 0; //存储读取到的值

	int file_index = 1; // 文件编号
	char subfile_name[20]; //文件路径
	while (fscanf(pf_r, "%d\n", &num) != EOF) {
		if (i < n - 1) {
			a[i++] = num;
		}
		//数据到10个后进行排序
		else {
			a[i] = num;
			QuickSort(a, 0, n - 1);
			//拼接文件路径
			sprintf(subfile_name, "%d", file_index++);
			FILE* pf_w = fopen(subfile_name, "w");

			if (pf_w == NULL) {
				printf("写入文件失败\n");
				exit(-1);
			}
			//写入数据
			for (int i = 0; i < n; i++) {
				fprintf(pf_w, "%d\n", a[i]);
			}
			fclose(pf_w);
			i = 0;
		}
	}
	//合并多块文件
	//file1 file2是要进行合成的文件
	//mfile是融合的文件
	char file1[100] = "1";
	char file2[100];
	char mfile[100] = "12";
	for (int i = 2; i <= n; i++) {
		//文件二的文件名
		sprintf(file2, "%d", i);

		//读取两个文件合并出mfile
		_MergeFile(file1, file2, mfile);

		//将file1设置为mfile，同时设置融合文件的文件名
		strcpy(file1, mfile);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	fclose(pf_r);
}


//计数排序
//时间复杂度O(N + range)
//空间复杂度O(range)
//只适用于整型，字符串或者浮点类型的还得用比较排序
void CountSort(int* a, int n) {
	assert(a);
	int max = a[0];
	int min = a[0];
	//找最大和最小
	int i = 0;
	for (i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	//开辟计数用的数组
	int range = max - min + 1;
	int* temp = (int*)malloc(sizeof(int) * range);
	if (temp == NULL) {
		printf("开辟失败\n");
		exit(-1);
	}
	memset(temp, 0, sizeof(int) * range);

	int index = 0;
	//遍历一遍并且计数
	for (i = 0; i < n; i++) {
		index = a[i] - min;
		temp[index]++;
	}
	
	//计数完就可以依次摆放回原来的数组
	int j = 0; //放回原来的数组的下标
	for (i = 0; i < range; i++) {
		//检查该下标对应的值是不是0
		int value = temp[i];

		while (value--) {
			//别忘了下标是相对最前面的一个数的，所以要加上最小值
			a[j++] = i + min;
		}
	}
	free(temp);
}