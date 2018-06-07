/**
 * @Author: lee
 * @Date:   2018-06-07T16:10:27+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T16:54:58+08:00
 */

// 皇后问题：n*n的国际象棋棋盘上，放置n个皇后，使得这n个皇后不在同一行、同一列、同一对角线上。

// 思路：每行每列只有1个皇后，竖着看，每列皇后的位置即为行号，所以就相当于全排列的问题，
// 全排列显然不会有皇后处于同行同列；因此只要判断每列皇后是否在同一对角线上。

// 判断两个皇后是否在同一对角线上的方法为：行号差的绝对值等于列号差的绝对值，则表示在
// 同一对角线上。

// 以下算法对每一种情况是否合法都进行了判断，没有进行优化，实际上可以使用回溯法优化算法。
// 回溯法见Queen_better.cpp

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 11;

// 1~n的n个整数
int n;
// 合法的方案数
int amount = 0;
// 当前排列顺序
int p[MAX_N];
// 整数 => 当前整数是否已在排列中
bool hashTable[MAX_N];

void recursion(int index)
{
    // 递归边界
    if (index == n + 1) {
        // flag为true表示当前方案是合法的
        bool flag = true;
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                // 如果在同一对角线上，那么当前方案不合法
                if (abs(i - j) == abs(p[i] - p[j])) {
                    flag = false;
                }
            }
        }

        // 合法方案++
        if (flag) {
            amount ++;
        }

        return;
    }

    // 递归式
    for (int x = 1; x <= n; x ++) {
        if (hashTable[x] == false) {
            p[index] = x;
            hashTable[x] = true;
            recursion(index + 1);
            hashTable[x] = false;
        }
    }
}

int main()
{
    n = 8;
    recursion(1);
    printf("amount = %d\n", amount);

    return 0;
}
