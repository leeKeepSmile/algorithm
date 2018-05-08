/**
 * @Author: lee
 * @Date:   2018-05-07T21:39:07+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-08T14:28:41+08:00
 */

// 字符串处理

// 本题注意点：
// ***（1）定义res[110]数组时，需要赋初值{0}，否则，反转数组时可能会出错，原因是
// 未被赋初值的元素将会由不同的编译器内部实现不同而被赋以不同的初值（可能是很大的随机数），
// 一般情况默认初值为0；如果未赋初值，那么测试点大部分都无法通过。
//
// （2）该题需要注意的是，循环次数取A和B两个字符串中较长的字符串长度，未够长度的字符串
// 计算时用整数0来代替运算；起初编码时，我取字符串B的长度为循环次数，超出A长度的部分取原值，
// 但测试点无法通过，所以是需要考虑两个字符串长短的问题。

#include <cstdio>
#include <cstring>

// 反转字符串
void reverse(char str[])
{
    int len;
    char temp;
    len = strlen(str);

    for (int i = 0; i < len / 2; i ++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main()
{
    int lenA, lenB, len;
    char a[110], b[110];
    char res[110] = {'\0'};

    // 奇数位相加取余后对应的字符
    char oddStr[14] = {
        '0', '1', '2', '3', '4', '5', '6', '7',
        '8', '9', 'J', 'Q', 'K'
    };

    scanf("%s %s", a, b);
    lenA = strlen(a);
    lenB = strlen(b);
    reverse(a);
    reverse(b);

    // 加密
    len = lenA < lenB ? lenB : lenA;
    for (int i = 0; i < len; i ++) {
        int numA = i < lenA ? a[i] - '0' : 0;
        int numB = i < lenB ? b[i] - '0' : 0;

        if ((i + 1) % 2 == 0) {
            int temp = numB - numA;
            if (temp < 0) {
                temp += 10;
            }
            res[i] = temp + '0';
        } else {
            res[i] = oddStr[(numA + numB) % 13];
        }
    }

    // 反转结果
    reverse(res);
    printf("%s", res);

    return 0;
}
