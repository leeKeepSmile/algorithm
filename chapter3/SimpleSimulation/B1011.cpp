/**
 * @Author: lee
 * @Date:   2018-04-17T16:38:38+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-17T16:54:56+08:00
 */

// 简单模拟

#include <cstdio>

int main ()
{
    int T;
    long long A, B, C;
    // 用于存储A+B是否>C
    bool a[10] = {0};

    scanf("%d\n", &T);

    for (int i = 0; i < T; i ++) {
        scanf("%lld%lld%lld", &A, &B, &C);
        if (A + B > C) {
            a[i] = 1;
        } else {
            a[i] = 0;
        }
    }

    for (int j = 0; j < T; j ++) {
        if (a[j] == 1) {
            printf("Case #%d: true\n", j + 1);
        } else {
            printf("Case #%d: false\n", j + 1);
        }
    }

    return 0;
}
