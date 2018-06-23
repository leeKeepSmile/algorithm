/**
 * @Author: lee
 * @Date:   2018-06-23T15:21:53+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-23T15:27:18+08:00
 */

// 素数

#include <cstdio>
#include <cmath>

// 判断n是否为素数
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
    int n, count = 0;

    scanf("%d", &n);

    for (int i = 3; i + 2 <= n; i += 2) {
        if (isPrime(i) == true && isPrime(i + 2) == true) {
            count ++;
        }
    }

    printf("%d\n", count);

    return 0;
}
