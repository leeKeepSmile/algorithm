/**
 * @Author: lee
 * @Date:   2018-06-26T13:46:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T14:30:46+08:00
 */

// 大整数运算-高精度加法

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

// 高精度 a+b
bign add(bign a, bign b)
{
    bign c;
    // 进位
    int carry = 0;

    for (int i = 0; i < a.len || i < b.len; i ++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len ++] = temp % 10;
        carry = temp / 10;
    }

    if (carry != 0) {
        c.d[c.len ++] = carry;
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
    char str1[1000], str2[1000];
    scanf("%s%s", str1, str2);
    bign a = change(str1);
    bign b = change(str2);
    print(add(a, b));

    return 0;
}
