/**
 * @Author: lee
 * @Date:   2018-05-08T21:59:31+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-08T22:32:53+08:00
 */

// 字符串处理

#include <cstdio>
#include <cmath>

int main()
{
    int a, b, sum, i = 0;
    char res[10] = {0};

    scanf("%d%d", &a, &b);

    sum = a + b;
    // 负数输出负号
    if (sum < 0) {
        printf("-");
    }

    // 字符个数
    int count = 0;
    do {
        int temp = sum % 10;
        int num = sqrt(temp * temp);

        res[i ++] = num + '0';
        sum /= 10;
        count ++;

        // 存入逗号
        if (count % 3 == 0 && sum != 0) {
            res[i ++] = ',';
        }
    } while (sum != 0);

    // 输出结果
    for (int j = i - 1; j >= 0; j --) {
        printf("%c", res[j]);
    }

    return 0;
}
