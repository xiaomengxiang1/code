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

// #include <stdio.h>
// int main() {
//     int weight = 0;
//     int height = 0;
//     printf("体重(公斤),身高(厘米):");
//     scanf("%d %d",&weight, &height);
//     double BMI = (weight / ((height/100.0) * (height/100.0)));
//     printf("BMI = %.2lf",BMI);  
//     return 0;
// }

//n的阶乘
// #include <stdio.h>
// int main() {
//     int i = 0;
//     int result = 1;
//     int n = 1;
//     scanf("%d",&n);
//     for(i = 1; i <= n; i++) {
//         result *= i;
//     }
//     printf("%d的阶乘是:%d", n, result);
//     return 0;
// }

//计算1! + 2! +.....+10!
// #include <stdio.h>
// int main() {
//     int i = 0;
//     int result = 1;
//     int n = 1;
//     int sum = 0;
//     scanf("%d",&n);
//     for(i = 1; i <= n; i++) {
//         result *= i;
//         sum += result;
//     }
//     printf("%d的阶乘是:%d\n", n, result);
//     printf("1! + 2! +.....+10!的值是:%d\n", sum);
//     return 0;
// }

//有序数组中查找具体的数字n
// #include <stdio.h>
// int main() {
//     int arr[] = {1,2,3,4,5,6,7,23,45,676};
//     int n = 0;
//     int sz = sizeof(arr)/sizeof(arr[0]);
//     int i = 0;
//     scanf("%d", &n);
//     for(i = 0; i < sz; i++) {
//         if (n == arr[i]) {
//             printf("有%d这个数字\n",n);
//             break;
//         }
//     }
//     if (i == sz) {
//         printf("没有找到数字%d\n",n);
//     }
//     return 0;
// }

//用二分法查找解决上个问题(有序数组)
// #include <stdio.h>
// int main() {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int sz = sizeof(arr)/sizeof(arr[0]);

//     int left = 0;
//     int right = sz - 1;
    
//     //查找n
//     int n = 0;
//     scanf("%d", &n);

//     while (left <= right) {
//         int mid = (left + right) / 2;
//         if (arr[mid] < n) {
//             left = mid + 1; 
//         }
//         else if (arr[mid] > n) {
//             right = mid - 1;
//         }
//         else {
//             printf("找到了,下标为%d", mid);
//             break;
//         }        
//     }
//     if (left > right) {
//         printf("找不到");
//     }
//     return 0;
// }
//时间复杂度为log2(n)

//多个字符从两端移动,向中间汇聚
// #include <stdio.h>
// #include <string.h>
// #include <windows.h>
// #include <stdlib.h>

// int main() {
//     char arr_1[] = "hello world";
//     char arr_2[] = "###########";

//     int left = 0;
//     int right = strlen(arr_1) - 1;  //字符串长度,因为索引小1,所以减去1
//     // int right = sizeof(arr_1) / sizeof(arr_1[0]) - 2;   //[....,\0]这里有算\0的长度所以多减一个1

//     while (left <= right) {
//         arr_2[left] = arr_1[left];
//         arr_2[right] = arr_1[right];

//         Sleep(1000);    //等待1000ms
//         system("cls");  //system是一个库函数,可以执行系统命令
        
//         printf("%s\n",arr_2);
//         left++;
//         right--; 
//     }
//    return 0;
// }

//用户登入,最多登入三次机会
// #include <stdio.h>

// int main() {
//     int i = 0;
//     int password = 123456;
//     int key = 0;
//     while (i < 3) {
//         printf("输入密码:");
//         scanf("%d", &key);
//         if (key == password) {
//             printf("密码正确\n");
//             break;
//         }
//         else {
//             printf("密码错误\n");
//         }
//         i++;
//     }
//     return 0;
// }

//比较两个字符是否相等,不能用==,应该用一个库函数:strcmp
//如果返回值是0,表示两个字符串相等
// #include <stdio.h>
// #include <string.h>  // 引入 string.h 以使用 strcmp
// int main() {
//     int i = 0;
//     char password[20] = {0};
//     //假设密码是abcdef
//     for (i = 0; i < 3; i++) {
//         printf("请输入密码>\n");
//         scanf("%s", password);  // 数组本身表示地址,不用取地址符
//         if (strcmp(password, "abcdef") == 0) {
//             printf("密码正确\n");
//             break;
//         }
//         else {
//             printf("密码错误\n");
//         }
//     }
//     if (i == 3) {
//         printf("三次密码均输入错误,程序退出\n");
//     }
//     return 0; 
// }

