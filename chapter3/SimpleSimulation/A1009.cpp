/**
 * @Author: lee
 * @Date:   2018-04-23T17:17:06+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-23T19:34:20+08:00
 */

// 简单模拟

#include <cstdio>

const int MAX = 1001;
const int RES_MAX = 2001;

int main()
{
    int k, e, count = 0;
    double val;
    double a[MAX] = {0};
    double b[MAX] = {0};
    double res[RES_MAX] = {0};

    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        scanf("%d %lf", &e, &val);
        a[e] = val;
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        scanf("%d %lf", &e, &val);
        b[e] = val;
    }

    for (int i = 0; i < MAX; i ++) {
        if (a[i] != 0) {
            for (int j = 0; j < MAX; j ++) {
                if (b[j] != 0) {
                    // 加前，若res[i + j] == 0，count++
                    if (res[i + j] == 0) {
                        count ++;
                    }
                    res[i + j] += a[i] * b[j];
                    // 加后，若res[i + j] == 0并且count不为0，count--
                    if (res[i + j] == 0 && count != 0) {
                        count --;
                    }
                }
            }
        }
    }

    printf("%d", count);
    for (int i = RES_MAX - 1; i >= 0; i --) {
        if (res[i] != 0) {
            printf(" %d %.1f", i, res[i]);
            count --;
        }
    }

    return 0;
}
