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
#include <stdio.h>
int main() {
    //a b c d e f \0
    char arr[] = "abcdef";
    int sz = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = sz - 2;
    while (left < right) {
        char tem = 0;
        tem = arr[left];
        arr[left] = arr[right];
        arr[right] = tem;

        left++;
        right--;
    }
    printf("%s\n", arr);
    return 0;
}


