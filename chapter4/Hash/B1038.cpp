/**
 * @Author: lee
 * @Date:   2018-06-05T21:57:09+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T22:09:27+08:00
 */

// 散列

#include <cstdio>

int main()
{
    int n, k;
    // 成绩
    int score;
    // 成绩 => 人数
    int stuAmount[101] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &score);
        stuAmount[score] ++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        scanf("%d", &score);

        printf("%d", stuAmount[score]);
        if (i != k - 1) {
            printf(" ");
        }
    }



    return 0;
}
