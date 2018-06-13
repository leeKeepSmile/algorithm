/**
 * @Author: lee
 * @Date:   2018-06-13T22:53:56+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-13T22:54:04+08:00
 */

 // 活用递推

 #include <cstdio>
 #include <cstring>

 const int MAX_LEN = 100010;
 const int MOD = 1000000007;

 char str[MAX_LEN];
 // A左边P的个数
 int leftNumP[MAX_LEN] = {0};

 int main()
 {
     scanf("%s", str);
     // 字符串长度
     int len = strlen(str);

     // 统计A左边P的个数，leftNumP数组表示当前位之前（包括当前位）有多少个P。
     for (int i = 0; i < len; i ++) {
         // 如果不是0位，则继承前一位的结果
         if (i > 0) {
             leftNumP[i] = leftNumP[i - 1];
         }

         // 遇到P，++
         if (str[i] == 'P') {
             leftNumP[i] ++;
         }
     }

     int ans = 0, rightNumT = 0;
     for (int i = len - 1; i >= 0; i --) {
         // 如果当前字符是T，则T的个数++
         if (str[i] == 'T') {
             rightNumT ++;
         } else if (str[i] == 'A') {
             ans = (ans + leftNumP[i] * rightNumT) % MOD;
         }
     }

     printf("%d\n", ans);

     return 0;
 }
