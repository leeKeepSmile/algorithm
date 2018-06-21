/**
 * @Author: lee
 * @Date:   2018-06-20T17:55:40+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-21T23:03:08+08:00
 */

// 简单数学

#include <cstdio>

int main()
{
    int n, a = 1, ans = 0;
    int left, right, now;

    scanf("%d", &n);
    while (n / a != 0) {
        left = n / (a * 10);
        now = n / a % 10;
        right = n % a;

        if (now == 0) {
            ans += left * a;
        } else if (now == 1) {
            ans += left * a + right + 1;
        } else {
            ans += (left + 1) * a;
        }

        a *= 10;
    }

    printf("%d\n", ans);

    return 0;
}
