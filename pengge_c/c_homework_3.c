// 输入一个整数数组，实现一个函数，
// 来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
// 所有偶数位于数组的后半部分。

//左右同时找
// #include <stdio.h>
// void sort(int arr[], int sz) {
//     int left = 0;
//     int right = sz - 1;

//     while (left < right) {
//     //从左向右找偶数,停下来
//         while ((left < right) && arr[left] % 2 == 1) {
//             left++;
//         }

//         //从右向左找奇数,停下来
//         while ((left < right) && arr[right] % 2 == 0) {
//             right--;
//         }
//         //防止奇数数组个数
//         if (left < right) {
//             int temp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = temp;
//             left++;
//             right--;    
//         }
//     }

// }

//效率较低的方法
// void sort(int arr[], int sz) {
//     int i = 0;
//     int j = 0;
//     int arr_copy[sz];
//     //奇数
//     for (i = 0; i < sz; i++) {
//         if (arr[i] % 2 == 1) {
//             arr_copy[j++] = arr[i];
//         }
//     }
//     //偶数
//     for (i = 0; i < sz; i++) {
//         if (arr[i] % 2 == 0) {
//             arr_copy[j++] = arr[i];
//         }
//     }

//     for (i = 0; i < sz; i++) {
//         arr[i] = arr_copy[i];
//     }
// }

// int main() {
//     int arr[10] = {0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         scanf("%d", &arr[i]);
//     }
//     // 调整
//     sort(arr, sz);

//     //输出
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 描述

// 输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。
// 数据范围：1≤n,m≤1000，序列中的值满足0≤val≤30000
// 输入描述：

// 输入包含三行，
// 第一行包含两个正整数n,m,相空格分隔。n表示第二行第一个升序序列中数字的个
// 数，表示第三行第二个升序序列中数字的个数。
// 第二行包含n个整数，用空格分隔。
// 第三行包含m个整数，用空格分隔。
// 输出描述：

// 输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序
// 序列中的元素重新进行升序序列排列合并。
// 5 6
// 1 3 7 9 22  n
// 2 8 10 17 33 44  m
#include <stdio.h>
int main() {
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    //输入m和n
    int arr_n[n];//c99 变长数组
    int arr_m[m];
    //输入数组n
    int i = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr_n[i]);
    }
    //输入数组m
    for (i = 0; i < m; i++) {
        scanf("%d", &arr_m[i]);
    }
    
    int start_n = 0;
    int start_m = 0;

    while ((start_n < n) && (start_m < m)) {
        //打印小的 小的加一
        if (arr_n[start_n] >= arr_m[start_m]) {
            printf("%d ", arr_m[start_m]);
            start_m++;
        }
        else {
            printf("%d ", arr_n[start_n]);
            start_n++;
        }
    }
    //有剩下的数字没打印完

    while (start_m < m) {
        printf("%d ", arr_m[start_m]);
        start_m++;
    }

    while (start_n < n) {
        printf("%d ", arr_n[start_n]);
        start_n++;
    }
    
    return 0;
}
