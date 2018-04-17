/**
 * @Author: lee
 * @Date:   2018-04-17T17:14:01+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-17T17:33:06+08:00
 */

// 简单模拟

#include <cstdio>
#include <cmath>

const float CLK_TCK = 100.0;

int main()
{
    int C1, C2, sec;
    scanf("%d%d", &C1, &C2);

    sec = round((C2 - C1) / CLK_TCK);

    // %md => 以m位进行右对齐输出，整数不足m位，高位用空格补齐。
    // %0md => 以m为进行右对齐输出，整数不足m位，高位用0补齐。
    printf("%02d:%02d:%02d\n", sec / 3600, (sec % 3600) / 60, sec % 60);

    return 0;
}
