/**
 * @Author: lee
 * @Date:   2018-04-17T17:35:56+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-17T17:45:53+08:00
 */

// 简单模拟

#include <cstdio>

int main()
{
    int N;
    int sum1, sum2;
    sum1 = sum2 = 0;
    scanf("%d", &N);

    while (N --) {
        int han1, hua1, han2, hua2;
        scanf("%d%d%d%d", &han1, &hua1, &han2, &hua2);

        // 同赢则继续下一轮
        if (hua1 == han1 + han2 && hua2 == han1 + han2) {
            continue;
        }

        if (hua1 == han1 + han2) {
            sum2 ++;
        }

        if (hua2 == han1 + han2) {
            sum1 ++;
        }
    }

    printf("%d %d\n", sum1, sum2);

    return 0;
}
