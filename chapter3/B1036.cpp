/**
 * @Author: lee
 * @Date:   2018-04-14T17:36:16+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-14T18:05:23+08:00
 */

#include <cstdio>
#include <cmath>

int main()
{
    int n;
    char c;
    // 行数
    int rawNum = 0;
    scanf("%d %c", &n, &c);

    // 行数等于列数的50%
    rawNum = round((double)(n / 2.0));

    // 格式化输出
    for (int i = 0; i < rawNum; i ++) {
        if (i == 0 || i == rawNum - 1) {
            for (int j = 0; j < n; j ++) {
                printf("%c", c);
            }
        } else {
            for (int j = 0; j < n; j ++) {
                if (j == 0 || j == n - 1) {
                    printf("%c", c);
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
