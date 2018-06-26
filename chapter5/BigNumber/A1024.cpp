/**
 * @Author: lee
 * @Date:   2018-06-26T16:28:48+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T16:52:17+08:00
 */

// 大整数运算

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

// 讲整数转化为bign
bign change(char str[])
{
    bign a;
    a.len = strlen(str);

    for (int i = 0; i < a.len; i ++) {
        a.d[i] = str[a.len - i - 1] - '0';
    }

    return a;
}

// 高精度加法
bign add(bign a, bign b)
{
    bign c;
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

// 判断是否为回文数字
bool judge(bign a)
{
    for (int i = 0; i <= a.len / 2; i ++) {
        if (a.d[i] != a.d[a.len - i - 1]) {
            return false;
        }
    }

    return true;
}

// 输出大整数
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i --) {
        printf("%d", a.d[i]);
    }

    printf("\n");
}

int main()
{
    char str1[1000];
    // t为操作上线，k为当前操作次数
    int t, k = 0;

    scanf("%s%d", str1, &t);

    bign a = change(str1);
    // 不超过上限次数，且a非回文数
    while (k < t && judge(a) == false) {
        bign b = a;
        reverse(b.d, b.d + b.len);
        a = add(a, b);
        k ++;
    }

    print(a);
    printf("%d\n", k);

    return 0;
}
