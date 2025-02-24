//  while (判断) {code}

#include <stdio.h>

int main() {
    int i = 1;
    int a = 1;
    int result_1 = 0;
    int result_2 = 0;
    while (i <= 100) {
        if (i % 2 == 0) {
            result_1 = result_1 + i;   
        }
        i = i + 1;
    }
    printf("1~100的偶数和:%d\n",result_1);

    do {
        if (a % 2 == 0) {
            result_2 = result_2 + a;
        }
        a = a + 1;
    } while(a <= 100);

    printf("1~100的偶数和:%d\n",result_2);
    return 0;
}