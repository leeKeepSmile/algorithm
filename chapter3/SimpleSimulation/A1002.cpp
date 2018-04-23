/**
 * @Author: lee
 * @Date:   2018-04-23T16:49:01+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-23T17:13:08+08:00
 */

// 简单模拟

// 注意点：当count=0时，注意输出count后，其后再有空格，否则会报格式错误。

#include <cstdio>
#include <cmath>

// 用于浮点数比较
const double eps = 1e-8;

int main()
{
    int k;
    float a[1001] = {0};
    float b[1001] = {0};
    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        int e;
        float k;
        scanf("%d %f", &e, &k);
        a[e] = k;
    }

    getchar();
    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        int e;
        float k;
        scanf("%d %f", &e, &k);
        b[e] = k;
    }

    int count = 0;
    float res[1001] = {0};
    for (int i = 0; i <= 1000; i ++) {
        if (fabs(a[i]) > eps || fabs(b[i]) > eps) {
            res[i] = a[i] + b[i];

            if (fabs(res[i]) > eps) {
                count ++;
            }
        }
    }

    printf("%d", count);
    // 如果count = 0，那么不输出空格
    if (count != 0) {
        printf(" ");
    }
    for (int i = 1000; i >= 0; i --) {
        if (fabs(res[i]) > eps) {
            printf("%d %.1f", i, res[i]);
            count --;

            if (count != 0) {
                printf(" ");
            }
        }
    }

    return 0;
}
