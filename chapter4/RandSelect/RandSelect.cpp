/**
 * @Author: lee
 * @Date:   2018-06-15T20:33:17+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-19T20:01:00+08:00
 */

// 随机选择算法

// 问题描述：给定一个由整数组成的集合，集合中的整数各不相同，现在要将它分为两个集合，
// 使得这两个子集合的并为原集合、交为空集，同时在两个子集合的元素个数n1与n2之差的绝对值
// |n1 - n2|尽可能小的前提下，要求它们各自的元素之和S1与S2之差的绝对值|S1 - S2|尽可能大。
// 求这个|S1 - S2|等于多少。

#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MAX_N = 100010;

int a[MAX_N], n;

// 对区间[left, right]进行划分
int randPartition(int a[], int left, int right)
{
    // 获取随机数
    int p = rand() % n;
    swap(a[p], a[left]);

    int temp = a[left];
    while (left < right) {
        while (left < right && a[right] > temp) {
            right --;
        }
        a[left] = a[right];
        while (left < right && a[left] <= temp) {
            left ++;
        }
        a[right] = a[left];
    }

    // 将temp放入left和right相遇的位置
    a[left] = temp;

    // 返回相遇的下标
    return left;
}

// 随机选择算法，从[left, right]中找到第k大的数，并进行切分
void randSelect(int a[], int left, int right, int k)
{
    // 边界
    if (left == right) {
        return;
    }

    // 划分后主元的位置为p
    int p = randPartition(a, left, right);
    // a[p]是[left, right]中的第m大
    int m = p - left + 1;

    if (k == m) {
        return;
    }
    if (k < m) {
        randSelect(a, left, p - 1, k);
    } else {
        randSelect(a, p + 1, right, k - m);
    }
}


int main()
{
    // 初始化随机数种子
    srand((unsigned)time(NULL));

    int sum = 0, sum1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        // 累计所有整数之和
        sum += a[i];
    }

    // 寻找第n/2大的数，并进行切分
    randSelect(a, 0, n - 1, n / 2);
    for (int i = 0; i < n / 2; i ++) {
        sum1 += a[i];
    }

    // 输出结果
    printf("%d\n", (sum - sum1) - sum1);

    return 0;
}
