/**
 * @Author: lee
 * @Date:   2018-06-26T15:07:24+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T15:18:25+08:00
 */

// 大整数运算

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

// 讲整数转化为数组
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

    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i --) {
        r = r * 10 + a.d[i];
        // 不够除
        if (r < b) {
            // 则当前位为0
            c.d[i] = 0;
        } else {
            c.d[i] = r / b;
            r = r % b;
        }
    }

    // 去除高位的0，并且至少保留一位最低位
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
    // r为余数
    int b, r = 0;
    scanf("%s%d", str, &b);

    bign a = change(str);
    print(divide(a, b, r));
    printf(" %d\n", r);

    return 0;
}
