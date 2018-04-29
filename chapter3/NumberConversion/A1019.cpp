/**
 * @Author: lee
 * @Date:   2018-04-29T22:52:58+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-29T23:16:20+08:00
 */

// 进制转换

#include <cstdio>

int main()
{
    int a[40];
    int n, b, num = 0;
    // 是否是回文，0表示不是，1表示是
    bool isPalindromic = 1;

    scanf("%d%d", &n, &b);

    // 进制转换
    do {
        a[num ++] = n % b;
        n /= b;
    } while (n != 0);

    // 判断是否是回文
    for (int i = 0; i < num / 2; i ++) {
        if (a[i] != a[num - i - 1]) {
            isPalindromic = 0;
            break;
        }
    }

    //输出结果
    isPalindromic ? printf("Yes\n") : printf("No\n");
    for (int i = num - 1; i >= 0; i --) {
        printf("%d", a[i]);

        if (i != 0) {
            printf(" ");
        }
    }

    return 0;
}
