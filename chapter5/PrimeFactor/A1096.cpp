/**
 * @Author: lee
 * @Date:   2018-06-24T14:39:23+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-24T14:47:15+08:00
 */

// 质因子分解

#include <cstdio>
#include <cmath>

typedef long long ll;

int main()
{
    ll n, ansI = 0, ansLen = 0;

    scanf("%lld", &n);

    int sqr = (int)sqrt(1.0 * n);
    for (ll i = 2; i <= sqr; i ++) {
        ll temp = 1, j = i;

        while (1) {
            // 连续整数的乘积
            temp *= j;
            if (n % temp != 0) {
                break;
            }

            if (j - i + 1 > ansLen) {
                ansI = i;
                ansLen = j - i + 1;
            }

            // j ++，下一个整数
            j ++;
        }
    }

    // 最大长度为0，说明根号n范围内无解，则输出n本身
    if (ansLen == 0) {
        printf("1\n%lld\n", n);
    } else {
        printf("%lld\n", ansLen);

        for (ll i = 0; i < ansLen; i ++) {
            printf("%lld", ansI + i);
            if(i < ansLen - 1) {
                printf("*");
            }
        }
    }

    return 0;
}
