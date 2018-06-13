/**
 * @Author: lee
 * @Date:   2018-06-13T20:13:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-13T21:03:42+08:00
 */

// two pointers

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000010;

int n, m;
int s1[MAX], s2[MAX], temp[MAX];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &s1[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        scanf("%d", &s2[i]);
    }

    // index为合并后数组的长度
    int i = 0, j = 0, index = 0;
    // 中位数所在的位置
    int median = (n + m - 1) / 2;
    while (i < n && j < m) {
        if (s1[i] <= s2[j]) {
            temp[index ++] = s1[i ++];
        } else {
            temp[index ++] = s2[j ++];
        }

        if (index - 1 == median) {
            printf("%d\n", temp[index - 1]);

            return 0;
        }
    }

    // 剩余数据插入数组
    while (i < n) {
        temp[index ++] = s1[i ++];

        if (index - 1 == median) {
            printf("%d\n", temp[index - 1]);

            return 0;
        }
    }
    while (j < n) {
        temp[index ++] = s2[j ++];

        if (index - 1 == median) {
            printf("%d\n", temp[index - 1]);

            return 0;
        }
    }

    return 0;
}
