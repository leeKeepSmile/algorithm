/**
 * @Author: lee
 * @Date:   2018-05-04T22:15:36+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-04T22:54:51+08:00
 */

// 进制转换

// 因为输入的3个十进制数在0~168之间，所以化为十三进制时，最多只有2个数字，所以可以直接输出，
// 不用先转换，再输出。

#include <cstdio>

int main()
{
    int a, b, c;
    char val[14] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

    scanf("%d%d%d", &a, &b, &c);
    printf("#");
    printf("%c%c", val[a / 13], val[a % 13]);
    printf("%c%c", val[b / 13], val[b % 13]);
    printf("%c%c", val[c / 13], val[c % 13]);

    return 0;
}
