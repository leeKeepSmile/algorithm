/**
 * @Author: lee
 * @Date:   2018-06-05T22:58:18+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T23:12:26+08:00
 */

// 散列

#include <cstdio>
#include <cstring>

int main()
{
    char str[10001];
    // 键0~5分别表示P A T e s t；值为字符个数。
    int hashTable[6] = {0};

    scanf("%s", str);
    int len = strlen(str);
    // 统计字符个数
    for (int i = 0; i < len; i ++) {
        switch (str[i]) {
            case 'P':
                hashTable[0] ++;
                break;
            case 'A':
                hashTable[1] ++;
                break;
            case 'T':
                hashTable[2] ++;
                break;
            case 'e':
                hashTable[3] ++;
                break;
            case 's':
                hashTable[4] ++;
                break;
            case 't':
                hashTable[5] ++;
                break;
            default:
                break;
        }
    }

    // 输出结果
    while (
        hashTable[0] || hashTable[1] || hashTable[2] ||
        hashTable[3] || hashTable[4] || hashTable[5]
    ) {
        if (hashTable[0]) {
            printf("P");
            hashTable[0] --;
        }
        if (hashTable[1]) {
            printf("A");
            hashTable[1] --;
        }
        if (hashTable[2]) {
            printf("T");
            hashTable[2] --;
        }
        if (hashTable[3]) {
            printf("e");
            hashTable[3] --;
        }
        if (hashTable[4]) {
            printf("s");
            hashTable[4] --;
        }
        if (hashTable[5]) {
            printf("t");
            hashTable[5] --;
        }
    }

    return 0;
}