//猜数字小游戏
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void menu() {
//     printf("                               \n");
//     printf("*******************************\n");
//     printf("*******   1. play    **********\n");
//     printf("*******   0. exit    **********\n");
//     printf("*******************************\n");
//     printf("                               \n");
// }

// //0~RAND_MAX
// void game() {
//     int guess = 0;
//     //1.生成随机数

//     // 0到100
//     int ret = rand()%100 + 1;   //生成随机数的函数
//     // printf("%d\n", ret);
//     //2.猜数字
    
//     while (1) {

//         printf("请猜数字>\n");
//         scanf("%d", &guess);

//         if (guess < ret) {
//             printf("猜小了\n");
//         }
//         else if (guess > ret) {
//             printf("猜大了\n");
//         }
//         else {
//             printf("猜对了\n");
//             break;
//         }  
//     }
  

// }

// int main() {
//     int input = 0;

//     //srand 函数需要一个 unsigned int 类型的种子
//     //所以需要将 time(NULL) 的结果强制转换为 unsigned int 类型
//     //这是为了确保类型匹配

//     //srand 是 C 标准库中的一个函数，用来初始化随机数生成器的种子
//     srand((unsigned int)time(NULL));

//     do {
//         menu();
//         printf("请选择\n");
//         scanf("%d", &input);
//         switch (input) {
//         case 1:
            
//             game();
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("选择错误,重新选择\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }

//输入我是猪,不然自动关机
// #include <stdio.h>
// #include <string.h>
// #include <windows.h>

// int main() {
//     char input[20] = {0};
//     system("shutdown -s -t 60");
// again:
//     printf("你的电脑将在60s后关机,如果输入:我是猪,就取消关机\n");
//     scanf("%s", input);
//     if (strcmp(input, "我是猪") == 0) {
//         system("shutdown -a");
//     }
//     else {
//         goto again;
//     }
//     return 0;
// }

// 质数，又称素数，指在大于1的自然数中，除了
// 1和该数自身外，无法被其他自然数整除的数
//写一个判断素数的函数
//判断1到200之间的素数
//素数只能被1和本身整除的
// #include <stdio.h>

// int main() {
//     int i = 0;
//     int count = 0;
    
//     //创造1到200
//     //可以写成i += 2;直接跳过偶数
//     for(i = 100; i <= 200; i++) {
//         //拿2到i-1式除
//         int flag = 1;//是1表示是素数
//         int j = 0;

//         //可以写成j <= sqrt(i),一个数字如果可以写成a*b的形式,则a或b一定有一个数<= sqrt(i)
//         for(j = 2; j <= i-1; j++) {
//             if (i % j == 0) {
//                 flag = 0;
//                 break;
//             }
//         }
//         if (flag == 1) {
//             count++;
//             printf("%d ", i);
//         }
//     }
//     printf("\ncount = %d\n",count);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int is_prime(int x) {
//     int j = 0;
//     for (j = 2; j <= sqrt(x); j++) {
//         if (x % j == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }
// int main() {
//     int i = 0;
//     int count = 0;
//     for (i = 100; i <= 200; i++) {
//         if (is_prime(i)) {
//             printf("%d ", i);
//             count++;
//         }
//     }
//     printf("\ncount = %d\n", count);
//     return 0;
// }

//1000到2000的闰年
//1.能被4整除,不能被100整除
//2.能被400整除
// #include <stdio.h>
// int main() {
//     int year = 0;
//     for (year = 1000; year <= 2000; year++) {
//         if ((year % 4 == 0) && (year % 100 != 0)) {
//             printf("%d ", year);
//         }
//         else if (year % 400 == 0) {
//             printf("%d ", year);
//         }
//     }
//     return 0;
// }

// #include <stdio.h>
// int is_leap_year(int y) {
//     if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
//         return 1;
//     }
//     return 0;
// }
// int main() {
//     int year = 0;
//     for (year = 1000; year <= 2000; year++) {
//         if (is_leap_year(year)) {
//             printf("%d ", year);
//         }
//     }
//     return 0;
// }

//二分查找函数

// #include <stdio.h>
// int binary_search(int arr[], int k, int sz) {
//     int left = 0;
//     int right = sz -1;

//     while (left <= right) {
//         int mid = left + (right - left) / 2;//这么写避免数据溢出
//         if (arr[mid] < k) {
//             left = mid + 1;
//         }
//         else if (arr[mid] > k) {
//             right = mid - 1;
//         }
//         else {
//             return mid;//找到了返回下标
//         }      
//     }
//     return -1;//找不到的情况

// }

// int main() {
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int k = 5;
//     int sz = sizeof(arr) / sizeof(arr[0]);

//     //找到了返回下标
//     //找不到返回-1
//     int ret = binary_search(arr, k, sz);
//     if (ret == -1) {
//         printf("找不到\n");
//     }
//     else {
//         printf("找到了,下标index = %d\n", ret);
//     }
//     return 0;
// }

// int binary_search(int arr[], int k)
//arr是一个指针变量

//传递数组的时候传递给函数的是数组0位元素的地址,即&arr[0]

// int sz = sizeof(arr) / sizeof(arr[0]);
// 在函数内部计算sz等于两个指针变量的大小相除,为4/4 = 1;

//调用一次num加1
// #include <stdio.h>
// void add(int* p) {
//     // *p++ 只是移动指针 p，没有修改 *p 指向的值
//     (*p)++;
// }
// int main() {
//     int num = 0;
//     add(&num);
//     printf("%d\n", num);//1
//     add(&num);
//     printf("%d\n", num);//2
//     add(&num);
//     printf("%d\n", num);//3
// }

//传入无符号整型,按顺序输出每一位,1234输出1 2 3 4
//递归的实现

// #include <stdio.h>
// void print(unsigned int n) {

//     if (n > 9) {
//         print(n / 10);
//     }
//     printf("%u ", n % 10);
// }
// int main() {
//     unsigned int num = 0;
//     scanf("%u", &num);
//     print(num);
//     return 0;
// }

//编写函数不允许创建临时变量,求字符串的长度
//模拟实现strlen函数
// #include <stdio.h>
// //此时str指向arr数组的a的地址
// int my_strlen(char* str) {
//     int count = 0;
//     while (*str != '\0') {
//         count++;
//         // *str++,先使用*str再移动指针
//         str++;
//     }
//     return count;
// }
// int main() {
   
//     char arr[] = "abc";//[a,b,c,\0]
//     int len = my_strlen(arr);
    
//     // 这里传递的字符串参数相当于a的地址,和传递数组参数时一样
//     // int len = my_strlen("abc");

//     printf("%d\n", len);
//     return 0;
// }

//递归求解
//my_strlen("abc")
//1 + my_strlen("bc")
//1 + 1+ my_strlen("c")
//1 + 1+ 1+ 0 my_strlen("")

// #include <stdio.h>

// int my_strlen(char* str) {

//     // str 是指针，表示地址
//     // *str 是指针指向的值，表示字符

//     if (*str != '\0') {
//         //利用上面char* str声明的指针变量str,使其移动至下一个字符
//         // str++;
//         return 1 + my_strlen(str + 1);
//     }
//     else {
//         return 0;
//     }
// }
// int main() {
   
//     char arr[] = "abc";//[a,b,c,\0]
//     int len = my_strlen(arr);

//     printf("%d\n", len);
//     return 0;
// }

//n!
// #include <stdio.h>

//递归
// int fac(int n) {
//     if (n > 1) {
//         n = n * fac(n - 1);
//     }
//     else {
//         return 1;
//     }
//     return n;
// }
// int fac(int n) {
//     if (n <= 1) {
//         return 1;
//     }
//     else {
//         return n * fac(n - 1);
//     }
// }

//迭代
// int fac(int n) {
//     int i = 0;
//     int ret = 1;
//     for (i = 1; i <= n; i++) {
//         ret *= i; 
//     }
//     return ret;
// }

// int main() {
//     int n = 1;
//     scanf("%d", &n);
//     int ret = fac(n);
//     printf("%d\n", ret);
//     return 0;
// }

//第n个斐波那契数列
//1 1 2 3 5 8 13 21

//采用递归但是效率低下

// int fib(int n) {
//     if (n <= 2) {
//         return 1;
//     }
//     else {
//         return fib(n-1) + fib(n-2);
//     }
// }

//迭代
// #include <stdio.h>
// int fib(int n) {
//     int a = 1;
//     int b = 1;
//     int c = 0;
//     while (n >= 3) {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }

// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int ret = fib(n);
//     printf("%d\n", ret);
//     return 0;
// }

// 一只青蛙一次可以跳 1 级台阶 或 2 级台阶
// 它跳上 n 级台阶的方式有多少种

// 0级台阶说明已经在台上了f(0) = 1
//1级台阶f(1) = 1
//2级台阶f(1) = 2
//n级台阶时,前一个台阶要么是上1格,要么是上2格
//前一个台阶之前的跳法可以表示为f(n-1)或者f(n-2)
// f(n) = f(n-1) + f(n-2)，相当于斐波那契数列
// f(1) = 1，f(2) = 2
//所以可以直接采用迭代,时间复杂度低

// 汉诺塔问题	hanoi(n) = hanoi(n-1) + 1 + hanoi(n-1)
//共A B C三个柱子
//目标是移动到C柱子上
//假设n个盘子需要移动hanoi(n)步完成
//将n盘子上的n-1个盘子视为一个整体
//现在将这n-1个盘子移动到B柱子上,其实步骤和移动到C柱子上是一样的只是换一个目标
//移动的时候可以忽略最大的一个盘子,因为最大,谁都可以放在它的上面
//所以n-1个盘子移动到B柱子上的步骤也就是hanoi(n-1)
//现在可以将最大的盘子移动到C上面也就是1步
//最后将n-1个盘子由B移动到C,同上的步骤,也就是hanoi(n-1)
//所以递归表达式应该为hanoi(n) = hanoi(n-1) + 1 + hanoi(n-1)

// #include <stdio.h>
// int hanoi(int n) {
//     if (n > 1) {
//         return (2 * hanoi(n-1) + 1);
//     }
//     else {
//         return 1;
//     }
// }
// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int ret = hanoi(n);
//     printf("%d\n", ret);
//     return 0;
// }

//三个整数从大到小输出
// #include <stdio.h>
// void swap(int* px, int* py) {
//     int tem = *px;
//     *px = *py;
//     *py = tem;
// }
// int main() {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     //输入
//     scanf("%d %d %d", &a, &b, &c);
//     //最大的放在a里面
//     if (a < b) {
//         swap(&a, &b);
//     }
//     if (a < c) {
//         swap(&a, &c);
//     }
//     //第二大的放b里
//     if (b < c) {
//         swap(&b, &c);
//     }

//     //输出
//     printf("%d %d %d\n",a, b, c);
//     return 0;
// }

//1到100之间所有3的倍数
// #include <stdio.h>
// int main() {
//     int i = 0;
//     for (i = 1; i <= 100; i++) {
//         if (i % 3 == 0) {
//             printf("%d ", i);
//         }
//     }
//     return 0;
// }

//两个数之间的最大公约数

//暴力求解
// #include <stdio.h>
// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     //三目运算符(exp1?exp2:exp3)，若exp1成立，执行exp2，反之执行exp3
//     //找比较小的数
//     int min = a < b ? a : b;
//     int m = min;
//     while (1) {
//         if ((a % m == 0) && (b % m == 0)) {
//             break;
//         }
//         m--;
//     }
//     printf("%d\n", m);
//     return 0;
// }

//辗转相除法
// #include <stdio.h>
// int main() {
//     int a = 0;
//     int b = 0;
//     scanf("%d %d", &a, &b);
//     while (a % b != 0) {
//         int c = a % b;
//         a = b;
//         b = c;
//     }
    
//     printf("%d\n", b);
//     return 0;
// }


//1到100中有几个9(数字中的9,不是被9整除)
// #include <stdio.h>
// int main() {
//     int i = 0;
//     int count = 0;
//     for (i = 1; i <= 100; i++) {
//         //个位
//         if (i % 10 == 9) {
//             count++;
//         }
//         //十位
//         if (i / 10 == 9) {
//             count++;
//         }
//     }
//     printf("%d\n", count);
//     return 0;
// }

// -----------------------
// #include <stdio.h>
// int main() {
//     int i = 0;
//     double sum = 0;
//     int flag = 1;

//     for (i = 1; i <= 100; i++) {
//         sum = sum + flag * (1.0 / i);
//         flag = -flag;
//     }
//     printf("%lf\n", sum);
//     return 0;
// }

//10个中的最大值
// #include <stdio.h>
// int main() {
//     int arr[] = {1,2,3,4,5,6,7,8,9,0};
//     int sz = sizeof(arr)/sizeof(arr[0]) - 1;
//     int i = 0;
//     //假设最大为第一个
//     int max = arr[0];
//     for (i = 1; i <= sz; i++) {
//         if (max < arr[i]) {
//             max = arr[i];
//         }
//     }
//     printf("%d\n", max);
//     return 0;
// }

//乘法表
// #include <stdio.h>
// int main() {
//     int i = 0;
//     int j = 0;
//     int n = 0;
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++) {
//         for (j = 1; j <= i; j++) {
//             printf("%d * %d = %d  ", i, j, i*j);
//         }
//         printf("\n");
//     }
//     return 0;
// }

