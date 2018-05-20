/**
 * @Author: lee
 * @Date:   2018-05-18T23:57:48+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-20T21:55:48+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    // left最初指向第一个数字，right起始指向最后一个数字
    int left = 0, right;
    char s[11];
    // 数字对应的中文字符
    char numStr[10][5] = {
        "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
    };
    // 单位对应的拼音
    char unit[5][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

    scanf("%s", s);
    int len = strlen(s);
    right = len - 1;

    if (s[0] == '-') {
        left ++;
        // 若第一个字符为"-"，则输出"-"号
        printf("Fu");
    }

    // 将数字分为不同节，每一节4个数字
    while (left + 4 <= right) {
        right -= 4;
    }

    while (left < len) {
        // 是否有0堆积
        bool flag = false;
        // 该节是否输出过其中的位，用于判断是否需要输出万或亿
        bool hasPrint = false;

        while (left <= right) {
            if (left > 0 && s[left] == '0') {
                // 有零堆积
                flag = true;
            } else {
                // 输出ling
                if (flag == true) {
                    printf(" ling");
                    flag = false;
                }

                // 除第一位外，每位前面输出空格
                if (left > 0) {
                    printf(" ");
                }
                printf("%s", numStr[s[left] - '0']);
                hasPrint = true;
                // 除个位外，其余都输出对应的位
                if (left != right) {
                    printf(" %s", unit[right - left - 1]);
                }
            }
            left ++;
        }

        // 除是个位外，其他输出万或亿
        if (hasPrint == true && right != len - 1) {
            printf(" %s", unit[(len - 1 - right) / 4 + 2]);
        }
        right += 4;
    }
}
