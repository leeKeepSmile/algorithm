/**
 * @Author: lee
 * @Date:   2018-06-26T14:13:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T14:37:03+08:00
 */

// 大整数运算-高精度与低精度的乘法

#include <cstdio>
#include <cstring>

struct bign {
    int d[1000];
    int len;

    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

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

// 高精度乘法
bign multi(bign a, int b)
{
    bign c;
    // 进位
    int carry = 0;

    for (int i = 0; i < a.len; i ++) {
        int temp = a.d[i] * b + carry;
        c.d[c.len ++] = temp % 10;
        carry = temp / 10;
    }

    while (carry != 0) {
        c.d[c.len ++] = carry % 10;
        carry /= 10;
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
    scanf("%s%d", str, &b);
    bign a = change(str);
    print(multi(a, b));

    return 0;
}
