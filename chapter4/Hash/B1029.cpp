/**
 * @Author: lee
 * @Date:   2018-06-05T19:53:55+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T20:59:08+08:00
 */

// 散列

// 注：因为键盘小写字母和大写字母对应的是一个键位，并且只输出大写字母，所以
// 将所有的小写字母都转化为大写字母。

#include <cstdio>
#include <cstring>

int main()
{
    char a[81], b[81];
    // 键为字符ASCII码，true表示该字符已输出过。
    bool hashTable[128] = {false};
    scanf("%s%s", a, b);

    int lenA = strlen(a);
    int lenB = strlen(b);

    for (int i = 0; i < lenA; i ++) {
        int j;
        char c1, c2;
        c1 = a[i];
        // 将小写字母转化为大写字母
        if (c1 >= 'a' && c1 <= 'z') {
            c1 -= 32;
        }

        for (j = 0; j < lenB; j ++) {
            c2 = b[j];
            if (c2 >= 'a' && c2 <= 'z') {
                c2 -= 32;
            }

            if (c1 == c2) {
                break;
            }
        }

        // 如果a字符串中的字符在b字符串中找不到并且该字符未输出过，则输出该字符
        if (j == lenB && hashTable[c1] == false) {
            printf("%c", c1);
            hashTable[c1] = true;
        }
    }

    return 0;
}
