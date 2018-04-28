/**
 * @Author: lee
 * @Date:   2018-04-26T22:58:10+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-28T23:16:09+08:00
 */

// 图形输出

// 注意：以下算法需要将二维数组a全部赋值为空格，若没有全部赋值为空格，而是在最后
// 输出的时候输出空格，则所有的测试点都不能通过。

#include <cstdio>
#include <cstring>

int main()
{
    int n1, n2, len, j = 0;
    char str[100];
    char a[40][40];

    scanf("%s", str);
    len = strlen(str);
    // n1 = n3, n2 = len - 2 * n1 + 2
    n1 = (len + 2) / 3;
    n2 = len - 2 * n1 + 2;

    // 将二维数组全部赋值为空格
    for (int m = 0; m < n1; m ++) {
        for (int n = 0; n < n2; n ++) {
            a[m][n] = ' ';
        }
    }

    // 将字符串的每个字符依次录入数组
    for (int i = 0; i < n1; i ++) {
        a[i][0] = str[j ++];
    }
    for (int i = 1; i < n2 - 1; i ++) {
        a[n1 - 1][i] = str[j ++];
    }
    for (int i = n1 - 1; i >= 0; i --) {
        a[i][n2 - 1] = str[j ++];
    }

    // 输出整个二维数组
    for (int m = 0; m < n1; m ++) {
        for (int n = 0; n < n2; n ++) {
            printf("%c", a[m][n]);
        }

        printf("\n");
    }

    return 0;
}
