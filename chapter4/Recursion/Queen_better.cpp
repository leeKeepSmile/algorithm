/**
 * @Author: lee
 * @Date:   2018-06-07T16:55:40+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T17:14:29+08:00
 */

// 皇后问题-回溯法

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
    // 能到这步的都是合法的方案
    if (index == n + 1) {
        amount ++;
        return;
    }

    for (int x = 1; x <= n; x ++) {
        // 第x行还没有皇后
        if (hashTable[x] == false) {
            // flag为true表示当前皇后不会与之前的皇后冲突
            bool flag = true;
            for (int pre = 1; pre < index; pre ++) {
                // 第index列的皇后的行号为x，第pre列的皇后的行号为p[pre]
                if (abs(index - pre) == abs(x - p[pre])) {
                    // 与之前的皇后在同一对角线上，则冲突
                    flag = false;
                    break;
                }
            }

            // 如果不冲突
            if (flag) {
                p[index] = x;
                hashTable[x] = true;
                recursion(index + 1);
                hashTable[x] = false;
            }
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
