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


// 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
// A选手说：B第二，我第三；
// B选手说：我第二，E第四；
// C选手说：我第一，D第二；
// D选手说：C最后，我第三；
// E选手说：我第四，A第一；
// 比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
// #include <stdio.h>
// int main() {
//     int a = 0;
//     int b = 0;
//     int c = 0;
//     int d = 0;
//     int e = 0;
//     for (a = 1; a <= 5; a++) {
//         for (b = 1; b <= 5; b++) {
//             for (c = 1; c <= 5; c++) {
//                 for (d = 1; d <= 5; d++) {
//                     for (e = 1; e <= 5; e++) {

//                         if (((b == 2) + (a == 3) == 1)
//                          && ((b == 2) + (e == 4) == 1)
//                          && ((c == 1) + (d == 2) == 1)
//                          && ((e == 4) + (a == 1) == 1)) {

//                             if (a * b * c * d * e == 120) {
//                                 printf("a = %d b = %d c = %d d = %d e = %d", a, b, c, d, e);
//                             }
//                          }
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }



// 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
// 以下为4个嫌疑犯的供词：
// A说：不是我。 
// B说：是C。 
// C说：是D。 
// D说：C在胡说
// 已知3个人说了真话，1个人说的是假话
// #include <stdio.h>
// int main() {
//     int killer = 0;
//     for (killer = 'a'; killer <= 'd'; killer++) {
//         //判断
//         if (((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3) {
//             printf("%c ", killer);
//         }
//     }

//     return 0;
// }


//打印杨辉三角
//      1 
//     1 1
//    1 2 1
//   1 3 3 1
//  1 4 6 4 1

// 将三角形移到左边 先简化步骤
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// #define ROW 5
// #define COL 5
// #include <stdio.h>
// int main() {

//     int arr[ROW][COL] = {0};
//     int i = 0;
//     //行
//     for (i = 0; i < ROW; i++) {
//         //列
//         int j = 0;
//         for (j = 0; j <= i; j++) {
//             if (j == 0) {
//                 arr[i][j] = 1;
//             }
//             if (i == j) {
//                 arr[i][j] = 1;
//             }
//             if ((j != 0) && (i != j)) {
//                 arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//             }
//         }
//     }

//     i = 0;
//     int j = 0;
//     for (i = 0; i < ROW; i++) {
//         //空格
//         for (j = 0; j < COL - 1 - i; j++) {
//             printf(" ");
//         }
//         //数字
//         for (j = 0; j <= i; j++) {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// 题目名称：
// 字符串左旋 
// 题目内容：
// 实现一个函数，可以左旋字符串中的k个字符。例如：
// ABCD左旋一个字符得到BCDA
// ABCD左旋两个字符得到CDAB

//sizeof 有算上\0

//法1
// #include <stdio.h>
// void levorotation(int k, char* p_arr, int sz) {
//     char* p_arr_right = p_arr + sz - 1 - k;
//     while (k--) {
//         char temp = *p_arr;
//         *p_arr = *p_arr_right;
//         *p_arr_right = temp;

//         p_arr++;
//         p_arr_right++;
//     }
// }
// int main() {
//     int k = 0;
//     scanf("%d", &k);
//     char arr[] = "hello world";
//     int sz = sizeof(arr) / sizeof(arr[0]);

//     levorotation(k, arr, sz);

//     printf("%s\n", arr);

//     return 0;
// }

//法2
// #include <stdio.h>
// #include <string.h>
// void levorotation(int k, char arr[]) {
//     int i = 0;
//     int len = strlen(arr);
//     for (i = 0; i < k; i++) {
//         //往后挪一个字符
//         char temp = arr[0];
//         int j = 0;
//         //整体往前
//         // abcdef
//         // 012345
//         // len = 6
//         for (j = 0; j < len - 1; j++) {
//             arr[j] = arr[j + 1];
//         }
//         arr[len - 1] = temp;
//     }
// }
// int main() {
//     int k = 0;
//     scanf("%d", &k);
//     char arr[] = "abcdef";

//     levorotation(k, arr);

//     printf("%s\n", arr);

//     return 0;
// }

//法3
#include <stdio.h>
#include <string.h>
#include <assert.h>
//分开逆序 分成两个部分
// a b c d e f
// a b | c d e f
//两个部分分别逆序
// b a | f e d c
//整体再次逆序
// c d e f a b
void reserve(char* left, char* right) {
    assert(left && right);
    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
    
        left++;
        right--;
    }

}

void levorotation(int k, char* arr) {
    int len = strlen(arr);
    //翻转len个数据相当于没有翻转 所以可以取出余数
    k %= len;
    reserve(arr, arr + k - 1);//左边
    reserve(arr + k, arr + len - 1);//右边
    reserve(arr, arr + len - 1);//整
}

int main() {
    int k = 0;
    scanf("%d", &k);
    char arr[] = "abcdef";

    levorotation(k, arr);

    printf("%s\n", arr);

    return 0;
}


