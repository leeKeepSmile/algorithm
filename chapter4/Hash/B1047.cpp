/**
 * @Author: lee
 * @Date:   2018-06-05T23:15:00+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T23:22:30+08:00
 */

// 散列

#include <cstdio>

int main()
{
    int n, maxScore = -1, maxTeamNo = -1;
    // 键为队伍编号，值为总成绩
    int teamScore[1000] = {0};

    scanf("%d", &n);
    int teamNo, memberNo, score;
    for (int i = 0; i < n; i ++) {
        scanf("%d-%d %d", &teamNo, &memberNo, &score);

        teamScore[teamNo] += score;
        if (teamScore[teamNo] > maxScore) {
            maxScore = teamScore[teamNo];
            // 成绩最高的队伍编号
            maxTeamNo = teamNo;
        }
    }

    printf("%d %d", maxTeamNo, maxScore);

    return 0;
}
