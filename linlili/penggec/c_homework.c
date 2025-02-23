//小飞机

// #include <stdio.h>
// int main() {
//     printf("    **    \n");
//     printf("    **    \n");
//     printf("**********\n");
//     printf("**********\n");
//     printf("  *    *  \n");
//     printf("  *    *  \n");
//     return 0;
// }

//输出学生信息
// #include <stdio.h>

// int main() {
//     printf("Name\tAge\tGender\n");
//     printf("----------------------\n");
//     printf("Jack\t18\tman\n");
//     return 0;
// } 

//计算
// #include <stdio.h>
// int main() {
//     int a = 40;
//     int c = 212;
//     float b = (-8 + 22) * a - 10 + c / 2;
//     printf("%f",b);
//     return 0;
// }

//输出两个数字中较大的一个
// #include <stdio.h>

// int Max(int x, int y) {
//     if (x > y) {
//         return x;
//     }
//     else {
//         return y;
//     }
// }

// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     int r = Max(a,b);
//     printf("%d",r);
// }

//x = 0 y = 0,x = 正 y = -1, x = 负 y = 1

// #include <stdio.h>
// int main() {
//     int x = 0;
//     int y = 0;
//     printf("输入x的值:");
//     scanf("%d", &x);
//     if (x < 0) {
//         int y = 1;
//         printf("y = %d",y);
//     }
//     else if (x == 0) {
//         int y = 0;
//         printf("y = %d",y);
//     }
//     else {
//         int y =-1;
//         printf("y = %d",y);
//     }
//     return 0;
// }
//注意作用域

// a/b 的余数和整数部分

// #include <stdio.h>

// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d",&a, &b);
//     int c = a / b;
//     int d = a % b;
//     printf("%d %d", c, d);
//     return 0;
// }

//判断奇数

// #include <stdio.h>

// int main() {
//     int a = 2;
//     if (a % 2 == 0) {
//         printf("偶数");
//     }
//     else {
//         printf("奇数");
//     }
//     return 0;
// }

//输出1到100的奇数
// #include <stdio.h>

// int main() {
//     for (int i = 1; i <= 100; i++) {
//         if (i % 2!= 0) {
//             printf("%d\n",i);
//         }
//     }
//     return 0;
// }

//转换ASCII码值为字符
//  'a'/    ascii   97

// #include <stdio.h>
// int main() {

//     // printf("%c\n", 'a');
//     // printf("%c\n", 97);
//     int arr[] = {73, 32, 99, 97, 110, 32, 100, 111, 32, 105, 116, 33};
//     int i = 0;
//     int sz = sizeof(arr)/sizeof(arr[0]);

//     // arr[0] 是数组 arr 的第一个元素，它是一个 int 类型
//     //sizeof(arr) 返回整个数组 arr 占用的字节数

//     while (i < sz) {
//         printf("%c",arr[i]);
//         i++;
//     }
    
//     return 0;
// }

//a b交换数字
// #include <stdio.h>
// int main() {
//     int a,b;
//     scanf("%d %d",&a, &b);
//     a = a + b;
//     b = a - b;
//     a = a - b;
//     printf("a=%d,b=%d\n",a, b);
//     return 0;
// }

//输入生日，然后分别输出年月日
// #include <stdio.h>
// int main() {
//    int year = 0;
//    int month = 0;
//    int data = 0;
// //    "%4d"：读取四个数字并将其存储到 year 变量中。
// //     "%2d"：读取两个数字并将其存储到 month 变量中。
// //     "%2d"：读取两个数字并将其存储到 date 变量中。
//    scanf("%4d%2d%2d",&year, &month, &data);

// //    %：表示这是一个格式化输出的开始。
// //    0：这是一个 填充符，表示如果数字的位数不足指定的宽度，应该用 0 来填充。
// //    2：表示该数字至少应该占用 2 个字符宽度。如果数字的位数不足 2 位，会使用 0 填充。
// //    d：表示输出的是一个 十进制整数（即 int 类型的值）。
//    printf("year = %d\n",year);
//    printf("month = %03d\n",month);
//    printf("data = %03d\n",data);

//    return 0;
// }

//输入学生学号以及学科信息，处理后进行输出
// #include <stdio.h>
// int main() {
//     int id = 0;
//     float c_score = 0.0f;   //没有f默认是双精度的
//     float math_score = 0.0f;
//     float english_score = 0;
//     printf("学号以及3科成绩,学号和成绩之间用英文分号隔开,成绩之间用英文逗号隔开\n");
//     scanf("%d;%f,%f,%f",&id, &c_score, &math_score, &english_score);
//     printf("The each subject score of No. %d is %.2f, %.2f, %.2f.\n",id, c_score, math_score, english_score);
//     return 0;
// }

//打印出调用printf函数后的返回值
// #include <stdio.h>
// int main() {
//     int a;
//     a = printf("Hello world");  //返回打印的字符串的个数,若有\n，\n算一个
//     printf("\n%d",a);
//     return 0;
// }


//打印printf("hello world\n")
// #include <stdio.h>
// int main() {
//     printf("printf(\"hello world\\n\")\n");
//     printf("cout << \"hello world\" <<endl;\n");
// }

//找最大数(4个中)

// #include <stdio.h>
// int max(int x, int y) {
//     if (x > y) {
//         return x;
//     }
//     return y;
// }
// int main() {
//     int a,b,c,d;
//     scanf("%d %d %d %d",&a, &b, &c, &d);
//     int ab = max(a,b);
//     int cd = max(c,d);
//     int num = max(ab,cd);
//     printf("max_num = %d\n",num);
//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int arr[4] = {0};
//     int i = 0;
//     while (i < 4) {
//         printf("输入数字:");
//         scanf("%d",&arr[i]);
//         i++;
//     }

//     //找最大值
//     //假设第一个是最大值
//     int max = arr[0];
//     i = 1;
//     while (i < 4) {
//         if (max < arr[i]) {
//             max = arr[i];
//         }
//         i++;
//     }
//     printf("max_num = %d",max);
// }

// #include <stdio.h>
// int main() {
//     int i = 1;
//     int n = 0;
//     int max = 0;
//     //假设第一个是最大值 
//     printf("输入数字:");
//     scanf("%d",&max);

//     while (i < 4) {
//         printf("输入数字:");
//         scanf("%d",&n);

//         if (max < n) {
//             max = n;
//         }
//         i++;
//     }
//     printf("max_num = %d",max);
//     return 0;
// }

//球的体积
// #include <stdio.h>
// int main() {
//     double r = 0;
//     printf("半径0到15:");
//     scanf("%f",&r);
//     double v = 4 *  3.1415926 * (r * r * r) / 3;
//     printf("球的体积:%.3lf\n",v);
//     return 0;
// }

//BMI计算

#include <stdio.h>
int main() {
    int weight = 0;
    int height = 0;
    printf("体重(公斤),身高(厘米):");
    scanf("%d %d",&weight, &height);
    double BMI = (weight / ((height/100.0) * (height/100.0)));
    printf("BMI = %.2lf",BMI);  
    return 0;
}
