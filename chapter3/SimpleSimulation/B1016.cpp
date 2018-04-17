/**
 * @Author: lee
 * @Date:   2018-04-17T16:56:40+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-17T17:11:37+08:00
 */

// 简单模拟

#include <cstdio>

// 获取新整数PA,PB
long long getP(long long N, int DN)
{
    int temp;
    long long P = 0;

    while (N) {
        temp = N % 10;
        if (temp == DN) {
            P = P * 10 + temp;
        }
        N /= 10;
    }

    return P;
}

int main()
{
    int DA, DB;
    long long A, B;

    scanf("%lld%d%lld%d", &A, &DA, &B, &DB);

    printf("%lld\n", getP(A, DA) + getP(B, DB));

    return 0;
}
