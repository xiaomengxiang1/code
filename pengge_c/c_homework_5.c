// 描述
// KiKi 学习了循环，BoBo 老师给他出了一系列打印图案的练习，该任务是打印用 “*” 组成的箭形图案。
// 输入描述：
// 本题多组输入，每行一个整数（2~20）。
// 输出描述：
// 针对每行输入，输出用 “*” 组成的箭形。
// *
// **
// ***
// **
// *
// #include <stdio.h>
// int main() {
//     int n = 0;
//     while (scanf("%d", &n) == 1) {
//         //上
//         int i = 0;
//         for (i = 0; i < n + 1; i++) {
//             //空格
//             int j = 0;
//             for (j = 0; j < (n - i); j++) {
//                 printf("  ");
//             }
//             //"*"
//             for (j = 0; j < i + 1; j++) {
//                 printf("*");
//             }
//             printf("\n");
//         }
//         //下
//         for (i = 0; i < n; i++) {
//             //空格
//             int j = 0;
//             for (j = 0; j < i + 1; j++) {
//                 printf("  ");
//             }
//             //"*"
//             for (j = 0; j < n - i; j++) {
//                 printf("*");
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

// 3
//       *
//     **
//   ***
// ****
//   ***
//     **
//       *


// 描述
// 公务员面试现场打分。有 7 位考官，从键盘输入若干组成绩，每组 7 个分数（百分制），
// 去掉一个最高分和一个最低分，输出每组的平均成绩。（注：本题有多组输入）
// 输入描述：
// 每一行，输入 7 个整数（0~100），代表 7 个成绩，用空格分隔。
// 输出描述：
// 每一行，输出去掉最高分和最低分的平均成绩，小数点后保留 2 位，每行输出后换行。
// #include <stdio.h>
// int main() {
//     int arr[7] = {0};
//     int i = 0;
//     int max = 0;
//     int min = 100;
//     int sum = 0;
//     for (i = 0; i < 7; i++) {
//         scanf("%d", &arr[i]);
//         if (arr[i] > max) {
//             max = arr[i];
//         }
//         if (arr[i] < min) {
//             min = arr[i];
//         }
//         sum += arr[i];
//     }
//     double score = (sum - max - min)/5.0;
//     printf("%.2lf", score);

//     return 0;
// }


// 栈区：放临时变量和局部变量，堆区：：放动态内存 ， 静态区放静态变量  文字常量区就放机器指令

// 一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
// 编写一个函数找出这两个只出现一次的数字。
// 1.法1
// #include <stdio.h>
// void single_num(int arr[], int sz) {
//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         int j = 0;
//         int count = 0;
//         for (j = 0; j < sz; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//             }
//         }
//         if (count == 1) {
//             printf("%d ", arr[i]);
//         }
//     }
// }
// int main() {    
//     int arr[] = {1,2,3,4,5,6,1,2,3,4};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     single_num(arr, sz);
//     return 0;
// }

// 法2
// #include <stdio.h>
// void find_single_num(int arr[], int sz, int* num_1, int* num_2) {
//     int i = 0;
//     int ret = 0;
//     // 1.异或
//     for (i = 0; i < sz; i++) {
//         ret ^= arr[i];
//     }
//     // 2.计算二进制的最右边第几位是1
//     // 和1进行与或运算(都是1才是1) 0000 0001
//     int pos = 0;
//     for (pos = 0; pos < 32; pos++) {
//         if ((ret >> pos) & 1 == 1) {
//             break;
//         }
//     }

//     //遍历分组
//     for (i = 0; i < sz; i++) {
//         if ((arr[i] >> pos) & 1 == 1) {
//             //分组后，同一个数组中，所有的数异或,数字相同则消去,只留下最后不一样的那一个
//             *num_1 ^= arr[i];
//         }
//         else {
//             *num_2 ^= arr[i];
//         }
//     }
// }
// int main() {    
//     int arr[] = {1,2,3,4,5,6,1,2,3,4};
//     // 5^6
//     // 101 - 5 b 1 1 3 3
//     // 110 - 6 a 2 2 4 4
//     // 两个数字异或
//     // 011 
//     // 分组
//     // 1.所有数字异或
//     // 2.找到异或的结果中哪一位为1 - n第n位
//     // 3.以第n位为1，分一组，第n位为0分一组

//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int num_1 = 0;
//     int num_2 = 0;
//     find_single_num(arr, sz, &num_1, &num_2);
//     printf("%d %d\n", num_1, num_2);
//     return 0;
// }


// atoi函数的实现
// 字符串转换为整型
// atoi
// int atoi (const char * str);

//自己的方法
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// int my_atoi(const char* str) {
//     int count = 0;
//     //定位'\0'的位置
//     while (*(str + count) != '\0') {
//         count++;
//     }
//     int i = 0;
//     int sum = 0;
//     int j = count;
//     //根据ascii表 数字与其ascii值相差48
//     for (i = 0; i < count; i++) {
//         sum = sum + (*(str + i) - 48) * pow(10, --j);
//     }
//     return sum;
// }
// int main() {
//     char arr[20] = "123456";
//     int ret = my_atoi(arr);
//     printf("%d\n", ret);
//     return 0;
// }

//法2(完整)
// #include <stdio.h>
// #include <assert.h>
// #include <ctype.h>
// #include <limits.h>
// //1.空指针
// //2.空字符串
// //3.空格
// //4.+-
// //5.越界
// //6.非数字字符
// enum Status {
//     VALID,//0
//     INVALID//1
// }sta = INVALID;//默认非法

// int my_atoi(const char * str) {
//     assert(str);
//     int flag = 1;
//     if (*str == '\0') {
//         return 0;//非法
//     }
//     //跳过空白字符
//     while (isspace(*str)) {
//         str++;
//     }
//     //
//     if (*str == '+') {
//         flag = 1;
//         str++;
//     }
//     else if (*str == '-') {
//         flag = -1;
//         str++;
//     }
//     long long ret = 0;
//     while (*str) {
//         if (isdigit(*str)) {
//             ret = ret * 10 + flag * (*str - '0');
//             if (ret > INT_MAX || ret < INT_MIN) {
//                 return 0;
//             }
//         }
//         else {
//             return ret;
//         }
//         str++;
//     }
//     if (*str == '\0') {
//         sta = VALID;
//     } 
//     return (int)ret;

// }
// int main() {
//     char arr[20] = "-123abc456";
//     int ret = my_atoi(arr);
//     if (sta == INVALID) {
//         printf("非法返回:%d\n", ret);
//     }
//     else if (sta == VALID) {
//         printf("合法转换:%d\n", ret);
//     }
//     return 0;
// }

// offsetof宏
// 为什么不能用 int？
// 类型不匹配：
// 指针地址是无符号的，而 int 是有符号的，强制类型转换可能会导致截断或符号错误。
// 可能发生溢出或精度丢失：
// 在 64 位平台上，sizeof(void*) 是 8，而 int 仍是 4。将 64 位地址强转为 32 位 int，会丢掉高位，结果就错了。
// 标准库函数也用 size_t 表示偏移和大小：
// 如 memcpy、sizeof、strlen 返回或接受的参数也都是 size_t。
// #define OFFSETOF(type, member) (size_t)&(((type*)0)->member)
// #include <stdio.h>
// struct S {
//     char c1;
//     int i;
//     char c2;
// };
// int main() {
//     struct S s = {0};
//     printf("%d\n", OFFSETOF(struct S, c2));
//     return 0;
// }


// 写一个宏可以将一个整数的二进制位的奇数位和偶数位交换