/**
 * @Author: lee
 * @Date:   2018-06-05T23:38:04+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-06T00:06:16+08:00
 */

// 散列

#include <cstdio>

int main()
{
    int n;
    // number => 个数
    int bets[10001] = {0};
    int number[100000];

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &number[i]);

        bets[number[i]] ++;
    }

    // 是否存在第一个唯一的赌注号码
    bool hasWinner = false;
    int uniqueNumber;
    for (int i = 0; i < n; i ++) {
        if (bets[number[i]] == 1) {
            hasWinner = true;
            uniqueNumber = number[i];
            break;
        }
    }

    // 输出结果
    if (hasWinner) {
        printf("%d", uniqueNumber);
    } else {
        printf("None");
    }

    return 0;
}
