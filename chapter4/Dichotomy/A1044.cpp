/**
 * @Author: lee
 * @Date:   2018-06-12T12:38:28+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-12T16:43:13+08:00
 */

// 贪心

#include <cstdio>

const int MAX_N = 100010;

int sum[MAX_N];

// 返回[left, right)内第一个比x大的数所在的位置
int upperBound(int left, int right, int x)
{
    int mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (sum[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main()
{
    // nearM为最接近m的值
    int n, m, nearM = 100000010;

    // 初始化sum[0] = 0
    sum[0] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }

    for (int i = 1; i <= n; i ++) {
        int j = upperBound(i, n + 1, sum[i - 1] + m);

        // Di + ... + Dj = M
        if (sum[j - 1] - sum[i - 1] == m) {
            // 此时最接近m的值是其本身
            nearM = m;
            break;
        } else if (j <= n && sum[j] - sum[i - 1] < nearM) {
            // 更新nearM，最后的nearM即为
            nearM = sum[j] - sum[i - 1];
        }
    }

    for (int i = 1; i <= n; i ++) {
        // 找出第一个比nearM大的位置
        int j = upperBound(i, n + 1, sum[i - 1] + nearM);

        if (sum[j - 1] - sum[i - 1] == nearM) {
            printf("%d-%d\n", i, j - 1);
        }
    }

    return 0;
}
