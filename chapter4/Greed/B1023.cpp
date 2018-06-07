/**
 * @Author: lee
 * @Date:   2018-06-07T18:09:07+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T18:25:02+08:00
 */

// 贪心

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a[50];
    // amount为数字总个数；pos为计数器，表示当前的数
    int num, amount = 0, pos = 0;

    while (scanf("%d", &num) != EOF) {
        for (int i = amount; i < amount + num; i ++) {
            a[i] = pos;
        }
        // 累加总数
        amount += num;
        // 当前数++
        pos ++;
    }

    // 从小到大排序a数组中的元素
    sort(a, a + amount);
    // 第一位数字在数组中的位置
    int firstNumPos;
    // 找出最小的第一位数字，第一位数字不为0，并记录改数字在数组中的位置。
    for (int i = 0; i < amount; i ++) {
        if (a[i] != 0) {
            printf("%d", a[i]);
            firstNumPos = i;
            break;
        }
    }

    // 输出结果
    for (int i = 0; i < amount; i ++) {
        // 第一位数字不再被输出
        if (i == firstNumPos) {
            continue;
        }

        printf("%d", a[i]);
    }

    return 0;
}
