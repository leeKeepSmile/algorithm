/**
 * @Author: lee
 * @Date:   2018-05-06T22:09:55+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-06T22:23:36+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    int len, sum = 0, j = 0;
    int res[4] = {0};
    char n[110];
    char a[11][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    scanf("%s", n);
    len = strlen(n);

    for (int i = 0; i < len; i ++) {
        sum += n[i] - 48;
    }

    // 获取和的各位数字
    do {
        res[j ++] = sum % 10;
        sum /= 10;
    } while (sum != 0);

    // 输出结果
    for (int i = j - 1; i >= 0; i --) {
        printf("%s", a[res[i]]);

        if (i != 0) {
            printf(" ");
        }
    }

    return 0;
}
