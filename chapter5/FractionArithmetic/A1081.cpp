/**
 * @Author: lee
 * @Date:   2018-06-22T22:27:23+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-22T22:52:08+08:00
 */

// 分数的四则运算

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Fraction {
    LL up, down;
};

// 求a与b的最大公约数
LL gcd(LL a, LL b)
{
    return !b ? a : gcd(b, a % b);
}

// 化简分数
Fraction reduction(Fraction result)
{
    if (result.down < 0) {
        result.down = -result.down;
        result.up = -result. up;
    }

    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }

    return result;
}

// 分数f1加上分数f2
Fraction add(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 输出结果
void showResult(Fraction r)
{
    reduction(r);
    if (r.down == 1) {
        printf("%lld\n", r.up);
    } else if (abs(r.up) > abs(r.down)) {
        // 假分数
        printf("%lld %lld/%lld\n", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        // 真分数
        printf("%lld/%lld\n", r.up, r.down);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Fraction sum, temp;
    sum.up = 0;
    sum.down = 1;
    for (int i = 0; i < n; i ++) {
        scanf("%lld/%lld", &temp.up, &temp.down);
        sum = add(sum, temp);
    }

    showResult(sum);

    return 0;
}
