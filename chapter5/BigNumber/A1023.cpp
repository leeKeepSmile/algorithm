/**
 * @Author: lee
 * @Date:   2018-06-26T16:09:34+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-26T16:22:56+08:00
 */

// 大整数运算

#include <cstdio>
#include <cstring>

struct bign {
    int d[21];
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
bign multi(bign a, int b) {
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

// 判断b是否为a的某个排列
bool judge(bign a, bign b)
{
    // 长度不同，肯定不为某个排列
    if (a.len != b.len) {
        return false;
    } else {
        int count[10] = {0};

        for (int i = 0; i < a.len; i ++) {
            count[a.d[i]] ++;
            count[b.d[i]] --;
        }

        for (int i = 0; i < 10; i ++) {
            if (count[i] != 0) {
                return false;
            }
        }
    }

    return true;
}

// 输出结果
void print(bign a)
{
    for (int i = a.len - 1; i >= 0; i --) {
        printf("%d", a.d[i]);
    }
}

int main()
{
    char str[21];
    scanf("%s", str);

    bign a = change(str);
    bign mul = multi(a, 2);

    if (judge(a, mul) == true) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    print(mul);

    return 0;
}
