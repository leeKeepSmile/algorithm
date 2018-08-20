/**
 * @Author: lee
 * @Date:   2018-06-13T20:13:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-28T23:03:11+08:00
 */

// two pointers

#include <cstdio>

const int MAX = 200010;
// int 上限
const int INF = 0x7fffffff;

int s1[MAX], a2;

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &s1[i]);
    }
    s1[n] = INF;
    
    scanf("%d", &m);
    // count计算当前位置数
    int i = 0, j = 0, count = 0;
    // 中位数所在的位置
    int median = (n + m - 1) / 2;

    // 第二个序列边读边进行比较
    scanf("%d", &a2);
    while (count < median) {
        if (s1[i] < a2) {
            i ++;
        } else {
            j ++;
            if (j < m) {
                scanf("%d", &a2);
            } else if (j == m) {
                a2 = INF;
            } else {
                break;
            }
        }

        count ++;
    }

    // 输出较小的数
    printf("%d\n", s1[i] < a2 ? s1[i] : a2);

    return 0;
}
