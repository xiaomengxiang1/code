// for(初始化表达式; 条件表达式; 更新表达式) {
//          ...//循环执行的代码
//}

// #include <stdio.h>
// int main() {
//     for(int i = 1; i <= 10; i = i +1) {
//         printf("%d\n",i);
//     }
// }

// i++  (i = i + 1)
//先进行初始化表达式，然后进行条件判断，执行完循环的代码后才进行表达式的更新

#include <stdio.h>

int main() {
    for(int i = 1; i <= 50; i++) {
        if (i % 2 == 0) {
            if (i % 3 == 0) {
                continue;
            }
            else if (i == 42) {
                break;
            }
            printf("%d\n",i);
        }
    }
}


