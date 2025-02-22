#include <stdio.h>
#include <math.h>


int main() {
    int result_1;
    result_1 = 2+10/8*3;      //如果均为整数计算时不会取小数(10/8取1)
    printf("result_1=%d\n",result_1);
    double result_2;
    result_2 = 2+10/8.0*3;
    printf("result_2=%lf\n",result_2);


    int a = -1;
    int b = -2;
    int c = 3;
    double x_1 = (-b + sqrt(pow(b,2) - 4*a*c)) / (2*a);
    double x_2 = (-b - sqrt(pow(b,2) - 4*a*c)) / (2*a);
    printf("x_1 = %lf\n",x_1);
    printf("x_1 = %lf\n",x_2);
    return 0;
}