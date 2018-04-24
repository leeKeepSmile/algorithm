/**
 * @Author: lee
 * @Date:   2018-04-24T17:10:23+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-24T17:43:18+08:00
 */

// 查找元素

#include <cstdio>
#include <cstring>

struct student{
    char name[11];
    char sno[11];
    int grade;
}stu[100];

int main()
{
    int n, grade, max, min;
    max = 0;
    min = 100;
    char name[11];
    char sno[11];

    scanf("%d", &n);
    // 没有两个学生的成绩是相同的，所以可以取成绩作为下标。
    for (int i = 0; i < n; i ++) {
        scanf("%s%s%d", name, sno, &grade);
        strcpy(stu[grade].name, name);
        strcpy(stu[grade].sno, sno);

        if (grade > max) {
            max = grade;
        }

        if (grade < min) {
            min = grade;
        }
    }

    printf("%s %s\n", stu[max].name, stu[max].sno);
    printf("%s %s", stu[min].name, stu[min].sno);

    return 0;
}
