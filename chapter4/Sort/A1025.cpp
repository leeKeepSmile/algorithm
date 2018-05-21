/**
 * @Author: lee
 * @Date:   2018-05-21T22:12:23+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-21T23:37:11+08:00
 */

// 排序

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    char num[14];
    int score;
    int finalRank;
    int locationNumber;
    int localRank;
}g[30000];

// 按分数从高到低排序，分数相同按编号从小到大排序
int cmp(Student a, Student b)
{
    if (a.score != b.score) {
        return a.score > b.score;
    } else {
        return strcmp(a.num, b.num) < 0;
    }
}

int main()
{
    int n, count = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        int temp;
        scanf("%d", &temp);

        for (int j = count; j < count + temp; j ++) {
            getchar();
            scanf("%s %d", g[j].num, &g[j].score);
            g[j].locationNumber = i + 1;
        }

        //排序
        sort(g + count, g + count + temp, cmp);
        // 初始化该部分排名第一的排名
        g[count].localRank = 1;
        // 处理相同分数排名
        for (int j = count + 1; j < count + temp; j ++) {
            // 相同分数排名相同，不同分数排名等于当前循环次数
            if (g[j].score == g[j - 1].score) {
                g[j].localRank = g[j - 1].localRank;
            } else {
                g[j].localRank = j - count + 1;
            }
        }

        // 计算总个数
        count += temp;
    }

    // 总排名排序
    sort(g, g + count, cmp);
    g[0].finalRank = 1;
    for (int i = 1; i < count; i ++) {
        if (g[i].score == g[i - 1].score) {
            g[i].finalRank = g[i - 1].finalRank;
        } else {
            g[i].finalRank = i + 1;
        }
    }

    // 输出结果
    printf("%d\n", count);
    for (int i = 0; i < count; i ++) {
        printf(
            "%s %d %d %d\n",
            g[i].num, g[i].finalRank, g[i].locationNumber, g[i].localRank
        );
    }

    return 0;
}
