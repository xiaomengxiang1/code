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
// #include <stdio.h>
// int main() {
//     int n = 0;
//     int m = 0;
//     scanf("%d %d", &n, &m);
//     //输入m和n
//     int arr_n[n];//c99 变长数组
//     int arr_m[m];
//     //输入数组n
//     int i = 0;
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr_n[i]);
//     }
//     //输入数组m
//     for (i = 0; i < m; i++) {
//         scanf("%d", &arr_m[i]);
//     }
    
//     int start_n = 0;
//     int start_m = 0;

//     while ((start_n < n) && (start_m < m)) {
//         //打印小的 小的加一
//         if (arr_n[start_n] >= arr_m[start_m]) {
//             printf("%d ", arr_m[start_m]);
//             start_m++;
//         }
//         else {
//             printf("%d ", arr_n[start_n]);
//             start_n++;
//         }
//     }
//     //有剩下的数字没打印完

//     while (start_m < m) {
//         printf("%d ", arr_m[start_m]);
//         start_m++;
//     }

//     while (start_n < n) {
//         printf("%d ", arr_n[start_n]);
//         start_n++;
//     }
    
//     return 0;
// }



// 教材p82  习题6,7

// #include <stdio.h>
// int main() {
//     char c1 = 'C'; 
//     char c2 = 'h'; 
//     char c3 = 'i'; 
//     char c4 = 'n'; 
//     char c5 = 'a';

//     putchar(c1 + 4);
//     putchar(c2 + 4);
//     putchar(c3 + 4);
//     putchar(c4 + 4);
//     putchar(c5 + 4);

//     printf(" %c ", c1 + 4);
//     printf("%c ", c2 + 4);
//     printf("%c ", c3 + 4);
//     printf("%c ", c4 + 4);
//     printf("%c ", c5 + 4);

//     return 0;
// }

// #define PI 3.14
// #include <stdio.h>
// int main() {
//     double r = 0;
//     double h = 0;

//     scanf("%lf %lf", &r, &h);
//     printf("周长:%.2lf\n", 2 * PI * r);
//     printf("圆的面积:%.2lf\n", PI * r * r);
//     printf("圆球的表面积:%.2lf\n", 4 * PI * r * r);
//     printf("圆球的体积:%.2lf\n", (float)4 / 3 * PI * r * r * r);
//     printf("圆柱的体积:%.2lf\n", (PI * r * r) * h);

//     return 0;
// }


// 教材p107  习题4,8,9,11,12

//习题4
// #include <stdio.h>
// int max(int a, int b, int c) {
//     if (a >= b && a >= c) {
//         return a;
//     }
//     else if (b >= a && b >= c) {
//         return b;
//     }
//     else {
//         return c;
//     }
// }
// int main() {
//     int a = 0;
//     int b = 0;
//     int c = 0;

//     scanf("%d %d %d", &a, &b, &c);
//     int ret = max(a,b,c);
//     printf("%d\n", ret);
//     return 0;
// }


//习题8
// #include <stdio.h>
// int main() {
//     int score = 0;
//     scanf("%d", &score);

//     if (score >= 90) {
//         printf("等级为A\n");
//     }
//     else if (score >= 80) {
//         printf("等级为B\n");
//     }
//     else if (score >= 70) {
//         printf("等级为C\n");
//     }
//     else if (score >= 60) {
//         printf("等级为D\n");
//     }
//     else {
//         printf("等级为E\n");
//     }

//     return 0;
// }


//习题9
// #include <stdio.h>
// #include <string.h>
// int main() {
//     char arr[6] = {0};
//     scanf("%s", arr);

//     int ret = strlen(arr);
//     printf("它是%d位数\n", ret);

//     //每一位
//     int i = 0;
//     while (arr[i] != '\0') {
//         printf("%c ", arr[i]);
//         i++;
//     }

//     printf("\n");
//     // 倒序输出
//     for (i = ret -1; i >= 0; i--) {
//         printf("%c ", arr[i]);
//     }
//     return 0;
// }


//习题11
// #include <stdio.h>
// #include <stdlib.h>
// int cmp_int(const void* e1, const void* e2) {
//     //升序
//     return (*(int*)e1 - *(int*)e2); 
// }
// int main() {
//     int arr[4] = {0};
//     int i = 0;
//     for (i = 0; i < 4; i++) {
//         scanf("%d", &arr[i]);
//     }

//     qsort(arr, 4, sizeof(arr[0]), cmp_int);

