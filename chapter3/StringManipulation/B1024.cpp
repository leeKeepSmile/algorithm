/**
 * @Author: lee
 * @Date:   2018-05-06T22:56:22+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-07T10:53:59+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    char a[10010] = {'\0'};
    int pointPos, ePos, len, carry = 0;
    // E后的符号
    char op;

    scanf("%s", a);
    // 输出符号位
    if (a[0] == '-') {
        printf("-");
    }
    len = strlen(a);

    for (int i = 1; i < len; i ++) {
        if (a[i] == '.') {
            pointPos = i;
        }

        if (a[i] == 'E') {
            ePos = i;
        }

        if (a[i - 1] == 'E') {
            op = a[i];
        }
    }

    // 获取指数
    int temp = 1;
    for (int i = len - 1; i >= ePos + 2; i --) {
        carry += (a[i] - '0') * temp;
        temp *= 10;
    }

    // 如果指数为正
    if (op == '+') {
        for (int i = 1; i < ePos; i ++) {
            if (a[i] == '.') {
                continue;
            }

            // 将小数点放在合适的位置
            if (ePos - pointPos - 1 > carry) {
                if (i == pointPos + carry + 1) {
                    printf(".");
                }
            }

            printf("%c", a[i]);
        }
        // 进位比较多时，后面全跟0
        if (ePos - pointPos - 1 <= carry) {
            for (int i = 0; i < carry - ePos + pointPos + 1; i ++) {
                printf("0");
            }
        }
    } else {
        // 当指数为负时，输出如下
        printf("0.");
        for (int i = 0; i < carry - 1; i ++) {
            printf("0");
        }
        for (int i = 1; i < ePos; i ++) {
            if (a[i] == '.') {
                continue;
            }

            printf("%c", a[i]);
        }
    }

    return 0;
}
