/**
 * @Author: lee
 * @Date:   2018-04-25T18:14:53+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-25T18:36:07+08:00
 */

// 查找元素

#include <cstdio>

struct grade{
    char name[11];
    char gender;
    char id[11];
    int grade;
}highest, lowest, temp;

int main()
{
    int n;

    // 初始化最高和最低成绩
    highest.grade = -1;
    lowest.grade = 101;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        getchar();
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.grade);

        if (temp.grade > highest.grade && temp.gender == 'F') {
            highest = temp;
        }

        if (temp.grade < lowest.grade && temp.gender == 'M') {
            lowest = temp;
        }
    }

    if (highest.grade != -1) {
        printf("%s %s\n", highest.name, highest.id);
    } else {
        printf("Absent\n");
    }

    if (lowest.grade != 101) {
        printf("%s %s\n", lowest.name, lowest.id);
    } else {
        printf("Absent\n");
    }

    if (highest.grade != -1 && lowest.grade != 101) {
        printf("%d", highest.grade - lowest.grade);
    } else {
        printf("NA");
    }

    return 0;
}
