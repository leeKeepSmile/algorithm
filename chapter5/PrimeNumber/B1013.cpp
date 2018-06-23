/**
 * @Author: lee
 * @Date:   2018-06-23T15:04:27+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-23T15:17:24+08:00
 */

// 素数

#include <cstdio>

const int MAX_N = 1000001;

int prime[MAX_N], num = 0;
// 如果i为素数，那么p[i]为false;否则，p[i]为true。
bool p[MAX_N] = {0};

void findPrime(int n)
{
    for (int i = 2; i < MAX_N; i ++) {
        if (p[i] == false) {
            prime[num ++] = i;
            // 只需要n个素数
            if (num >= n) {
                break;
            }
            for (int j = i + i; j < MAX_N; j += i) {
                p[j] = true;
            }
        }
    }
}

int main()
{
    int m, n, count = 0;

    scanf("%d%d", &m, &n);

    findPrime(n);
    for (int i = m; i <= n; i ++) {
        // 下标是从0开始的
        printf("%d", prime[i - 1]);
        count ++;

        if (count % 10 != 0 && i < n) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
