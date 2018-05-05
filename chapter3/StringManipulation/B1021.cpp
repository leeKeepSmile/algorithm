/**
 * @Author: lee
 * @Date:   2018-05-05T22:10:26+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-05T22:22:59+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    char n[1001];
    int res[10] = {0};
    int len;

    scanf("%s", n);
    len = strlen(n);

    // 计算每个数字的个数
    for (int i = 0; i < len; i ++) {
        res[n[i] - 48] ++;
    }

    // 输出结果
    for (int i = 0; i < 10; i ++) {
        if (res[i] != 0) {
            printf("%d:%d\n", i, res[i]);    
        }
    }

    return 0;
}
