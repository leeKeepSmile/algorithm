/**
 * @Author: lee
 * @Date:   2018-04-18T18:15:01+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-19T19:46:39+08:00
 */

// 简单模拟

// 以下代码逻辑较复杂

#include <cstdio>
#include <cstring>

// 判断哪个手势赢的次数最多，相同就输出字母较小的。
int judge(int win[][1])
{
    if (win[2][0] >= win[1][0] && win[2][0] >= win[0][0]) {
        return 2;
    } else if (win[0][0] >= win[1][0] && win[0][0] >= win[2][0]) {
        if (win[0][0] == win[2][0]) {
            return 2;
        } else {
            return 0;
        }
    } else {
        return 1;
    }
}

int main()
{
    int n;
    // 记录甲的胜场数和甲的平场数，a[0]为赢的次数，a[1]为平的次数
    int a[2][1] = {0};
    // 甲以C/J/B赢的次数
    int win1[3][1] = {0};
    // 乙以C/J/B赢的次数
    int win2[3][1] = {0};
    char temp1, temp2;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        getchar();
        scanf("%c %c", &temp1, &temp2);

        // 输赢结果：0表示平局，1表示甲赢，2表示乙赢
        int res = 0;

        // 判断输赢结果
        if (
            (temp1 == 'C' && temp2 == 'J') ||
            (temp1 == 'J' && temp2 == 'B') ||
            (temp1 == 'B' && temp2 == 'C')
        ) {
            // 胜场数+1
            a[0][0] ++;
            // 甲赢
            res = 1;
        } else if (
            (temp1 == 'C' && temp2 == 'C') ||
            (temp1 == 'J' && temp2 == 'J') ||
            (temp1 == 'B' && temp2 == 'B')
        ) {
            // 平场数+1
            a[1][0] ++;
        } else {
            // 乙赢
            res = 2;
        }

        // 如果甲赢，记录对应获胜的手势
        if (res == 1) {
            win1[(temp1 == 'C') ? 0 : (temp1 == 'J' ? 1 : 2)][0] ++;
        }

        // 如果乙赢，记录对应获胜的手势
        if (res == 2) {
            win2[(temp2 == 'C') ? 0 : (temp2 == 'J' ? 1 : 2)][0] ++;
        }
    }

    // 打印甲胜平负
    printf("%d %d %d\n", a[0][0], a[1][0], n - a[0][0] - a[1][0]);
    // 打印乙胜平负
    printf("%d %d %d\n", n - a[0][0] - a[1][0], a[1][0], a[0][0]);
    // 打印甲乙获胜次数最多的手势，相同就输出字母最小的
    judge(win1) == 0 ? printf("C ") : judge(win1) == 1 ? printf("J ") :
        printf("B ");
    judge(win2) == 0 ? printf("C") : judge(win2) == 1 ? printf("J") :
        printf("B");

    return 0;
}
