// #include <stdio.h>
// #include <stdbool.h>    //标准bool型头文件,定义bool变量

// //  0代表false
// //  1代表true

// int main() {
//     bool is_data_low = true;
//     if (is_data_low) {
//         printf("流量不足了！\n");
//         return 0;
//     }
// }

#include <stdio.h>

int main() {
    int a = 2;
    int b = 8;
    if (a > b) {
        printf("a - b = %d\n",a - b);
    }
    else {
        printf("a + b = %d\n",a + b);
    }
    return 0;
}
