// 描述
// 小乐乐喜欢数字，尤其喜欢0和1。他现在得到了一个数，
// 想把每位的数变成0或1。如果某一位是奇数，就把它变成1，如果是偶数，那
// 么就把它变成0。请你回答他最后得到的数是多少。
// 输入描述：
// 输入包含一个整数n（0≤n≤10^9）输出描述：
// 输出一个整数，即小乐乐修改后得到的数字。
// #include <stdio.h>
// void func(int n) {
//     if (n > 9) {
//         func(n / 10);
//     }
//     printf("%d", n % 2);
// }

// int main() {

//     int n = 0;
//     scanf("%d", &n);
//     func(n);
//     return 0;
// }

// #include <stdio.h>
// #include <math.h>
// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int sum = 0;
//     int count = 0;
//     while (n) {
//         int bit = n % 10;
//         if (bit % 2 == 0) {
//             sum += 0;
//         }
//         else {
//             sum += 1 * pow(10,count);
//         }
//         count++;
//         n = n / 10;
//     }
//     printf("%d ", sum);
//     return 0;
// }

//直角三角形
//输入一个数 代表行数和三角形的边长
// #include <stdio.h>
// int main() {
//     int n = 0;
//     scanf("%d", &n);
//     int i = 0;
//     //总的行数n
//     for (i = 0; i < n; i++) {
//         //空格
//         int j = 0;
//         //打印列    j为列 个数为4 3 2 1...逐渐减小
//         for (j = 0; j < n - 1 - i; j++) {
//             printf("  ");
//         }
//         //星号
//         j = 0;
//         //打印列 j为列  个数为1 2 3 4 ...逐渐变大
//         for (j = 0; j < i + 1; j++) {
//             printf("* ");
//         }
//         printf("\n");
//     }

//     return 0;
// }


// 描述
// KiKi非常喜欢网购，在一家店铺他看中了一件衣服，他了解到，如果今天是“双11”（11月11日）
// 则这件衣服打7折，“双12”（12月12日）则这件衣服打8折，如果有优
// 惠券可以额外减50元（优惠券只能在双11或双12使用），
// 求KiKi最终所花的钱数。数据范围：衣服价格满足1≤val≤100000
// 输入描述：
// 一行，四个数字，第一个数表示小明看中的衣服价格，第二和第三个整数分别表示当天的月份、
// 当天的日期、第四个整数表示是否有优惠券（有优惠券用1表示，无优惠券用0表示）。
// 注：输入日期保证只有“双11”和“双12”。
// 输出描述：
// 一行，小明实际花的钱数（保留两位小数）。（提示：不要指望商家倒找你钱）

//错误版
// #include <stdio.h>
// int main() {
//     double price = 0;
//     int month = 0;
//     int day = 0;
//     int acount = 0;
//     while (scanf("%lf %d %d %d", &price, &month, &day, &acount) == 4) {
//         if (price >= 50) {
//             //有优惠卷
//             if (acount) {
//                 if (month == day && day == 11) {
//                     price = price * 0.7 - 50;
//                 }
//                 else if (month == day && day == 12) {
//                     price = price * 0.8 - 50;
//                 }
//             }
//             //无优惠卷
//             else {
//                 if (month == day && day == 11) {
//                     price *= 0.7;
//                 }
//                 else if (month == day && day == 12) {
//                     price *= 0.8;
//                 }
//             }
//         }
//         else {
//             if (month == day && day == 11) {
//                 price *= 0.7;
//             }
//             else if (month == day && day == 12) {
//                 price *= 0.8;
//             }
//         }
//         if (price < 0) price = 0;
//         printf("%lf\n", price);
//     }
//     return 0;
// }

//正确版
// #include <stdio.h>
// int main() {
//     double price = 0;
//     int month = 0;
//     int day = 0;
//     int acount = 0;
//     while (scanf("%lf %d %d %d", &price, &month, &day, &acount) == 4) {
//         if (month == day && day == 11) {
//             price = price * 0.7;
//             if (acount) {
//                 price = price - 50;
//             }
//         }
//         else if (month == day && day == 12) {
//             price = price * 0.8;
//             if (acount) {
//                 price = price - 50;
//             }
//         }
//         if (price < 0)  {
//             price = 0;
//         }
//         printf("%.2lf\n", price);
//     }
//     return 0;
// }

// -------------------------------------------------
// int main() {
//     // unsigned类型在发生整型提升的时候要补0
//     unsigned char a = 200;
//     // 00000000000000000000000011001000
//     // 11001000 - a 截断

//     unsigned char b = 100;
//     // 00000000000000000000000001100100
//     // 01100100 - b 截断

//     unsigned char c = 0;

//     c = a + b;
//     // 整型提升
//     // 00000000000000000000000011001000
//     // 00000000000000000000000001100100
//     // 00000000000000000000000100101100 补码
//     // 00101100 - c 截断
//     // 00000000000000000000000000101100


//     // 00000000000000000000000100101100 补码  a + b直接打印的是源码，因为是整数源码和补码相同

//     printf("%d %d", a + b, c);
//     // 300 44

//     return 0;
// }

// #include <stdio.h>
// int main() {
//     // 小端存储
//     unsigned int a = 0x1234;
//     // 34 12 00 00
//     // --------------->
//     // 低地址      高地址

//     // 解引用一个字节
//     unsigned char b = *(unsigned char*)&a;
//     printf("%x\n", b);

//     return 0;
// }
