/**
 * @Author: lee
 * @Date:   2018-06-08T12:37:22+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-09T16:17:38+08:00
 */

// 贪心

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 510;

// 加油站
struct Station {
    double price;
    double distance;
} s[MAX_N];

// 按加油站距离从小到大排序
bool cmp(Station a, Station b)
{
    return a.distance < b.distance;
}

int main()
{
    int n;
    double maxCapacity, totalDistance, avgDistance;

    scanf("%lf%lf%lf%d", &maxCapacity, &totalDistance, &avgDistance, &n);
    for (int i = 0; i < n; i ++) {
        scanf("%lf%lf", &s[i].price, &s[i].distance);
    }
    // 设终点油价为0，距离等于totalDistance
    s[n].price = 0;
    s[n].distance = totalDistance;

    // 排序
    sort(s, s + n, cmp);
    // 如果第一个加油站距离不为0，则无法出发
    if (s[0].distance != 0) {
        printf("The maximum travel distance = 0.00\n");
    } else {
        // 当前加油站下标
        int now = 0;
        // 花费总金额、当前剩余油量、满油最多能行驶的路程
        double totalPrice = 0, nowTank = 0, maxDistance = maxCapacity * avgDistance;

        // 每次循环选出一个加油站
        while (now < n) {
            // 从当前加油站加满油能到范围内的车站中选择比当前油价小的加油站
            // 如果没有找到该加油站，则从范围内的几个加油站中选择油价相对最小的加油站
            // 最低油价加油站编号
            int k = -1;
            double minPrice = 1000000000;
            // 寻找范围内是否有比当前加油站油价低的加油站
            for (
                int i = now + 1;
                i <= n && s[i].distance - s[now].distance <= maxDistance;
                i ++
            ) {
                if (s[i].price < minPrice) {
                    minPrice = s[i].price;
                    k = i;

                    // 找到比当前加油站油价低的加油站就跳出循环
                    if (minPrice < s[now].price) {
                        break;
                    }
                }
            }
            // 如果一个加油站都没找到，就跳出循环
            if (k == -1) {
                break;
            }

            // 从now加油站到k加油站需要的油量
            double need = (s[k].distance - s[now].distance) / avgDistance;
            // 如果k加油站的油价比now加油站的油价便宜，则只需要加到足够去k加油站的油
            if (s[k].price < s[now].price) {
                // 当前油量不足以开到k加油站，则补冲油
                if (nowTank < need) {
                    totalPrice += (need - nowTank) * s[now].price;
                    // 开到加油站k后油箱内油量为0
                    nowTank = 0;
                } else {
                    nowTank -= need;
                }
            } else {
                // 若k加油站的油价不比now加油站的油价便宜，则加满油
                totalPrice += (maxCapacity - nowTank) * s[now].price;
                // 开到k加油站后剩余的油量
                nowTank = maxCapacity - need;
            }

            // 继续循环
            now = k;
        }

        // 达到终点输出总金额
        if (now == n) {
            printf("%.2f\n", totalPrice);
        } else {
            printf("The maximum travel distance = %.2f\n", s[now].distance + maxDistance);
        }
    }

    return 0;
}
