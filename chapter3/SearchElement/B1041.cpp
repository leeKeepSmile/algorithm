/**
 * @Author: lee
 * @Date:   2018-04-24T16:38:15+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-24T17:00:49+08:00
 */

// 查找元素

#include <cstdio>

// 考生信息
struct stuInfo{
    long long sno;
    // 试机座位号
    int tryNo;
    // 考试座位号
    int ExamNo;
} stu[1000];

int main()
{
    int n, m, temp;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        scanf("%lld%d%d", &(stu[i].sno), &(stu[i].tryNo), &(stu[i].ExamNo));
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i ++) {
        scanf("%d", &temp);

        for (int j = 0; j < n; j ++) {
            if (stu[j].tryNo == temp) {
                printf("%lld %d\n", stu[j].sno, stu[j].ExamNo);
                break;
            }
        }
    }

    return 0;
}
