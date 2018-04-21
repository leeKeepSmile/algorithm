/**
 * @Author: lee
 * @Date:   2018-04-21T16:50:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-21T23:25:19+08:00
 */

// 简单模拟

// 以下代码运行超时

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

        // 选择最短的路径求和
        if (ex[i][1] - ex[i][0] <= n / 2) {
            for (int j = ex[i][0]; j < ex[i][1]; j ++) {
                sum1 += dis[j];
            }
        } else {
            for (int j = 1; j < ex[i][0]; j ++) {
                sum1 += dis[j];
            }
            for (int j = ex[i][1]; j <= n; j ++) {
                sum1 += dis[j];
            }
        }

        sum2 = totalDistances - sum1;

        printf("%d\n", sum1 > sum2 ? sum2 : sum1);
    }

    return 0;
}
