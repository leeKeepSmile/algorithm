/**
 * @Author: lee
 * @Date:   2018-05-30T12:34:50+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-31T15:13:43+08:00
 */

// 排序

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Student {
    // 用户id
    int id;
    // 每道题得分
    char score[6];
    // 是否有能通过编译的提交
    bool flag;
    // 总分
    int totalScore;
    // 完美解题数
    int perfectTimes;
} stu[10001];

int n, k, m;
// 每道题的满分
int fullScore[6] = {0};

// 排序
bool cmp(Student a, Student b)
{
    if (a.totalScore != b.totalScore) {
        return a.totalScore > b.totalScore;
    } else if (a.perfectTimes != b.perfectTimes) {
        return a.perfectTimes > b.perfectTimes;
    } else {
        return a.id < b.id;
    }
}

// 初始化结构体
void init()
{
    for (int i = 1; i <= n; i ++) {
        stu[i].id = i;
        stu[i].totalScore = 0;
        stu[i].perfectTimes = 0;
        stu[i].flag = false;
        // 每道题初始化得分为-1
        memset(stu[i].score, -1, sizeof(stu[i].score));
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    init();
    for (int i = 1; i <= k; i ++) {
        scanf("%d", &fullScore[i]);
    }

    int userId, problemId, pScore;
    for (int i = 0; i < m; i ++) {
        scanf("%d%d%d", &userId, &problemId, &pScore);

        // 只要不是编译通过，就置flag = true;
        if (pScore != -1) {
            stu[userId].flag = true;
        }
        // 第一次编译错误，分值记为0
        if (pScore == -1 && stu[userId].score[problemId] == -1) {
            stu[userId].score[problemId] = 0;
        }
        // 第一次获得满分，完美答题数+1
        if (
            pScore == fullScore[problemId] &&
            stu[userId].score[problemId] < fullScore[problemId]
        ) {
            stu[userId].perfectTimes ++;
        }
        // 取最高分
        if (pScore > stu[userId].score[problemId]) {
            stu[userId].score[problemId] = pScore;
        }
    }

    // 计算总分
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (stu[i].score[j] != -1) {
                stu[i].totalScore += stu[i].score[j];
            }
        }
    }

    // 排序
    sort(stu + 1, stu + n + 1, cmp);
    int rank = 1;
    for (int i = 1; i <= n && stu[i].flag == true; i ++) {
        if (i > 1 && stu[i].totalScore != stu[i - 1].totalScore) {
            rank = i;
        }
        printf("%d %05d %d", rank, stu[i].id, stu[i].totalScore);
        for (int j = 1; j <= k; j ++) {
            // 没有提交记录输出-
            if (stu[i].score[j] == -1) {
                printf(" -");
            } else {
                printf(" %d", stu[i].score[j]);
            }
        }

        printf("\n");
    }

    return 0;
}
