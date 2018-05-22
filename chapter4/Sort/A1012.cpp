/**
 * @Author: lee
 * @Date:   2018-05-22T22:37:20+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-22T23:51:16+08:00
 */

// 排序

// 注意平均成绩是四舍五入

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    // 0表示A；1表示C；2表示M；3表示E。
    int grade[4];
}stu[2000];

// 当前排序成绩；0表示A；1表示C；2表示M；3表示E。
int now;
// 以学生ID为一维下标，二维下标分别对应A、C、M、E
int r[10000000][4] = {0};
char course[4] = {'A', 'C', 'M', 'E'};

bool cmp(Student a, Student b)
{
    return a.grade[now] > b.grade[now];
}

int main()
{
    int n, m;
    int id[2000] = {0};

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf(
            "%d%d%d%d",
            &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]
        );
        // 求平均值
        stu[i].grade[0] = (int)round((stu[i].grade[1] +
            stu[i].grade[2] + stu[i].grade[3]) / 3.0);
    }
    for (int i = 0; i < m; i ++) {
        scanf("%d", &id[i]);
    }

    for (now = 0; now < 4; now ++) {
        // 排序
        sort(stu, stu + n, cmp);
        // 第一名排名为1
        r[stu[0].id][now] = 1;
        for (int i = 1; i < n; i ++) {
            // 如果该对应now成绩等于上一个人的成绩，则排名相同，否则排名=i+1
            if (stu[i].grade[now] == stu[i - 1].grade[now]) {
                r[stu[i].id][now] = r[stu[i - 1].id][now];
            } else {
                r[stu[i].id][now] = i + 1;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < m; i ++) {
        if (r[id[i]][0] == 0) {
            printf("N/A\n");
        } else {
            int k = 0;
            int bestRank = r[id[i]][0];

            for (int j = 1; j < 4; j ++) {
                if (r[id[i]][j] < bestRank) {
                    bestRank = r[id[i]][j];
                    k = j;
                }
            }

            printf("%d %c\n", bestRank, course[k]);
        }
    }

    return 0;
}
