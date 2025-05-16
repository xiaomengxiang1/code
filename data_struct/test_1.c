// -----------------------时间复杂度---------------------
// 2.2 大 O 的渐进表示法
// 大 O 符号（Big O notation）：是用于描述函数渐进行为的数学符号。
// 推导大 O 阶方法：
// 1、用常数 1 取代运行时间中的所有加法常数。
// 2、在修改后的运行次数函数中，只保留最高阶项。(n^2 和 n 保留n^2)
// 3、如果最高阶项存在且不是 1(2n 3n 4n 0.5n)，则去除与这个项目相乘的常数，得到的结果就是大O 阶(n)。

// 计算Func4的时间复杂度？  复杂度为O(1)
// void Func4(int N)
// {
//     int count = 0;
//     for (int k = 0; k < 100; ++ k)
//     {
//         ++count;
//     }
//     printf("%d\n", count);
// }

// 当一个算法随着输入不同，时间复杂度不同，时间复杂度做悲观预期，看最坏的情况

// 二分查找
// 一个数组    元素个数N
// 查找一次得到N/2
// 最坏的情况 N/2/2/2/2... = 1 (找到了)    (假设查找了X次)
// N / (2^X) = 1
// 由此得到时间复杂度为 X = log N (2为底)

// 递归算法：递归次数*每次递归调用的次数


// 计算斐波那契递归Fib的时间复杂度？    复杂度O(2^N)
// long long Fib(size_t N)
// {
//     if(N < 3)
//         return 1;

//     return Fib(N-1) + Fib(N-2);
// }


// -----------------------空间复杂度---------------------
// 空间复杂度也是一个数学函数表达式，是对一个算法在运行过程中临时占用存储空间大小的量度。
// 空间复杂度不是程序占用了多少 bytes 的空间，因为这个也没太大意义，所以空间复杂度算的是变量的个数。
// 空间复杂度计算规则基本跟时间复杂度类似，也使用大 O 渐进表示法。
// 注意：函数运行时所需要的栈空间 (存储参数、局部变量、一些寄存器信息等) 在编译期间已经确定好了，
// 因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定。(变量开辟内存的个数)

// 空间可以重复利用，时间是累计的



// 数组 nums 包含从 0 到 n 的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。
// 你有办法在 O (n) 时间内完成吗？

// 示例 1:
// 输入：[3,0,1]
// 输出：2

// 示例 2:
// 输入：[9,6,4,2,3,5,7,0,1]
// 输出：8

// 思路1    qsort
// #include <stdio.h>
// #include <stdlib.h>
// int cmp(const void* e1, const void* e2) {
//     return (*(int*)e1 - *(int*)e2);
// }
// int main() {
//     int arr[] = {9,6,4,2,3,5,7,0,1};
//     //排序
//     qsort(arr, 9, sizeof(int), cmp);

//     int i = 0;
//     //遍历判断是否为前后差1
//     for (i = 0; i < 9 - 1; i++) {
//         if (arr[i] + 1 != arr[i+1]) {
//             printf("找到了：%d\n", i + 1);
//         }
//     }

//     for (i = 0; i < 9; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 思路2 异或
// int missingNumber(int* nums, int numsSize) {
//     int x = 0;
//     //x和[0,n]异或
//     int i = 0;
//     for(i = 0; i < numsSize + 1; i++) {
//         x ^= i;
//     }
//     //x和nums异或
//     for (i = 0; i < numsSize; i++) {
//         x ^= nums[i];
//     }
//     return x;
// }

// 旋转数组
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

// 进阶：
// 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
// 你可以使用空间复杂度为 O (1) 的 原地 算法解决这个问题吗？

// 方法1 时间复杂度O（n*k）
// 空间复杂度O（1）
// #include <stdio.h>
// void reverse(int *arr, int sz, int n) {
//     n %= sz;
//     //每次移动1步,移动n次
//     int i = 0;
//     for (i = 0; i < n; i++) {
//         //移动1步
//         int tem = arr[sz - 1];
//         int j = 0;
//         for (j = sz - 1; j > 0; j--) {
//             arr[j] = arr[j-1];
//         }
//         arr[0] = tem;
//     }
// }

// int main() {
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = 0;
//     scanf("%d", &n);

//     int sz = sizeof(arr) / sizeof(arr[0]); 
//     reverse(arr, sz, n);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 方法2 空间换时间
// 额外开辟空间，将后k个放到前面，前面n - k个放后面
// O(sz)
// #include <stdio.h>
// #include <string.h>
// void reverse(int *arr, int sz, int n) {
//     if (n != 0) {
//         int arr_tem[sz];
//         n %= sz;
//         int i = 0;
//         int j = 0;
//         //后面n个放到另一个数组
//         for (i = sz-n; i < sz; i++) {
//             arr_tem[j++] = arr[i];
//         }
//         //前面几个
//         for (i = 0; i < sz - n; i++) {
//             arr_tem[j++] = arr[i];
//         }
//         //替换原数组内容
//         for (i = 0; i < sz; i++) {
//             arr[i] = arr_tem[i];
//         }
//     }
// }
// int main() {
//     int arr[] = {1,2,3,4,5,6,7};
//     int n = 0;
//     scanf("%d", &n);

//     int sz = sizeof(arr) / sizeof(arr[0]); 
//     reverse(arr, sz, n);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }


// 方法3 3次翻转
// 假设输入3
// 1 2 3 4 5 6 7
//翻转后面3个
// 1 2 3 4 7 6 5
//翻转前面几个
// 4 3 2 1 7 6 5
//整体翻转
// 5 6 7 1 2 3 4

// 时间复杂度：O(n)（每个元素最多被交换一次）
// 空间复杂度：O(1)（原地操作，无额外数组）
// void Reverse(int* nums, int left, int right) {
//     while (left < right) {
//         int tem = nums[left];
//         nums[left] = nums[right];
//         nums[right] = tem;

//         left++;
//         right--;
//     }
// }

// void rotate(int* nums, int num_size, int k) {
//     if (k != 0) {
//         k %= num_size;
//         Reverse(nums, num_size - k, num_size - 1);
//         Reverse(nums, 0, num_size - k - 1);
//         Reverse(nums, 0, num_size - 1);
//     }
// }


// -----------------------顺序表和链表---------------------
// 顺序表
// 2.1 概念及结构
// 顺序表就是数组，但是在数组的基础上，它还要求数据是连续存储的，不能跳跃间隔
// 顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，
// 一般情况下采用数组存储。在数组上完成数据的增删查改。

// oj的分类和原理
// 1.接口型
// 2.io型

// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O (1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    while (numsSize > 0) {
        if (nums[i] == val) {
            nums[i] = nums[numsSize - 1];  // 用最后一个元素替换
            numsSize--;                    // 缩短数组
        } else {
            i++;
        }
    }
    return numsSize;
}

