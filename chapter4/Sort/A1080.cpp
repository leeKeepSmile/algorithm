/**
 * @Author: lee
 * @Date:   2018-05-31T22:54:48+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-01T18:20:04+08:00
 */

// 排序

#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k;

struct Applicant {
    int id;
    // 初试成绩
    int ge;
    // 复试成绩
    int gl;
    // 最终成绩
    int finalGrade;
    // 志愿院校
    int choices[5];
    // 排名
    int rank;
} app[40000];

struct School {
    // 学校录取名额
    int quota;
    // 录取学生ID
    int receivers[40000];
    // 录取人数
    int count;
    // 最后一位录取学生的排名
    int lastRank;
} school[100];

// 初始化学校结构体
void initSchool()
{
    for (int i = 0; i < m; i ++) {
        school[i].count = 0;
    }
}

// 成绩排序，如果最终成绩和初试成绩都相等，那么排名相等。
bool cmpRank(Applicant a, Applicant b)
{
    if (a.finalGrade != b.finalGrade) {
        return a.finalGrade > b.finalGrade;
    } else {
        return a.ge > b.ge;
    }
}

// 录取学生id从小到大排序
bool cmpId(int a, int b)
{
    return a < b;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i ++) {
        scanf("%d", &school[i].quota);
    }
    // 初始化学校结构体
    initSchool();
    for (int i = 0; i < n; i ++) {
        scanf("%d%d", &app[i].ge, &app[i].gl);
        app[i].id = i;
        app[i].finalGrade = (app[i].ge + app[i].gl) / 2;

        for (int j = 0; j < k; j ++) {
            scanf("%d", &app[i].choices[j]);
        }
    }

    // 排序
    sort(app, app + n, cmpRank);

    // 初始化第一名排名
    app[0].rank = 1;
    for (int i = 1; i < n; i ++) {
        // 若最终成绩和初试成绩都相等，则排名相同
        if (app[i].finalGrade == app[i - 1].finalGrade && app[i].ge == app[i - 1].ge) {
            app[i].rank = app[i - 1].rank;
        } else {
            app[i].rank = i + 1;
        }
    }

    // 录取学生
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < k; j ++) {
            // 学校ID
            int schoolId = app[i].choices[j];

            // 如果录取名额不为0
            if (school[schoolId].quota != 0) {
                // 学校录取人数+1
                school[schoolId].receivers[school[schoolId].count ++] = app[i].id;
                school[schoolId].lastRank = app[i].rank;
                // 名额--
                school[schoolId].quota --;

                break;
            } else {
                // 如果录取名额没有剩余，且该生排名与最后一位录取的学生的排名相同，
                // 则同样录取该生。
                if (school[schoolId].lastRank == app[i].rank) {
                    school[schoolId].receivers[school[schoolId].count ++] = app[i].id;
                    break;
                }
            }
        }
    }

    // 输出结果
    for (int i = 0; i < m; i ++) {
        // 排序
        sort(school[i].receivers, school[i].receivers + school[i].count, cmpId);

        for (int j = 0; j < school[i].count; j ++) {
            printf("%d", school[i].receivers[j]);

            if (j != school[i].count - 1) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
