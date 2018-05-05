/**
 * @Author: lee
 * @Date:   2018-05-05T21:41:54+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-05T21:54:52+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    int i = 0;
    char str[81][81];

    while (scanf("%s", str[i]) != EOF) {
        i ++;
    }

    for (int j = i - 1; j >= 0; j --) {
        printf("%s", str[j]);

        if (j != 0) {
            printf(" ");
        }
    }

    return 0;
}
