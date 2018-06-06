/**
 * @Author: lee
 * @Date:   2018-06-06T11:48:51+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-06T12:04:03+08:00
 */

// 散列

#include <cstdio>
#include <cstring>

int main()
{
    char s1[10001], s2[10001];
    // ASCII => 该字符是否需要过滤
    bool hashTable[128] = {false};
    int len1 = 0, len2 = 0;

    while (true) {
        s1[len1 ++] = getchar();
        if (s1[len1 - 1] == '\n') {
            break;
        }
    }
    while (true) {
        s2[len2 ++] = getchar();
        if (s2[len2 - 1] == '\n') {
            break;
        }
    }

    for (int i = 0; i < len2; i ++) {
        hashTable[s2[i]] = true;
    }

    for (int i = 0; i < len1; i ++) {
        if (!hashTable[s1[i]]) {
            printf("%c", s1[i]);
        }
    }

    return 0;
}
