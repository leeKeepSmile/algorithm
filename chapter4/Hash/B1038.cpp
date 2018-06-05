/**
 * @Author: lee
 * @Date:   2018-06-05T21:57:09+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T22:06:39+08:00
 */

// 散列

#include <cstdio>

int main()
{
    int n, k;
    // 成绩
    int grade[100000] = {0};
    // 成绩 => 人数
    int stuAmount[101] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &grade[i]);
        stuAmount[grade[i]] ++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        int temp;
        scanf("%d", &temp);

        printf("%d", stuAmount[temp]);
        if (i != k - 1) {
            printf(" ");
        }
    }



    return 0;
}
