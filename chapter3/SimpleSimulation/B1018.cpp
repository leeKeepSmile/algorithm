/**
 * @Author: lee
 * @Date:   2018-04-19T19:53:48+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-20T17:00:38+08:00
 */

// 简单模拟

#include <cstdio>

// 将B、C、J 映射成 0，1，2
int mapToNum(char c)
{
    switch (c) {
        case 'B':
            return 0;
        case 'C':
            return 1;
        default:
            return 2;
    }
}

int main()
{
    int n;
    // 甲和乙赢、平、输的次数，对应0，1，2
    int winA[3] = {0}, winB[3] = {0};
    // 甲和乙每个手势赢的次数。0 => B；1 => C；2 => J
    int handA[3] = {0}, handB[3] = {0};
    // 甲和乙的手势
    char c1, c2;
    // 手势数组
    char map[3] = {'B', 'C', 'J'};
    // 甲乙手势转变为整数后的值
    int a1, a2;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        // 吸收回车
        getchar();
        scanf("%c %c", &c1, &c2);
        a1 = mapToNum(c1);
        a2 = mapToNum(c2);

        // 0胜1；1胜2；2胜0；联想到取余
        // 若a1胜a2
        if ((a1 + 1) % 3 == a2) {
            // 甲胜场+1
            winA[0] ++;
            // 乙输场数+1
            winB[2] ++;
            // 赢的手势 ++
            handA[a1] ++;
        } else if ((a2 + 1) % 3 == a1) {
            // 若乙赢，乙赢场数+1
            winB[0] ++;
            // 甲输场数+1
            winA[2] ++;
            // 赢的手势 ++
            handB[a2] ++;
        } else {
            // 平局
            winA[1] ++;
            winB[1] ++;
        }
    }

    // 分别打印甲、乙赢、平、输的次数
    printf("%d %d %d\n", winA[0], winA[1], winA[2]);
    printf("%d %d %d\n", winB[0], winB[1], winB[2]);

    // 甲赢次数最多的手势，乙赢次数最多的手势
    int resA, resB;
    resA = resB = 0;

    // B、C、J是按从小到大排列的，所以只要判断后面的数是否大于前面的数，
    // 相等的话，还是保留前面的，无需写很多if else来判断。
    for (int i = 1; i < 3; i ++) {
        if (handA[i] > handA[resA]) {
            resA = i;
        }

        if (handB[i] > handB[resB]) {
            resB = i;
        }
    }

    printf("%c %c", map[resA], map[resB]);

    return 0;
}
