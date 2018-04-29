/**
 * @Author: lee
 * @Date:   2018-04-29T22:08:37+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-29T22:50:16+08:00
 */

// 进制转换

// 本题思路是将钱转换为最小单位（Knut），然后再做差值，最后再转换为
// Galleon.Sickle.Knut的形式。
// 与将二进制转换为八进制一样，先将二进制转换为十进制，再将十进制数
// 转换为八进制数。

#include <cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

struct money{
    int g;
    int s;
    int k;
}forPay, paid, change;

int main()
{
    scanf("%d.%d.%d", &forPay.g, &forPay.s, &forPay.k);
    scanf("%d.%d.%d", &paid.g, &paid.s, &paid.k);

    int k1, k2, changeK;
    // 将钱都转换为纳特（Knut）
    k1 = forPay.g * Galleon + forPay.s * Sickle + forPay.k;
    k2 = paid.g * Galleon + paid.s * Sickle + paid.k;
    changeK = k2 - k1;

    // 若changeK<0，则转换为正数进行计算，并在最前面打印负号
    if (changeK < 0) {
        printf("-");
        changeK = -changeK;
    }

    printf("%d.%d.%d", changeK / Galleon, changeK % Galleon / Sickle, changeK % Sickle);

    return 0;
}
