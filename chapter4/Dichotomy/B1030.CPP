/**
 * @Author: lee
 * @Date:   2018-06-10T22:04:10+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-10T23:03:26+08:00
 */

// 二分

// 注意点：如果(long long)a[i] * p 写成 (long long)(a[i] * p)，则最后一个测试点未通过。

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int n, p, a[MAX_N];

// 二分法，找到第一个大于x的数所在数组的位置
int binarySearch(int i, long long x)
{
    // 如果所有数都不大于x，则直接返回n
    if (a[n - 1] <= x) {
        return n;
    }

    int left = i + 1, right = n - 1, mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 最大长度，初值为1，至少有一个数
    int ans = 1;
    // 从小到大排序
    sort(a, a + n);
    for (int i = 0; i < n; i ++) {
        int j = binarySearch(i, (long long)a[i] * p);
        ans = max(ans, j - i);
    }

    printf("%d\n", ans);

    return 0;
}
