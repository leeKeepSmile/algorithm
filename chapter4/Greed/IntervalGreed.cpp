/**
 * @Author: lee
 * @Date:   2018-06-08T12:08:45+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-08T12:29:30+08:00
 */

// 区间贪心

// 问题描述：不相交问题：给出N个开区间（x, y），从中选择尽可能多的开区间，使得这些开区间
// 两两没有交集。例如对开区间(1,3)、(2,4)、(3,5)、(6,7)来说，可以选出最多3个区间
// (1,3)、(3,5)、(6,7)

// 这个问题类似的是区间选点问题：给出N个闭区间[x,y],求最少需要确定多少个点，才能
// 使每个闭区间中都至少存在一点。例如闭区间[1,4]、[2,6]、[5,7]来说，需要两个点（例如3、5）
// 才能保证每个闭区间中都至少存在一点。
// 区间选点的问题只要把以下代码中的  I[i].y <= lastX（59行）改为 I[i].y < lastX即可。

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 110;

struct Interval {
    int x;
    int y;
} I[MAX_N];

// 左端点不相同，按左端点从大到小排序
// 若左端点相同，则按右端点从小到大排序
bool cmp(Interval a, Interval b)
{
    if (a.x != b.x) {
        return a.x > b.x;
    } else {
        return a.y < b.y;
    }
}

int main()
{
    int n;

    while (scanf("%d", &n), n != 0) {
        // 录入各区间数据
        for (int i = 0; i < n; i ++) {
            scanf("%d%d", &I[i].x, &I[i].y);
        }

        // 排序
        sort(I, I + n, cmp);
        // 最多开区间数
        int amount = 1;
        // 上一个满足条件的开区间的左端点
        int lastX = I[0].x;
        for (int i = 1; i < n; i ++) {
            if (I[i].y <= lastX) {
                amount ++;
                lastX = I[i].x;
            }
        }

        printf("%d\n", amount);
    }

    return 0;
}
