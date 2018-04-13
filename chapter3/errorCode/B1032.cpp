/**
 * @Author: lee
 * @Date:   2018-04-13T16:06:50+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-13T18:19:29+08:00
 */

// 以下代码运行超时，算法太差
// -------------------------------------------------------------------

#include <stdio.h>

// 参赛者结构体
struct participant{
    int scno;
    int grade;

    // 构造函数
    participant() {};
    // 构造函数
    participant(int _scno, int _grade) : scno(_scno) , grade(_grade) {};
};

// 学校总得分结构体
struct schoolGrade{
    int scno;
    int totalGrade;

    schoolGrade() {};
    schoolGrade(int _scno, int _totalGrade) : scno(_scno) , totalGrade(_totalGrade) {};
};

int main()
{
    int N;
    // 学校总数
    int schoolNum = 0;
    // 最高得分学校 和 所对应的最高分
    int hscno, hgrade;
    hscno = hgrade = 0;

    scanf("%d\n", &N);

    participant p[N];
    schoolGrade s[N];

    // 将数据存入结构体中
    for (int i = 0; i < N; i ++) {
        int scno;
        int grade;

        scanf("%d%d", &scno, &grade);
        p[i] = participant(scno, grade);

        // 第一次输入数据时，初始化schoolGrade结构体
        if (schoolNum == 0) {
            s[0].scno = scno;
            s[0].totalGrade = grade;
            hscno = scno;
            hgrade = grade;
            schoolNum ++;
            continue;
        }

        // 是否为新学校数据
        bool isNew = true;
        // 计算学校总得分。
        for (int j = 0; j < schoolNum; j ++) {
            if (s[j].scno == scno) {
                s[j].totalGrade += grade;
                isNew = false;

                // 找出最高得分学校
                if (s[j].totalGrade > hgrade) {
                    hgrade = s[j].totalGrade;
                    hscno = s[j].scno;
                }

                break;
            }
        }

        // 有新学校数据时，插入结构体内
        if (isNew) {
            s[schoolNum].scno = scno;
            s[schoolNum].totalGrade = grade;

            if (grade > hgrade) {
                hscno = scno;
                hgrade = grade;
            }

            schoolNum ++;
        }
    }

    printf("%d %d\n", hscno, hgrade);

    return 0;
}
