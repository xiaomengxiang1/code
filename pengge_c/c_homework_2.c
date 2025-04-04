//打印一个数的每一位数
//递归(要求)
// #include <stdio.h>

// void func(int x) {
//     if (x > 9) {
//         func(x / 10);
//     }
//     printf("%d ", x % 10);
// }

// int main() {
//     int x = 0;
//     scanf("%d", &x);
//     func(x);

//     return 0;
// }

//逆序打印字符串(递归)

//非递归的方法
// #include <stdio.h>
// int main() {
//     //a b c d e f \0
//     char arr[] = "abcdef";
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     //定义两个指针  从左右同时向中间靠  同时交换两个指针对应的元素
//     int left = 0;
//     int right = sz - 2;
//     while (left < right) {
//         char tem = 0;
//         tem = arr[left];
//         arr[left] = arr[right];
//         arr[right] = tem;

//         left++;
//         right--;
//     }
//     printf("%s\n", arr);
//     return 0;
// }

//递归的解法
// #include <stdio.h>
// int my_strlen(char* str) {
//     int count = 0;
//     while (*str != '\0') {
//         count++;
//         str++;
//     }
//     return count;
// }
//函数方案1
// void reverse(char* str) {
//     char temp = *str;
//     int len = my_strlen(str);

//     //将右端元素赋值到左端
//     *str = *(str + len - 1);
//     //将右端元素赋值为\0
//     *(str + len - 1) = '\0';

//     // 限制递归条件,下一轮字符串个数大于2
//     if (my_strlen(str + 1) >= 2) {
//        reverse(str + 1); 
//     }
//     //将临时变量赋值回去
//     *(str + len - 1) = temp;

// }

// int main() {
//     //a b c d e f \0
//     char arr[] = "abcdef";
//     reverse(arr);
//     printf("%s\n", arr);
//     return 0;
// }

//函数方案2
// void reverse(char arr[], int left, int right) {
//     if (left < right) {  // 正确终止条件
//         char temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;

//         reverse(arr, left + 1, right - 1);
//     }
// }


// int main() {
//     //a b c d e f \0
//     char arr[] = "abcdef";
//     int left = 0;
//     int right = my_strlen(arr) - 1;
//     reverse(arr, left, right);
//     printf("%s\n", arr);
//     return 0;
// }

//计算一个数的每位的和
// #include <stdio.h>
// int func(int x) {
//     if (x > 9) {
//        return func(x / 10) + x % 10; 
//     }   
//     else {
//         return x;
//     }
// }

// int main() {
//     int x = 0;
//     int result = 0;
//     scanf("%d", &x);
//     result = func(x);
//     printf("%d\n", result);

//     return 0;
// }

//n的k次方
// #include <stdio.h>
// float func(int n, int k) {
//     if (k > 0) {
//         return n * func(n,(k - 1));
//     }
//     else if (k < 0) {
//         return (float)1/n * func(n ,k + 1);
//     }
//     return 1;
// }

// int main() {
//     int n = 0;
//     int k = 0;
//     float result = 0;
//     scanf("%d %d", &n, &k);
//     result = func(n,k);
//     printf("%f\n", result);

//     return 0;
// }


//A B 数组交换内容  数组一样大

// #include <stdio.h>
// int main() {
//     int arr_1[] = {1,2,3,4,5};
//     int arr_2[] = {6,7,8,9,0};
//     int sz = sizeof(arr_1) / sizeof(arr_1[0]);
//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         int temp = 0;

//         temp = arr_1[i];
//         arr_1[i] = arr_2[i];
//         arr_2[i] = temp;
//     }



//     int j = 0;
//     for (j = 0; j < sz; j++) {
//         printf("%d ", arr_1[j]);
//     }
//     printf("\n");
//     for (j = 0; j < sz; j++) {
//         printf("%d ", arr_2[j]);
//     }
//     return 0;
// }

//创建一个整型数组
//实现函数init 初始化数组全为0
//实现print 打印数组的每一个元素
//实现reverse 数组元素逆序
// #include <stdio.h>
// void init(int arr[], int sz) {
//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         arr[i] = 0;
//     }
// }

// void print(int arr[], int sz) {
//     int j = 0;
//     for (j = 0; j < sz; j++) {
//         printf("%d ", arr[j]);
//     }
//     printf("\n");
// }

// void reverse(int arr[], int left, int right) {
//     while (left < right) {
//         int temp = 0;
//         temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;
        
//         left++;
//         right--;
//     }
// }

// int main() {
//     int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//     int sz = sizeof(arr) / sizeof(arr[0]);

//     int left = 0;
//     int right = sz - 1;
    
//     print(arr, sz);
//     reverse(arr, left, right);
//     print(arr, sz);
//     //初始化
//     init(arr, sz);
//     print(arr, sz);
// }

