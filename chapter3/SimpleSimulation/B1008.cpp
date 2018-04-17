/**
 * @Author: lee
 * @Date:   2018-04-17T17:47:16+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-17T20:17:49+08:00
 */

// 简单模拟

// 注意点：右移m位，m可能大于整数的个数，即m>n的情况。

#include <cstdio>

int main()
{
    int a[100] = {0};
    int n, m, temp;
    scanf("%d%d", &n, &m);

    // 将数据录入数组
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 如果m>n，则取余
    if (m > n) {
        m = m % n;
    }

    // 不移动数据，只循环输出数据，向右移m位，就相当于从(n - m)位开始输出到最后，
    // 再从第一位输出到(n - m)的前一位。
    for (int i = n - m; i < n; i ++) {
        printf("%d", a[i]);

        if (!(n == m && i == n - 1)) {
            printf(" ");
        }
    }

    for (int i = 0; i < n - m; i ++) {
        printf("%d", a[i]);

        if (i != n - m - 1) {
            printf(" ");
        }
    }

    return 0;
}
