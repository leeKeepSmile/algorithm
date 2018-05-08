/**
 * @Author: lee
 * @Date:   2018-05-08T22:36:21+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-08T22:51:36+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    int sum = 0, j = 0;
    char n[110];
    int res[110] = {0};
    // 数字英文字母数组
    char en[10][6] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    scanf("%s", n);
    int len = strlen(n);

    // 计算各位数字和
    for (int i = 0; i < len; i ++) {
        sum += n[i] - '0';
    }

    // 从后往前获取每一位数字
    do {
        res[j ++] = sum % 10;
        sum /= 10;
    } while (sum != 0);

    for (int i = j - 1; i >= 0; i --) {
        printf("%s", en[res[i]]);

        if (i > 0) {
            printf(" ");
        }
    }

    return 0;
}
