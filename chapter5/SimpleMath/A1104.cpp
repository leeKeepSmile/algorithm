/**
 * @Author: lee
 * @Date:   2018-06-20T17:32:19+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-20T17:32:22+08:00
 */

 // 简单数学

 // 思路：第i个数出现的次数等于i * (n + 1 - i)

 #include <cstdio>

 int main()
 {
     int n;
     double v, ans = 0;

     scanf("%d", &n);

     for (int i = 1; i <= n; i ++) {
         scanf("%lf", &v);
         ans += v * i * (n + 1 - i);
     }

     printf("%.2f\n", ans);
 }
