/**
 * @Author: lee
 * @Date:   2018-05-05T21:57:57+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-05T22:07:55+08:00
 */

// 字符串处理

#include <cstdio>

int main()
{
    int n, i = 0;
    int a[3] = {0};
    scanf("%d", &n);

    // 获取各位数字
    do {
        a[i ++] = n % 10;
        n /= 10;
    } while (n != 0);

    // 输出结果
    for (int j = 0; j < a[2]; j ++) {
        printf("B");
    }
    for (int j = 0; j < a[1]; j ++) {
        printf("S");
    }
    for (int j = 1; j <= a[0]; j ++) {
        printf("%d", j);
    }

    return 0;
}
