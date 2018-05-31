/**
 * @Author: lee
 * @Date:   2018-05-31T22:40:13+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-31T22:52:33+08:00
 */

// 排序

#include <cstdio>
#include <algorithm>

using namespace std;

struct Student {
    char name[11];
    char id[11];
    int grade;
} stu[50];

// 排序
bool cmp(Student a, Student b)
{
    return a.grade > b.grade;
}

int main()
{
    int n, minGrade, maxGrade;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s%s%d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d%d", &minGrade, &maxGrade);

    // 排序
    sort(stu, stu + n, cmp);
    // 是否没有在成绩区间内的记录，true表示没有
    bool isNone = true;
    for (int i = 0; i < n; i ++) {
        if (stu[i].grade >= minGrade && stu[i].grade <= maxGrade) {
            // 非空
            isNone = false;

            printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }

    if (isNone) {
        printf("NONE\n");
    }

    return 0;
}
