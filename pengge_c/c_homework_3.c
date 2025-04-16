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
// 习题1
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
// #define ROW 3
// #define COL 4
// #include <stdio.h>
// int main() {
//     int arr[ROW][COL] = {{1,1,1,1},
//                          {1,1,1,1},
//                          {1,1,1,1}};
//     //遍历行
//     int i = 0; 
//     int count = 0;
//     for (i = 0; i < ROW; i++) {

//          //找每一行最大的值
//         int row_max = arr[i][0];
//         int j = 0;
//         for (j = 0; j < COL; j++) {
//             if (arr[i][j] > row_max) {
//                 row_max = arr[i][j];
//             }
//         }

//         //遍历每一行为最大值的元素
//         for (j = 0; j < COL; j++) {
//             if (arr[i][j] == row_max) {

//                 //判断是否为每一个列的最小值
//                 int col_min = row_max;
//                 int k = 0;
//                 //假设为最小值
//                 int flag = 1;
//                 for (k = 0; k < ROW; k++) {
//                     if (col_min > arr[k][j]) {
//                         flag = 0;
//                         break;
//                     }
//                 }
//                 if (flag) {
//                     printf("鞍点:arr[%d][%d] = %d\n", i, j, row_max);
//                     count++;
//                 }
//             }
//         }
//     }
//     if (count) {
//         printf("鞍点有%d个\n", count);
//     }
//     else {
//         printf("没有鞍点\n");
//     }
// // 1 2 3 4
// // 2 3 4 5
// // 3 4 5 6
//     return 0;
// }

// 习题11
// #include <stdio.h>
// int main() {
//     int row = 0;
//     int col = 0;
//     scanf("%d %d", &row, &col);

//     int i = 0;
//     for (i = 0; i < row; i++) {
//         //空格
//         int j = 0;
//         for (j = 0; j < i; j++) {
//             printf("   ");
//         }

//         //星号
//         for (j = 0; j < col; j++) {
//             printf("*  ");
//         }
//         printf("\n");
//     } 
//     return 0;
// }


// 习题13
// #include <stdio.h>
// void my_strcat(char* p1, char* p2) {
//     while (*p1 != '\0') {
//         p1++;
//     }

//     while (*p2 != '\0') {
//         *p1 = *p2;
//         p1++;
//         p2++; 
//     }

// }
// int main() {
//     char str1[100] = "hello ";
//     char str2[10] = "world";

//     my_strcat(str1, str2);

//     printf("%s\n", str1);
//     return 0;
// }


// 习题15
// #include <stdio.h>
// void my_strcpy(char* p1, char* p2) {
//     while (*p1 != '\0') {
//         p1++;
//     }
//     while (*p2 != '\0') {
//         *p1 = *p2;
//         p1++;
//         p2++; 
//     }

//     *p1 = '\0';
// }

// int main() {
//     char str1[20] = "hello ";
//     char str2[10] = {'a', 'b', 'c', '\0', 'x', 'y', 'z'};

//     my_strcpy(str1, str2);

//     printf("%s\n", str1);
//     return 0;
// }


// 教材215,  2,5,7,11,17
// 习题2
// #include <stdio.h>
// #include <math.h>
// void func_1(int a, int b, int c, int deta) {
//     double x_1 = (-b + sqrt(deta)) / (2 * a);
//     double x_2 = (-b - sqrt(deta)) / (2 * a);
//     printf("方程有两个不同的实数根：x1 = %lf, x2 = %lf\n", x_1, x_2);
// }

// void func_2(int a, int b, int c, int deta) {
//     double x = -b / (2 * a);
//     printf("方程有两个相等的实数根：x1 = x2 = %lf\n", x);
// }
// void func_3(int a, int b, int c, int deta) {
//     double real = -b / (2 * a);
//     double xu = (sqrt(-deta)) / (2 * a);
//     printf("方程有两个复数根\n");
//     printf("x1 = %lf + %lfi\n", real, xu);
//     printf("x1 = %lf - %lfi\n", real, xu);
// }

// int main() {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     scanf("%d %d %d", &a, &b, &c);

//     int deta = pow(b, 2) - (4 * a * c);
//     if (deta > 0) {
//         func_1(a,b,c,deta);
//     }
//     else if (deta == 0) {
//         func_2(a,b,c,deta);
//     }
//     else {
//         func_3(a,b,c,deta);
//     }
//     return 0;
// }
// 1 2 5

// 习题5
// #include <stdio.h>
// void reverse_string(char* left) {
//     char* right = left;
//     //右边位置
//     while (*right != '\0') {
//         right++;
//     }
//     right--;
//     while (left < right) {
//         char temp = *left;
//         *left = *right;
//         *right = temp;

//         left++;
//         right--;
//     }
// }
// int main() {
//     char arr[20] = {0};
//     scanf("%s", arr);

//     printf("%s\n", arr);
//     reverse_string(arr);
//     printf("%s\n", arr);
//     return 0;
// }

// 习题7
// #include <stdio.h>
// void copy(char* arr1, char* arr2) {
//     while (*arr1 != '\0') {
//         //元音字母复制,目标地址数组+1
//         if (*arr1 == 'a' || *arr1 == 'e' || *arr1 == 'i' || *arr1 == 'o' || *arr1 == 'u') {
//             *arr2 = *arr1;
//             arr2++;
//         }
//         arr1++;
//     }
// }
// int main() {
//     char arr1[10] = "hello";
//     char arr2[10] = {0};

//     copy(arr1, arr2);
//     printf("%s\n", arr2);
//     return 0;
// }

// 习题11
// #include <stdio.h>
// void bubble_sort(int arr[], int sz) {
//     //总趟数
//     int i = 0;
//     for (i = 0; i < sz - 1; i++) {
//         int flag = 1;//假设已经有序
//         //每一趟
//         int j = 0;
//         for (j = 0; j < sz -1 -i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;

//                 flag = 0;//有交换一次说明不是有序
//             }
//         }
//         if (flag == 1) {
//             break;
//         }
//     }
// }
// int main() {

//     int arr[] = {9,8,7,6,5,4,3,2,1,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     for (i = 0 ;i < sz; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     bubble_sort(arr, sz);

//     for (i = 0 ;i < sz; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// 习题17
// #include <stdio.h>
// void func(int n, char arr[], int* pi) {
//     if (n > 9) {
//         func(n / 10, arr, pi);
//     }

//     arr[(*pi)++] = '0' + (n % 10);
// }

// int main() {
//     int n = 0;
//     scanf("%d", &n);

//     char arr[10] = {0};
//     int i = 0;
//     func(n, arr, &i);
//     printf("%s", arr);
//     return 0;
// }
