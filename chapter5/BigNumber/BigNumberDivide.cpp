/**
 * @Author: lee
 * @Date:   2018-06-26T14:38:31+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T15:00:56+08:00
 */

// 大整数运算-高精度与低精度的除法

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct bign {
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

// 余数
int r = 0;

// 将整数转化为bign
bign change(char str[])
{
    bign a;
    a.len = strlen(str);

    for (int i = 0; i < a.len; i ++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }

    return a;
}

// 高精度除法，r为余数
bign divide(bign a, int b, int& r)
{
    bign c;

    // 被除数的每一位与商的每一位一一对应，所以长度相等
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i --) {
        r = r * 10 + a.d[i];
        // 如果不够除
        if (r < b) {
            // 当前位为0
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }

    // 去除高位的0，同时至少保留一位最低位
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len --;
    }

    return c;
}

// 打印结果
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i --) {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char str[1000];
    int b;
    // str是否为负数
    bool isStrNegative = false;
    scanf("%s%d", str, &b);

    if (str[0] == '-') {
        // str为负数
        isStrNegative = true;
        int len = strlen(str);

        // 去负号
        for (int i = 1; i < len; i ++) {
            str[i - 1] = str[i];
        }
        str[len - 1] = '\0';
    }

    if ( (b < 0 && isStrNegative == false) || (b > 0 && isStrNegative == true) ) {
        printf("-");
    }

    bign a = change(str);
    if (b < 0) {
        b = abs(b);
    }
    print(divide(a, b, r));
    printf("\n");
    // 输出最后的余数
    printf("%d\n", r);

    return 0;
}
