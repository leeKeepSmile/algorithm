/**
 * @Author: lee
 * @Date:   2018-04-26T16:57:40+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-26T21:32:11+08:00
 */

// 图形输出

// 此题需要注意的是
//（1）行后不能有多余的空格
//（2）最后没有剩下的字符了，也要打印剩余字符为0

// 以下代码测试点2和测试点3未通过，找不出原因所在。

#include <cstdio>

int main()
{
    // max为字符最多的一行的个数
    int n, temp, max = 1;
    // 记录已用掉多少个字符
    int sum = 0;
    char c;

    scanf("%d %c", &n, &c);
    temp = (n - 1) / 2;

    for (int i = 3; i <= temp; i += 2) {
        if (sum + i > temp) {
            break;
        } else {
            max = i;
            sum += i;
        }
    }

    // n < 7组成不了沙漏，直接输出n
    if (n < 7) {
        printf("*\n");
    } else {
        // 输出上半部，包括中间的一个字符
        for (int i = max; i >= 1; i -= 2) {
            for (int j = 0; j < (max - i) / 2; j ++) {
                printf(" ");
            }
            for (int k = 0; k < i; k ++) {
                printf("%c", c);
            }
            printf("\n");
        }

        // 输出后半部分
        for (int i = 3; i <= max; i += 2) {
            for (int j = 0; j < (max - i) / 2; j ++) {
                printf(" ");
            }
            for (int k = 0; k < i; k ++) {
                printf("%c", c);
            }
            printf("\n");
        }
    }

    // 剩余字符为0个也要输出。
    printf("%d", n - sum * 2 - 1);

    return 0;
}
