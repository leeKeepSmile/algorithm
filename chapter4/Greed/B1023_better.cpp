/**
 * @Author: lee
 * @Date:   2018-06-07T18:28:29+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T18:32:49+08:00
 */

// 贪心

// B1023更好的算法

#include <cstdio>

int main()
{
    // 表示0~9数字的个数，0~9对应数组下标
    int count[10];

    for (int i = 0; i < 10; i ++) {
        scanf("%d", &count[i]);
    }

    // 第一位数字不为0，所以从1~9中找出最小的一位数字
    for (int i = 1; i < 10; i ++) {
        if (count[i] > 0) {
            printf("%d", i);
            count[i] --;
            break;
        }
    }

    // 输出结果
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < count[i]; j ++) {
            printf("%d", i);
        }
    }

    return 0;
}
