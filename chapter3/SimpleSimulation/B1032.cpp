/**
 * @Author: lee
 * @Date:   2018-04-13T16:06:50+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-15T16:03:29+08:00
 */

// 简单模拟

#include <stdio.h>

int main()
{
    int N;

    // 定义学校数组，下标为学校编号，值为总得分
    // 以空间换取时间
    int a[100000] = {0};

    // 得分最高的学校编号 以及 对应的总分
    int hSchoolNo, hGrade;
    hSchoolNo = hGrade = 0;

    scanf("%d\n", &N);

    for (int i = 0; i < N; i ++) {
        int schoolNo;
        int grade;

        scanf("%d%d", &schoolNo, &grade);

        // 找出得分最高的学校
        a[schoolNo] += grade;
        if (a[schoolNo] > hGrade) {
            hSchoolNo = schoolNo;
            hGrade = a[schoolNo];
        }
    }

    printf("%d %d\n", hSchoolNo, hGrade);

    return 0;
}
