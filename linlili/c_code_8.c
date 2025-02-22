//声明常量时用全大写字母命名，常量声明时就要赋值，不能通过之后赋值

// int main() {
//     const int WORKING_HOURS_PER_WEEK = 40;
// }

#include <stdio.h>
#include <math.h>

int main() {
    const float PI = 3.14;
    int r_1 = 2;
    int r_2 = 8;
    printf("m_1 = %.2f\n",PI * pow(r_1,2));
    printf("m_2 = %.2f\n",PI * pow(r_2,2));
    return 0;
}