//编写代码求一个整数存储在内存中的二进制中1的个数
//求补码的二进制的1的个数
// #include <stdio.h>
//     // 0011 a = 3
//     // 0001 1
// int main () {
//     int a = 3;
//     int i = 0;
//     int count = 0;
//     for (i = 0; i < 32; i++) {
//         if ((a & 1) == 1) {
//             // == 的等级比&高
//             count++;
//         }
//         a = a >> 1; 
//     }
//     printf("%d\n", count);

// }

// #include <stdio.h>

// int countOnes(int a) {
//     int count = 0;
//     while (a) {  // 避免遍历所有 32 位
//         count += (a & 1); // 检查最低位是否是1
//         a >>= 1; // 右移
//     }
//     return count;
// }

// int main() {
//     int a = 3;
//     printf("二进制中 1 的个数: %d\n", countOnes(a));
//     return 0;
// }

// Brian Kernighan 算法
// #include <stdio.h>
// int countOnesFast(int a) {
//     int count = 0;
//     while (a) {
//         a &= (a - 1); // 每次消去最低位的 1
//         count++;
//     }
//     return count;
// }

// int main() {
//     int a = 3;
//     printf("二进制中 1 的个数: %d\n", countOnesFast(a));
//     return 0;
// }


//两个int 整数n和m中二进制的表达式中有多少个(bit)位不同
//法1
// int count_diff_bit(int m, int n) {
//     int i = 0;
//     int count = 0;
//     for (i = 0; i < 32; i++) {
//         if (((m >> i) & 1) != ((n >> i) & 1)) {
//             count++;
//         }
//     }

//     return count;
// }

// //法2
// int count_diff_bit(int m, int n) {

//     int count = 0;
//     //使用异或^，相异为1，相同为0
//     int ret = m ^ n;
//     //统计1的个数
//     while (ret) {

//          消去最小位的1
//         ret = ret & (ret - 1);
//         count++;
//     }

//     return count;
// }

// #include <stdio.h>
// int main() {
//     int n = 0;
//     int m = 0;
//     scanf("%d %d", &n, &m);

//     int ret = count_diff_bit(m, n);
//     printf("%d\n", ret);
// }

//获取一个二进制数的序列中的奇数位和偶数位，分别打印出二进制序列
//10
// 00000000 00000000 00000000 00001010
// #include <stdio.h>
// int main() {
//     int i = 0;
//     int num = 0;
//     scanf("%d", &num);

//     //奇数位    31开始
//     for (i = 30; i >=0; i -= 2) {
//         // & 1 可以判断第一位，第一位为1则结果为1，第一位为0，返回结果为0
//         printf("%d ", (num >> i) & 1);
//     }
//     printf("\n");

//     //偶数位
//     for (i = 31; i >=0; i -= 2) {
//         printf("%d ", (num >> i) & 1);
//     }
// }

// 全局变量和静态变量未初始化为0
// 局部变量(栈区)会是随机值

// int i;
// #include <stdio.h>
// int main() {

//     i--;//-1
//     //sizeof返回的是size_t类型的,是无符号整型
//     // -1转化为无符号整型会变成一个非常大的数字
        // 相当于将-1的补码直接转换成正整数看待
//     if (i > sizeof(i)) {

//         printf("666\n");
//     }
//     else {

//         printf("777\n");
//     }
// }

//bc68 x型图案
// #include <stdio.h>
// int main() {
//     int n = 0;
//     // 而while里面的scanf用于检查读取是否成功： 
//     // 如果 scanf 成功读取了一个整数（返回值为 1）返回读取的元素的个数
//     // 则进入循环体处理当前输入的 n 如果 scanf 无法读取整数（返回值为 0 或 -1）循环结束
//     while (scanf("%d", &n) == 1) {
//         int i = 0;
//         int j = 0;
//         for (i = 0; i < n; i++) {
//             for (j = 0; j < n; j++) {
//                 if (i == j) {
//                     printf("*");
//                 }
//                 else if (i + j == n -1) {
//                     printf("*");
//                 }
//                 else {
//                     printf(" ");
//                 }
//             }
//             printf("\n");
//         }
//     }

    
//     return 0;
// }


//某年某月为多少天
// #include <stdio.h>
// int is_leap_year(int y) {
//     return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
// }
// int main() {
//     int y = 0;
//     int m = 0;
//     int d = 0;
//     int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 
//     while (scanf("%d %d", &y, &m) == 2) {

//         int d = days[m];
//         if ((is_leap_year(y) == 1) && (m == 2)) {
//             d++;
//         }
//         printf("%d\n", d);
//     }
//     return 0;

// }

#include <stdio.h>

int main() {
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("%d", i);
    }
    
    printf("\n按 Enter 键退出...");
    getchar(); // 等待用户输入，防止窗口自动关闭
    return 0;
}
