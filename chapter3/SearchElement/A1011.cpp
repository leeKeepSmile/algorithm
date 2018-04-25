/**
 * @Author: lee
 * @Date:   2018-04-25T17:01:31+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-25T17:47:16+08:00
 */

// 查找元素

#include <cstdio>
#include <cmath>

// 用于浮点数比较
const double eps = 1e-8;

// 将下标转化为字符
char convertIntToChar(int offset)
{
    if (offset == 0) {
        return 'W';
    } else if (offset == 1) {
        return 'T';
    } else {
        return 'L';
    }
}

int main()
{
    // 0表示W；1表示T；2表示L
    double a[3][3];
    // 记录最大赔率的下标
    int offset[3];

    for (int i = 0; i < 3; i ++) {
        scanf("%lf%lf%lf", &a[i][0], &a[i][1], &a[i][2]);

        double tempMax = 0;
        for (int j = 0; j < 3; j ++) {
            if (a[i][j] - tempMax > eps) {
                tempMax = a[i][j];
                // 存储最大赔率的下标
                offset[i] = j;
            }
        }
    }

    printf(
        "%c %c %c %.2f\n",
        convertIntToChar(offset[0]),
        convertIntToChar(offset[1]),
        convertIntToChar(offset[2]),
        (a[0][offset[0]] * a[1][offset[1]] * a[2][offset[2]] * 0.65 - 1) * 2
    );

    return 0;
}