//     for (i = 0; i < 4; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }


//习题12
// #include <stdio.h>
// #include <math.h>
// int dis(double x, double y) {
//     if ((pow(x - 2, 2) + pow(y - 2, 2) <= 1) ||
//         (pow(x + 2, 2) + pow(y - 2, 2) <= 1) ||
//         (pow(x - 2, 2) + pow(y + 2, 2) <= 1) ||
//         (pow(x + 2, 2) + pow(y + 2, 2) <= 1)) {
//         return 10;
//     }
//     else {
//         return 0;
//     }
// }
// int main() {
//     double x = 0;
//     double y = 0;
//     scanf("%lf %lf", &x, &y);

//     printf("该点的建筑高度%d", dis(x, y));
//     return 0;
// }

// 教材p137 5,6,8,13,16
// 习题5
// #include <stdio.h>
// int main() {
//     int n = 0;
//     int a = 0;
//     scanf("%d %d", &a, &n);

//     int Sn = 0;
//     int An = 0;
//     int i = 0;
//     for (i = 0; i < n; i++) {
//         An = An * 10 + a;
//         Sn += An;
//     }
//     printf("Sn = %d\n", Sn);

//     return 0;
// }

// // 习题6
// #include <stdio.h>
// int main() {
//     int n = 0;
//     scanf("%d", &n);

//     int i = 0;
//     int Sn = 0;
//     int An = 1;
//     for (i = 1; i <= n; i++) {
//         An = An * i;
//         Sn = Sn + An;
//     }
//     printf("Sn = %d\n", Sn);
//     return 0;
// }

// 习题8
// #include <stdio.h>
// #include <math.h>
// int main() {
//     int i = 0;
//     for (i = 100; i < 1000; i++) {
//         if ((pow(i % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 100, 3)) == i) {
//             printf("%d ", i);
//         }        
//     }
//     return 0;
// }

// abs() 是用来处理 int 的，返回 int，你这里传的是 double 类型的差值（浮点数），应该用 fabs()
// 习题13
// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h>
// int main() {
//     int a = 0;
//     scanf("%d", &a);

//     double x1 = a;
//     double x2 = 0;
//     while (1) {
//         x2 = 0.5 * (x1 + a / x1);
//         if (fabs(x1 - x2) <= 1e-5) {
//             break;
//         }
//         x1 = x2;     
//     }
//     printf("x2 = %lf ", x2);
//     printf("x1 = %lf ", x1);
//     return 0;
// }

// 习题16
// #include <stdio.h>
// int main() {
//     //上行数
//     int n = 0;
//     scanf("%d", &n);
//     int i = 0;

//     //上
//     for (i = 0; i < n; i++) {
//         //空格
//         int j = 0;
//         for (j = 0; j < n - i - 1; j++) {
//             printf(" ");
//         }

//         //星号
//         j = 0;
//         for (j = 0; j < 2 * i + 1; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//     //下
//     for (i = 0; i < n - 1; i++) {
//         //空格
//         int j = 0;
//         for (j = 0; j <= i; j++) {
//             printf(" ");
//         }

//         //星号
//         j = 0;
//         for (j = 0; j < 2 * (n - 1 - i) - 1; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }
//     printf("\n");
// }

// 教材p165 1,4,8,11,13,15
// #include <stdio.h>
// #include <math.h>

// int is_prime(int x) {
//     int j = 0;
//     //是返回1
//     //不是返回0
//     for (j = 2; j <= sqrt(x); j++) {
//         if (x % j == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main() {
//     int i = 0;
//     for (i = 2; i <= 100; i++) {
//         if (is_prime(i)) {
//             printf("%d ", i);
//         }    
//     }
//     return 0;
// }

// 习题4
// #include <stdio.h>
// int main() {
//     int arr[10] = {1,2,3,4,5};
//     int a = 0;
//     scanf("%d", &a);

//     int count = 0;
//     while (a >= arr[count]) {
//         count++;
//     }

//     int i = 0;
//     for (i = 9; i >= count; i--) {
//         arr[i] = arr[i-1];
//     }
//     arr[count] = a;

//     i = 0;
//     for (i = 0; i < 10; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }


// 习题8
#include <stdio.h>
int main() {
    int arr[3][4] = {1,2,3,4,2,3,4,5,3,4,5,6};
    int i = 0;
    for (i = 0; i < 3; i++) {
        int j = 0;
        for (j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
