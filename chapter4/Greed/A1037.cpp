/**
 * @Author: lee
 * @Date:   2018-06-09T17:56:00+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-09T18:26:49+08:00
 */

// 贪心

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int coupon[MAX], bonus[MAX];

int main()
{
    int nc, np;
    // 钱数
    int maxAmount = 0;

    scanf("%d", &nc);
    for (int i = 0; i < nc; i ++) {
        scanf("%d", &coupon[i]);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i ++) {
        scanf("%d", &bonus[i]);
    }

    // 从小到大排序
    sort(coupon, coupon + nc);
    sort(bonus, bonus + np);

    int i = 0, j = 0;
    // 从小到大遍历
    while (i < nc && i < np && coupon[i] < 0 && bonus[i] < 0) {
        maxAmount += coupon[i] * bonus[i];
        i ++;
    }

    // 从大到小遍历
    i = nc - 1;
    j = np - 1;
    while (i >= 0 && j >= 0 && coupon[i] > 0 && bonus[j] > 0) {
        maxAmount += coupon[i] * bonus[j];
        i --;
        j --;
    }

    printf("%d\n", maxAmount);

    return 0;
}
