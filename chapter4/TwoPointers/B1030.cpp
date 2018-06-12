/**
 * @Author: lee
 * @Date:   2018-06-12T18:18:43+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-12T18:27:36+08:00
 */

// two pointers

// 注意点：(a[i] * p)最多会使10^18次方，超过int范围，所以应该强转为(long long)型，
// 否则最后一个测试点无法通过。

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int main()
{
    int n, p;
    int a[MAX_N];

    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 从小到大排序
    sort(a, a + n);
    int i = 0, j = 0, count = 1;
    while (i < n && j < n) {
        while (j < n && a[j] <= (long long)a[i] * p) {
            count = max(count, j - i + 1);
            j ++;
        }

        i ++;
    }

    printf("%d\n", count);

    return 0;
}
