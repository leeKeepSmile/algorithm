/**
 * @Author: lee
 * @Date:   2018-06-13T20:13:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-28T23:03:11+08:00
 */

// two pointers

#include <cstdio>

const int MAX = 200001;
// int 上限
const int INF = 0x7fffffff;

int s1[MAX], s2[MAX];

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        scanf("%d", &s2[i]);
    }

    s1[n] = s2[m] = INF;
    // count计算当前位置数
    int i = 0, j = 0, count = 0;
    // 中位数所在的位置
    int median = (n + m - 1) / 2;
    while (count < median) {
        if (s1[i] < s2[j]) {
            i ++;
        } else {
            j ++;
        }
        count ++;
    }

    // 输出两个序列当前位置较小的元素
    if (s1[i] < s2[j]) {
        printf("%d\n", s1[i]);
    } else {
        printf("%d\n", s2[j]);
    }

    return 0;
}
