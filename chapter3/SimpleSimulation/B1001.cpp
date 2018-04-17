/**
 * @Author: lee
 * @Date:   2018-04-12T20:54:11+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-15T16:03:39+08:00
 */

// 注意n=1的情况，步数为0；
// 如果用do{}while(); n=1的情况会出现错误。

// 简单模拟

#include <stdio.h>

int main()
{
    int n;
    int step = 0;

    scanf("%d", &n);

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        step ++;
    }

    printf("%d", step);

    return 0;
}
