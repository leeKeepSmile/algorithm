/**
 * @Author: lee
 * @Date:   2018-05-28T21:08:29+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-29T20:16:12+08:00
 */

// 排序

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    char name[9];
    int grade;
} stu[100000];

int c;

// 排序
bool cmp(Student a, Student b)
{
    if (c == 1) {
        return a.id < b.id;
    } else if (c == 2) {
        int s = strcmp(a.name, b.name);

        if (s != 0) {
            return s < 0;
        } else {
            return a.id < b.id;
        }
    } else {
        if (a.grade != b.grade) {
            return a.grade < b.grade;
        } else {
            return a.id < b.id;
        }
    }
}

int main()
{
    int n;

    scanf("%d %d", &n, &c);

    for (int i = 0; i < n; i ++) {
        scanf("%d%s%d", &stu[i].id, stu[i].name, &stu[i].grade);
    }
    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i ++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }

    return 0;
}
