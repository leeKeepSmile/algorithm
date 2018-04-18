/**
 * @Author: lee
 * @Date:   2018-04-18T17:54:11+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-18T18:13:23+08:00
 */

// 简单模拟

#include <cstdio>

int main ()
{
    int n, temp;
    // 每个规则下对应数据的个数
    int count[5] = {0};
    // 每个规则对应的结果集
    int ans[5] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &temp);

        if (temp % 5 == 0) {
            if (temp % 2 == 0) {
                count[0] ++;
                ans[0] += temp;
            }
        } else if (temp % 5 == 1) {
            count[1] ++;
            count[1] % 2 == 0 ? ans[1] -= temp : ans[1] += temp;
        } else if (temp % 5 == 2) {
            count[2] ++;
            ans[2] ++;
        } else if (temp % 5 == 3) {
            count[3] ++;
            ans[3] += temp;
        } else {
            if (ans[4] < temp) {
                ans[4] = temp;
            }

            count[4] ++;
        }
    }

    count[0] ? printf("%d ", ans[0]) : printf("N ");
    count[1] ? printf("%d ", ans[1]) : printf("N ");
    count[2] ? printf("%d ", ans[2]) : printf("N ");
    count[3] ? printf("%.1f ", ans[3] / (float)count[3]) : printf("N ");
    count[4] ? printf("%d", ans[4]) : printf("N");

    return 0;
}
