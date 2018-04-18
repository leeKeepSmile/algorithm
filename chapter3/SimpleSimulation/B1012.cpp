/**
 * @Author: lee
 * @Date:   2018-04-18T16:49:34+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-18T17:50:31+08:00
 */

// 简单模拟

// 此题需要注意的是，A2规则不能通过最终和为0来判断是否输出'N'，最好的做法是
// 定义变量并记录满足规则的数据的个数，然后通过判断个数是否大于0，来判断是否
// 输出'N'。

#include <cstdio>

// A1 = 能被5整除的数字中所有偶数的和；
int a1(int a[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i ++) {
        if (a[i] % 5 == 0 && a[i] % 2 == 0) {
            sum += a[i];
        }
    }

    return sum;
}

// A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
// 注意，交错求和结果可能为0，不能用结果是否为0作为是否输出'N'的充分条件。
int a2(int a[], int n, bool &isEmpty)
{
    int sum, count;
    sum = count = 0;

    for (int i = 0; i < n; i ++) {
        if (a[i] % 5 == 1) {
            (count + 1) % 2 == 0 ? sum -= a[i] : sum += a[i];
            count ++;
        }
    }

    count ? isEmpty = 0 : isEmpty = 1;

    return sum;
}

// 被5除后余2的数字的个数；
int a3(int a[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i ++) {
        if (a[i] % 5 == 2) {
            count ++;
        }
    }

    return count;
}

// A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
float a4(int a[], int n)
{
    int sum, count;
    sum = count = 0;

    for (int i = 0; i < n; i ++) {
        if (a[i] % 5 == 3) {
            sum += a[i];
            count ++;
        }
    }

    return count ? sum / (float)count : 0;
}

// A5 = 被5除后余4的数字中最大数字。
int a5(int a[], int n)
{
    int max = 0;

    for (int i = 0; i < n; i ++) {
        if (a[i] % 5 == 4) {
            if (a[i] > max) {
                max = a[i];
            }
        }
    }

    return max;
}

int main()
{
    int n, res;
    float fres;
    // 数组中是否有满足A2规则的数据，1表示没有（即数据是空的），0表示有。
    bool isEmpty = 1;
    int i = 0;
    int a[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 输出结果
    (res = a1(a, n)) ? printf("%d ", res) : printf("N ");
    // 特殊处理，交错求和结果可能为0，引入变量isEmpty判断是否有满足A2规则的数据。
    ((res = a2(a, n, isEmpty)) || !isEmpty) ? printf("%d ", res) : printf("N ");
    (res = a3(a, n)) ? printf("%d ", res) : printf("N ");
    (fres = a4(a, n)) ? printf("%.1f ", fres) : printf("N ");
    (res = a5(a, n)) ? printf("%d", res) : printf("N");

    return 0;
}
