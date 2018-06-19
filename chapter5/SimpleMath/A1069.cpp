/**
 * @Author: lee
 * @Date:   2018-06-19T21:18:43+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-19T21:18:47+08:00
 */

 // 简单数学

 #include <cstdio>
 #include <algorithm>

 using namespace std;

 // 从大到小排序
 bool cmp(int a, int b)
 {
     return a > b;
 }

 // 将n的每一位存到数组中
 void toArray(int n, int num[])
 {
     for (int i = 0; i < 4; i ++) {
         num[i] = n % 10;
         n /= 10;
     }
 }

 // 将num数组转化为数字
 int toNumber(int num[])
 {
     int sum = 0;

     for (int i = 0; i < 4; i ++) {
         sum = sum * 10 + num[i];
     }

     return sum;
 }

 int main()
 {
     int n, max, min;
     int num[5];

     scanf("%d", &n);
     while (1) {
         toArray(n, num);
         // 从小到大排序
         sort(num, num + 4);
         min = toNumber(num);
         // 从大到小排序
         sort(num, num + 4, cmp);
         max = toNumber(num);
         n = max - min;

         printf("%04d - %04d = %04d\n", max, min, n);

         // 如果n为0或者6174则跳出循环
         if (n == 0 || n == 6174) {
             break;
         }
     }

     return 0;
 }
