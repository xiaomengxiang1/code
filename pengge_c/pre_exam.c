
// 冒泡排序
// #include <stdio.h>

// void bubble_sort(int* arr, int sz) {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++) {
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++) {
//             if (arr[j] > arr[j + 1]) {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int arr[] = {9,8,7,6,5,4,3};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, sz);

//     int i = 0;
//     for (i = 0; i < sz; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }



// 文件操作
// fputc 输出流  写入
// fgetc 输入流  读取

// #include <stdio.h>

// int main() {
//     FILE* pf;
//     pf = fopen("test.txt", "w");
//     if (pf == NULL) {
//         printf("fail\n");
//         return 1;
//     }
//     int i = 0;
//     for (i = 'A'; i <= 'Z';i++) {
//         fputc(i, pf);
//     }
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 若读取时已到达文件末尾（EOF），函数返回 EOF，并通过 feof(stream) 标记文件结束状态。
// 若读取过程中发生错误（如磁盘故障、权限问题等），函数也返回 EOF，并通过 ferror(stream) 标记错误状态。
// #include <stdio.h>

// int main() {
//     FILE* pf;
//     pf = fopen("test.txt", "r");
//     if (pf == NULL) {
//         printf("fail\n");
//         return 1;
//     }
//     int c;
//     while ((c = fgetc(pf)) != EOF) {
//         putchar(c);
//     }
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     FILE* pf;
//     pf = fopen("test.txt", "w");
//     if (pf == NULL) {
//         printf("fail \n");
//         return 1;
//     }
//     fputs("hello world", pf);

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     FILE* pf;
//     pf = fopen("test.txt", "r");
//     if (pf == NULL) {
//         printf("fail \n");
//         return 1;
//     }
//     char arr[20] = {0};
//     fgets(arr, 10, pf);

//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// 二分查找
// #include <stdio.h>
// int search(int* arr, int left, int right, int k) {
//     while (left <= right) {
//         int mid = (left + right) / 2;
//         if (k == arr[mid]) {
//             return 1;
//         }
//         else if (k > arr[mid]) {
//             left = mid + 1;
//         }
//         else {
//             right = mid - 1;
//         }
//     }
//     return 0;   
// }


// int main () {
//     int k = 5;
//     scanf("%d", &k);
//     int arr[] = {1,2,3,4,5,6,7,8,9};
//     int left = 0;
//     int right = sizeof(arr) / sizeof(arr[0]) - 1;
//     if (search(arr, left, right, k)) {
//         printf("找到了\n");
//     }
//     else {
//         printf("没找到\n");
//     }
//     return 0;
// }


// #include <stdio.h>
// #include <string.h>
// void reserve(char* arr, int len) {
//     int left = 0;
//     int right = len - 1;
//     while (left < right) {
//         char temp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = temp;

//         left++;
//         right--;
//     }
// }

// int main() {
//     char arr[20] = "hello world";
//     int len = strlen(arr);
//     reserve(arr, len);

//     int i = 0;
//     for(i = 0; i < len; i++) {
//         printf("%c ", arr[i]);
//     }

//     return 0;
// }


//最大公约数和最小公倍数
// #include <stdio.h>
// int main() {
//     int m;
//     int n;
//     scanf("%d %d", &m, &n);
//     int mul = m * n;
//     int ret = 0;
//     while (ret = m % n) {
//         m = n;
//         n = ret;
//     }

//     printf("最大公约数:%d\n", n);
//     printf("最小公倍数:%d\n", mul / n);

//     return 0;
// }

//第n个斐波那契数列
// #include <stdio.h>
// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int i = 1;
//     int j = 1;
//     int an = 0;
//     if (n > 2) {
//         while (n > 2) {
//             an = i + j;
//             i = j;
//             j = an;

//             n--;
//         }
//         printf("%d\n", an);
//     }
//     else {
//         printf("1\n");
//     }
//     return 0;
// }


#include <stdio.h>
#include <string.h>
void my_strcpy(char* arr1, char* arr2) {
    memcpy(arr2, arr1, sizeof(char) * (strlen(arr1) + 1));
}

int main() {
    char arr1[] = "hello world";
    char arr2[30] = {0};
    my_strcpy(arr1, arr2);
    printf("%s\n", arr2);

    return 0;
}