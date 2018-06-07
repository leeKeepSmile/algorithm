/**
 * @Author: lee
 * @Date:   2018-06-07T17:33:56+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T18:07:24+08:00
 */

// 贪心

#include <cstdio>
#include <algorithm>

using namespace std;

struct Goods {
    // 库存量（万吨）
    double depot;
    // 总售价（亿元）
    double totalPrice;
    // 商品单价（亿元/万吨）
    double perPrice;
}g[1000];

// 从大到小排序
bool cmp(Goods a, Goods b)
{
    return a.perPrice > b.perPrice;
}

int main()
{
    int n, d;
    // 最大收益
    double profit = 0;

    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i ++) {
        scanf("%lf", &g[i].depot);
    }
    for (int i = 0; i < n; i ++) {
        scanf("%lf", &g[i].totalPrice);

        // 计算单价
        g[i].perPrice = g[i].totalPrice / (double)g[i].depot;
    }

    // 按单价从大到小排序
    sort(g, g + n, cmp);
    // 计算最大收益
    for (int i = 0; i < n; i ++) {
        if (g[i].depot <= d) {
            profit += g[i].totalPrice;
            d -= g[i].depot;
        } else {
            profit += g[i].perPrice * d;
            break;
        }
    }

    printf("%.2f\n", profit);

    return 0;
}
