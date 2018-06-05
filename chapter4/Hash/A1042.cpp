/**
 * @Author: lee
 * @Date:   2018-06-05T22:37:43+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T22:54:18+08:00
 */

// 散列

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char str[1001];
    // ASCII => 字符个数
    int hashTable[128] = {0};
    scanf("%[^\n]", str);

    int maxAmount = -1;
    int len = strlen(str);
    for (int i = 0; i < len; i ++) {
        char c = str[i];

        // 将大写字母转化为小写字母
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }

        // 只统计字母
        if (c >= 'a' && c <= 'z') {
            hashTable[c] ++;
            maxAmount = max(hashTable[c], maxAmount);
        }
    }

    // 输出结果，如有并列，输出字母序较小的字母。
    for (int i = 0; i < 128; i ++) {
        if (hashTable[i] == maxAmount) {
            printf("%c ", i);
            break;
        }
    }
    printf("%d", maxAmount);

    return 0;
}
