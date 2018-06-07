/**
 * @Author: lee
 * @Date:   2018-06-07T14:54:14+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-07T15:44:57+08:00
 */

// 全排列算法

// 从递归的角度考虑，如果把问题描述为『输出1~n这n个数的全排列』，
// 那么可以被分为若干个子问题：『输出1开头的全排列』；『输出2开头的全排列』
// ...；『输出n开头的全排列』。

#include <cstdio>

const int MAX_N = 11;

// 1~n的整数
int n;
// 存储当前排列顺序
int p[MAX_N];
// 整数 => 该整数是否已填充至p数组
bool hashTable[MAX_N] = {false};

void recursion(int index)
{
    // 递归边界
    if (index == n + 1) {
        for (int i = 1; i <= n; i ++) {
            printf("%d", p[i]);
        }

        printf("\n");

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
    n = 3;
    recursion(1);
    return 0;
}
