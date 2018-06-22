/**
 * @Author: lee
 * @Date:   2018-06-22T21:37:37+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-22T21:56:49+08:00
 */

// 最大公约数与最小公倍数

#include <cstdio>

// 求a和b的最大公约数
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int main()
{
    int a[100];
    // temp为零时变量；pos存放当前处理的位置；next为下一个要处理的位置
    int n, m, temp, pos, next;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 修正m，m可能大雨
    m = m % n;
    // m == 0直接输出数组
    if (m != 0) {
        // m和n的最大公约数
        int d = gcd(m, n);
        for (int i = n - m; i < n - m + d; i ++) {
            temp = a[i];
            pos = i;
            do {
                next = (pos - m + n) % n;
                if (next != i) {
                    a[pos] = a[next];
                } else {
                    a[pos] = temp;
                }
                pos = next;
            } while (pos != i);
        }
    }

    for (int i = 0; i < n; i ++) {
        printf("%d", a[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }

    return 0;
}
