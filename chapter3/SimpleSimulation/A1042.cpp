/**
 * @Author: lee
 * @Date:   2018-04-20T17:03:10+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-20T20:13:15+08:00
 */

// 简单模拟

#include <cstdio>

int main()
{
    int k;
    // 54张牌，一维代表第(i+1)次洗牌，二位表示牌的顺序
    int card[21][54];
    // 获取输入数据
    int input[54];
    char cardType[5] = {'S', 'H', 'C', 'D', 'J'};

    scanf("%d", &k);
    for (int i = 0; i < 54; i ++) {
        getchar();
        scanf("%d", &input[i]);
        // 初始化牌的顺序，1 2 3 4 .... 54
        card[0][i] = i + 1;
    }

    // 将card[i - 1]的牌按card[0]给出的顺序存入card[i]
    for (int i = 1; i <= k; i ++) {
        for (int j = 0; j < 54; j ++) {
            card[i][input[j] - 1] = card[i - 1][j];
        }
    }

    // 输出结果
    for (int i = 0; i < 54; i ++) {
        printf("%c%d", cardType[(card[k][i] - 1) / 13],
            card[k][i] % 13 == 0 ? 13 : card[k][i] % 13);

        if (i != 53) {
            printf(" ");
        }
    }

    return 0;
}
