/**
 * @Author: lee
 * @Date:   2018-06-20T16:56:28+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-20T17:13:10+08:00
 */

// 简单数学

#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    while (n --) {
        char str[101];
        scanf("%s", str);
        int len = strlen(str);

        // P的个数；T的个数；其他字符的个数
        int numP = 0, numT = 0, other = 0;
        // P的位置；T的位置
        int locP = -1, locT = -1;
        for (int i = 0; i < len; i ++) {
            if (str[i] == 'P') {
                numP ++;
                locP = i;
            } else if (str[i] == 'T') {
                numT ++;
                locT = i;
            } else if (str[i] != 'A') {
                other ++;
            }
        }

        // P的个数不为1；T的个数不为1；有其他字符；P和T之间没有字符。则输出NO
        if (numP != 1 || numT != 1 || other != 0 || locT - locP <= 1) {
            printf("NO\n");
            continue;
        }

        // x表示P前A的个数；y表示P和T之间A的个数；z表示T后A的个数
        int x = locP, y = locT - locP - 1, z = len - locT - 1;
        // 根据条件如果 aPbTc 是正确的，那么 aPbATca 也是正确的，
        // 其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
        // 可知每次变化，x不变，y = y + 1，z = z + x。将字符串还原到
        // P和T之间只有一个A时，x不变，y = y - 1，z = z - x。一共需要进行
        // y - 1次回退，而z经过y - 1次会退后，z = z - x * (y - 1)，此时x = y
        // 所以当x = z - x * (y - 1)时，答案正确，否则答案错误。
        if (z - x * (y - 1) == x) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
