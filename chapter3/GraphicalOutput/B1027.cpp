/**
 * @Author: lee
 * @Date:   2018-04-26T16:57:40+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-26T22:23:59+08:00
 */

// 图形输出

// 此题需要注意的是
//（1）行后不能有多余的空格
//（2）最后没有剩下的字符了，也要打印剩余字符为0

#include <cstdio>
#include <cmath>

int main()
{
    int n, max = 1, sum = 0;
    char c;

    scanf("%d %c", &n, &c);

    for (int i = 1; ; i += 2) {
        if (sum + i > (n + 1) / 2) {
            break;
        }

        sum += i;
        max = i;
    }

    // 空格数
    int j = 0;
    for (int i = max; i >= 1; i -= 2) {
        for (int k = 0; k < j; k ++) {
            printf(" ");
        }
        for (int k = 0; k < i; k ++) {
            printf("%c", c);
        }
        // 空格数+1
        j ++;
        printf("\n");
    }

    // 空格数-2
    j -= 2;
    for (int i = 3; i <= max; i += 2) {
        for (int k = 0; k < j; k ++) {
            printf(" ");
        }
        for (int k = 0; k < i; k ++) {
            printf("%c", c);
        }
        // 空格数-1
        j --;
        printf("\n");
    }

    printf("%d", n - sum * 2 + 1);
}
