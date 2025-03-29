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
