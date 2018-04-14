/**
 * @Author: lee
 * @Date:   2018-04-14T16:56:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-14T17:34:54+08:00
 */

// 小范围可以直接遍历
// 若范围较大，可选择二分法等快速查找方法

#include <cstdio>

int main()
{
    int n;

    while (scanf("%d\n", &n) != EOF) {
        int x;
        int a[200];

        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }

        scanf("%d", &x);

        // 是否找到x
        int hasFound = 0;
        for (int i = 0; i < n; i ++) {
            if (a[i] == x) {
                hasFound = 1;
                printf("%d\n", i);
                break;
            }
        }

        // 不在数组中则输出-1
        if (hasFound == 0) {
            printf("-1\n");
        }
    }

    return 0;
}
