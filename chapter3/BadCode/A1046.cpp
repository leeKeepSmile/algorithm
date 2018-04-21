/**
 * @Author: lee
 * @Date:   2018-04-21T16:50:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-21T19:51:44+08:00
 */

// 简单模拟

// 以下代码最后一个测试点超时，需优化算法。

#include <cstdio>

int main()
{
    int n, m, temp;
    // 总距离
    int totalDistances = 0;
    int dis[100001] = {0};
    int ex[10001][2] = {0};

    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &dis[i]);
        totalDistances += dis[i];
    }

    getchar();
    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        getchar();
        scanf("%d %d", &ex[i][0], &ex[i][1]);
    }

    for (int i = 0; i < m; i ++) {
        // 保证ex[i][0] > ex[i][1]
        if (ex[i][0] > ex[i][1]) {
            temp = ex[i][0];
            ex[i][0] = ex[i][1];
            ex[i][1] = temp;
        }

        int sum1, sum2;
        sum1 = sum2 = 0;
        for (int j = ex[i][0]; j < ex[i][1]; j ++) {
            sum1 += dis[j];
        }

        sum2 = totalDistances - sum1;

        printf("%d\n", sum1 > sum2 ? sum2 : sum1);
    }

    return 0;
}
