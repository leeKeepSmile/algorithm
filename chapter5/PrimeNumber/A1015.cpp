/**
 * @Author: lee
 * @Date:   2018-06-23T15:30:04+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-23T15:40:53+08:00
 */

// 素数

#include <cstdio>
#include <cmath>

// 判断n是否是素数
bool isPrime(int n)
{
    if (n <= 1) {
        return false;
    }

    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i ++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int d[111];
    int n, radix;

    while (scanf("%d", &n) != EOF) {
        // 遇到负数则退出
        if (n < 0) {
            break;
        }

        scanf("%d", &radix);

        if (isPrime(n) == false) {
            printf("No\n");
        } else {
            int len = 0;
            do {
                d[len ++] = n % radix;
                n /= radix;
            } while (n != 0);

            // 按逆序转换进制
            for (int i = 0; i < len; i ++) {
                n = n * radix + d[i];
            }

            if (isPrime(n) == true) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
