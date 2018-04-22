/**
 * @Author: lee
 * @Date:   2018-04-22T16:05:47+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-22T17:05:16+08:00
 */

// 简单模拟

// 如果该题给出的a和b的值为2^63，则以下方法会出错
// 一下算法针对[-2^63, 2^63)有效

#include <cstdio>

int main()
{
    int t;
    // 编号
    int num = 1;
    scanf("%d", &t);

    while (t --) {
        getchar();

        // flag = true表示A+B>C，否则反之
        int flag;
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        long sum = a + b;

        // 计算机组成原理中指出，如果两个正数和等于负数或是两个负数之和等于正数，那么就是溢出。
        // 正溢出后的值区间为[-2^63, -2], 负溢出后的值区间为[0, 2^63)
        // a > 0 && b > 0 && a + b < 0 为正溢出，true
        // a < 0 && b < 0 && a + b >= 0 为负溢出，false
        if (a > 0 && b > 0 && sum < 0) {
            flag = true;
        } else if (a < 0 && b < 0 && sum >= 0) {
            flag = false;
        } else if (sum > c) {
            flag = true;
        } else {
            flag = false;
        }

        if (flag == true) {
            printf("Case #%d: true\n", num ++);
        } else {
            printf("Case #%d: false\n", num ++);
        }
    }

    return 0;
}
