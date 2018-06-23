/**
 * @Author: lee
 * @Date:   2018-06-23T14:14:45+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-23T14:35:50+08:00
 */

// 分数的四则运算

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Fraction {
    ll up, down;
}a, b;

// 求a和b的最大公约数
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// 化简
Fraction reduction(Fraction result)
{
    if (result.down < 0) {
        result.down = -result.down;
        result.up = -result.up;
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

// 加
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 减
Fraction minus(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 乘
Fraction multi(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;

    return reduction(result);
}

// 除
Fraction divide(Fraction f1, Fraction f2)
{
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;

    return reduction(result);
}

// 输出分数r
void showResult(Fraction r)
{
    r = reduction(r);
    if (r.up < 0) {
        printf("(");
    }
    if (r.down == 1) {
        printf("%lld", r.up);
    } else if (abs(r.up) > r.down) {
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        printf("%lld/%lld", r.up, r.down);
    }
    if (r.up < 0) {
        printf(")");
    }
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

    // 加法
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");

    // 减法
    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minus(a, b));
    printf("\n");

    // 乘法
    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a, b));
    printf("\n");

    // 除法
    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if (b.up == 0) {
        printf("Inf");
    } else {
        showResult(divide(a, b));
    }

    return 0;
}
