/**
 * @Author: lee
 * @Date:   2018-04-25T17:50:51+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-25T18:08:32+08:00
 */

// 查找元素

#include <cstdio>
#include <cstring>

// 时间格式
struct timeFormate{
    int hour;
    int minute;
    int second;
}signIn, signOut;

int main()
{
    int m;
    char idNumber[16];
    char unlockId[16];
    char lockId[16];
    int earliestTime = 240000;
    int latestTime = 0;
    int signInTime, signOutTime;

    scanf("%d", &m);
    for (int i = 0; i < m; i ++) {
        getchar();
        scanf(
            "%s %d:%d:%d %d:%d:%d",
            idNumber, &signIn.hour, &signIn.minute, &signIn.second,
            &signOut.hour, &signOut.minute, &signOut.second
        );

        signInTime = signIn.hour * 10000 + signIn.minute * 100 + signIn.second;
        signOutTime = signOut.hour * 10000 + signOut.minute * 100 + signOut.second;

        if (signInTime < earliestTime) {
            earliestTime = signInTime;
            strcpy(unlockId, idNumber);
        }
        if (signOutTime > latestTime) {
            latestTime = signOutTime;
            strcpy(lockId, idNumber);
        }
    }

    printf("%s %s", unlockId, lockId);

    return 0;
}
