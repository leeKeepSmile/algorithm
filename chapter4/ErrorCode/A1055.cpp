/**
 * @Author: lee
 * @Date:   2018-05-29T21:55:15+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-30T12:21:17+08:00
 */

// 排序

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// preview[20000]存储每个年龄段中净资产前100的人。
struct Person {
    char name[9];
    int age;
    int worth;
} p[100000], preview[20000];

bool cmp(Person a, Person b)
{
    if (a.worth != b.worth) {
        return a.worth > b.worth;
    } else if (a.age != b.age) {
        return a.age < b.age;
    } else {
        int s = strcmp(a.name, b.name);

        return s < 0;
    }
}

int main()
{
    int n, k;
    //下标对应年龄，值代表该年龄段的人数
    int age[201] = {0};
    // 预处理数组个数
    int previewCount = 0;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i ++) {
        scanf("%s%d%d", p[i].name, &p[i].age, &p[i].worth);
    }
    // 排序
    sort(p, p + n, cmp);

    // 预处理，每个年龄最多取100个人
    for (int i = 0; i < n; i ++) {
        if (age[p[i].age] < 100) {
            age[p[i].age] ++;
            preview[previewCount ++] = p[i];
        }
    }

    for (int i = 1; i <= k; i ++) {
        int m, aMin, aMax, printCount = 0;
        scanf("%d%d%d", &m, &aMin, &aMax);

        printf("Case #%d:\n", i);
        for (int j = 0; j < previewCount && printCount < m; j ++) {
            if (preview[j].age >= aMin && preview[j].age <= aMax) {
                printf(
                    "%s %d %d\n",
                    preview[j].name, preview[j].age, preview[j].worth
                );
                // 统计符合条件的人数
                printCount ++;
            }
        }

        // 若人数为0，则输出None
        if (printCount == 0) {
            printf("None\n");
        }
    }

    return 0;
}
