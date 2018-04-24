/**
 * @Author: lee
 * @Date:   2018-04-24T16:38:15+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-24T17:09:09+08:00
 */

// 查找元素

#include <cstdio>

// 考生信息
struct stuInfo{
    long long sno;
    // 考试座位号
    int examNo;
} stu[1000];

int main()
{
    int n, m, temp, tryNo, examNo;
    long long sno;
    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        scanf("%lld%d%d\n", &sno, &tryNo, &examNo);
        // 以试机座位号作为数组的下标
        stu[tryNo].sno = sno;
        stu[tryNo].examNo = examNo;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        scanf("%d", &temp);

        printf("%lld %d\n", stu[temp].sno, stu[temp].examNo);
    }

    return 0;
}
