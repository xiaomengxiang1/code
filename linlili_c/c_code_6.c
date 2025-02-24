//float 单精度      占用4字节(byte)     精准表示6~9位数字(超出会出现精度损失)
//double 双精度     占用8字节(byte)     精准表示15~17位数字

#include <stdio.h>

int main() {
    float float_1 = 11.27;
    float float_2 = 11.12345678910;
    printf("float_1:%f, float_2:%f\n",float_1, float_2);        //自动保留6位小数
    double double_1 = 11.12345678910;
    printf("float:%.10f,double_1:%.10lf\n",float_2, double_1);  //%.n   保留n位小数
    return 0;
}