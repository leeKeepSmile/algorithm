/**
 * @Author: lee
 * @Date:   2018-04-22T17:10:57+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-22T19:18:25+08:00
 */

// 简单模拟

#include <cstdio>

int main()
{
    // 系数
    int k;
    // 指数
    int e;
    int a[1001] = {0};
    // 求导后的非零项总数
    int count = 0;

    while (scanf("%d %d", &k, &e) != EOF) {
        a[e] = k;
    }

    // 0次项求导后为0
    a[0] = 0;
    for (int i = 1; i <= 1000; i ++) {
        if (a[i] != 0) {
            a[i - 1] = a[i] * i;
            a[i] = 0;
            if (a[i - 1] != 0) {
                count ++;
            }
        }
    }

    // 特殊情况：常数求导为0，此时要输出0 0
    if (count == 0) {
        printf("0 0");
    } else {
        for (int i = 1000; i >= 0; i --) {
            if (a[i] != 0) {
                printf("%d %d", a[i], i);
                count --;
                if (count != 0) {
                    printf(" ");
                }
            }
        }
    }

    return 0;
}
