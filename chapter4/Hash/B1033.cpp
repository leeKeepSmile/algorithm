/**
 * @Author: lee
 * @Date:   2018-06-05T21:02:43+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T21:55:22+08:00
 */

// 散列

// 注意：该题并没有说第一个字符串不为空，所以存在第一个字符串为空的情况
// 当没有坏键的时候，第一个字符串为空，如果用scanf("%s", ..);输入的话，
// 无法输入空字符串，如果不考虑空字符串的情况，第二个测试点会错误。

#include <cstdio>
#include <cstring>

int main()
{
    // 键为字符的ASCII码，true表示键位坏了，false表示没坏
    bool hashTable[128] = {false};
    char ch[100001], broken[128];

    scanf("%[^\n]", broken);
    scanf("%s", ch);
    int len1 = strlen(ch);
    int len2 = strlen(broken);

    for (int i = 0; i < len2; i ++) {
        char c = broken[i];
        hashTable[c] = true;
        // 如果当前字符为大写字母，则相应小写字母也无法被打出
        if (c >= 'A' && c <= 'Z') {
            hashTable[c - 'A' + 'a'] = true;
        }

        // 如果上档键坏掉了，所有大写字母都不能被打出
        if (c == '+') {
            for (int j = 'A'; j <= 'Z'; j ++) {
                hashTable[j] = true;
            }
        }
    }

    // 输出结果
    for (int i = 0; i < len1; i ++) {
        if (!hashTable[ch[i]]) {
            printf("%c", ch[i]);
        }
    }
}
