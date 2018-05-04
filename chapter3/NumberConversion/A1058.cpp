/**
 * @Author: lee
 * @Date:   2018-05-04T22:56:00+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-04T23:23:59+08:00
 */

// 进制转换

// 注意点：如果a1,a2,a3,b1,b2,b3为int型，那么有一个测试点会答案错误，可能是溢出造成的。
// 将所有的int型都换成long long型，即可全部通过测试。

#include <cstdio>

// 1 Galleon = 17 * 29 Knuts
const int Galleon = 17 * 29;
// 1 Sickle = 29 Knuts
const int Sickle = 29;

int main()
{
    long a1, a2, a3;
    long b1, b2, b3;
    long long temp1, temp2, sum;

    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &a2, &a3, &b1, &b2, &b3);
    temp1 = a1 * Galleon + a2 * Sickle + a3;
    temp2 = b1 * Galleon + b2 * Sickle + b3;
    sum = temp1 + temp2;

    printf("%lld.%lld.%lld", sum / Galleon, sum % Galleon / Sickle, sum % Sickle);

    return 0;
}
