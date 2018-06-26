/**
 * @Author: lee
 * @Date:   2018-06-26T13:46:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T14:11:57+08:00
 */

// 大整数运算-高精度减法

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

// 高精度 a b
bign sub(bign a, bign b)
{
    bign c;
    for (int i = 0; i < a.len || i < b.len; i ++) {
        // 如果不够减
        if (a.d[i] < b.d[i]) {
            // 向高位借1
            a.d[i + 1] --;
            // 当前位+10
            a.d[i] += 10;
        }
        c.d[c.len ++] = a.d[i] - b.d[i];
    }

    // 去除高位的0，并且至少保留一位最低位
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0) {
        c.len --;
    }

    return c;
}

// 判断两个整数的大小
int compare(bign a, bign b)
{
    if (a.len > b.len) {
        return 1;
    } else if (a.len < b.len) {
        return -1;
    } else {
        for (int i = a.len - 1; i >= 0; i --) {
            // 只要a有一位大，则a大
            if (a.d[i] > b.d[i]) {
                return 1;
            } else if (a.d[i] < b.d[i]) {
                // 只要a有1位小，则a小
                return -1;
            }
        }

        // 两者相等
        return 0;
    }
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

    // 若a比b小，则交换两个数，同时输出'-'号
    if (compare(a, b) < 0) {
        printf("-");

        bign temp;
        temp = a;
        a = b;
        b = temp;
    }

    print(sub(a, b));

    return 0;
}
