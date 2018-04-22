/**
 * @Author: lee
 * @Date:   2018-04-21T16:50:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-22T08:13:25+08:00
 */

// 简单模拟

#include <cstdio>

int main()
{
    int n, m, temp;
    // 总距离
    int totalDistances = 0;
    int dis[100001] = {0};
    int ex[10001][2] = {0};

    scanf("%d", &n);
    // 如果dis[i]只记录Dn，那么最糟糕的情况10^9，肯定会超时
    // 所以dis[i]记录D1~Di的距离总和，注：dis[0] = 0。
    // Exit[i]~Exit[j]的距离可记为sum1，假设Exit[j]>Exit[i]，则记sum1 = D[j - 1] - D[i - 1]，
    // sum2 = totalDistances - sum1，最短距离就是比较sum1和sum2的大小，取最小值。
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &dis[i]);
        // 计算总距离
        totalDistances += dis[i];
        dis[i] = dis[i - 1] + dis[i];
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

        // exit[i][1] 到 exit[i][0]的顺时针距离为 (exit[i][1] - 1) - (exit[i][0] - 1)
        int sum1, sum2;
        sum1 = dis[ex[i][1] - 1] - dis[ex[i][0] - 1];
        sum2 = totalDistances - sum1;

        printf("%d\n", sum1 > sum2 ? sum2 : sum1);
    }

    return 0;
}
