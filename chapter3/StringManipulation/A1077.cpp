/**
 * @Author: lee
 * @Date:   2018-05-18T20:59:42+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-18T23:56:40+08:00
 */

// 字符串处理

// 注意点：注意需要一次性输入带有空格的字符串时可采取以下两种办法
//（1）fgets(str, length, stdin); fputs(str, stdout);
//（2）scanf("%[^\n]", str); printf("%s\n", str);

// 注意单词nai，不要拼错，单词拼错，测试点始终有一个未通过，天坑，以后测试点未通过时，
// 还需看看单词是否拼写正确。

#include <cstdio>
#include <cstring>

// 字符串最多的个数
const int MAX_N = 100;
// 字符串最长的长度
const int STR_MAX_LENGTH = 257;

// 反转字符串
void reverse(char str[])
{
    char temp;
    int len = strlen(str);

    for (int i = 0; i < len / 2; i ++) {
        temp = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = temp;
    }
}

int main()
{
    int n, minLen = STR_MAX_LENGTH, count = 0;
    char str[MAX_N][STR_MAX_LENGTH];

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        getchar();
        scanf("%[^\n]", str[i]);

        // 获取最短字符串的长度
        int len = strlen(str[i]);
        if (len < STR_MAX_LENGTH) {
            minLen = len;
        }

        // 反转字符串
        reverse(str[i]);
    }

    for (int i = 0; i < minLen; i ++) {
        // 取第一个字符串的第i个字符
        char c = str[0][i];
        bool same = true;

        for (int j = 1; j < n; j ++) {
            if (str[j][i] != c) {
                same = false;
                break;
            }
        }

        if (same) {
            count ++;
        } else {
            break;
        }
    }

    if (count) {
        for (int i = count - 1; i >= 0; i --) {
            printf("%c", str[0][i]);
        }
    } else {
        printf("nai");
    }

    return 0;
}
