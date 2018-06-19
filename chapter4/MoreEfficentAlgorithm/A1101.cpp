/**
 * @Author: lee
 * @Date:   2018-06-19T20:52:22+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-19T20:52:24+08:00
 */

 // 其他高效技巧与算法

 #include <cstdio>
 #include <algorithm>

 using namespace std;

 const int MAX_N = 100010;
 // 一个很大的数
 const int INF = 0x3fffffff;

 // num为主元个数
 int n, num = 0;
 // leftMax数组记录每一位左边最大的数；rightMin数组记录每一位右边最小的数；ans记录所有主元。
 int a[MAX_N], leftMax[MAX_N], rightMin[MAX_N], ans[MAX_N];

 int main()
 {
     scanf("%d", &n);
     for (int i = 0; i < n; i ++) {
         scanf("%d", &a[i]);
     }

     // a[0]左边没有比他大的数字
     leftMax[0] = 0;
     for (int i = 1; i < n; i ++) {
         leftMax[i] = max(leftMax[i - 1], a[i - 1]);
     }

     // rightMin[n - 1]右边没有比他小的数
     rightMin[n - 1] = INF;
     for (int i = n - 2; i >= 0; i --) {
         rightMin[i] = min(rightMin[i + 1], a[i + 1]);
     }

     for (int i = 0; i < n; i ++) {
         // 左边的所有数比他小，右边的所有数比他大
         if (leftMax[i] < a[i] && rightMin[i] > a[i]) {
             // 记录主元
             ans[num ++] = a[i];
         }
     }

     printf("%d\n", num);
     for (int i = 0; i < num; i ++) {
         printf("%d", ans[i]);

         if (i < num - 1) {
             printf(" ");
         }
     }

     // 必须要有换行，当主元数为0时，也要输出换行
     printf("\n");

     return 0;
 }
