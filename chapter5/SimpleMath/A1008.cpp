/**
 * @Author: lee
 * @Date:   2018-06-20T17:35:29+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-20T17:52:36+08:00
 */

// 简单数学

#include <cstdio>

int main()
{
    // now为当前楼层；to为下一次目标楼层
    int n, now = 0, to, totalTime = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &to);

        if (to > now) {
            totalTime += (to - now) * 6;
        } else {
            totalTime += (now - to) * 4;
        }

        // 停留5秒
        totalTime += 5;
        now = to;
    }

    printf("%d\n", totalTime);

    return 0;
}
