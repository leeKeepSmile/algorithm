/**
 * @Author: lee
 * @Date:   2018-04-29T21:58:31+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-29T22:03:42+08:00
 */

// 进制转换

#include <cstdio>

int main()
{
    int a, b, d, num = 0;
    long long sum;
    int res[40];

    scanf("%d%d%d", &a, &b, &d);
    sum = a + b;

    // 进制转换
    do {
        res[num ++] = sum % d;
        sum /= d;
    } while (sum != 0);

    // 输出结果
    for (int i = num - 1; i >= 0; i --) {
        printf("%d", res[i]);
    }

    return 0;
}
