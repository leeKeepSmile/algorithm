/**
 * @Author: lee
 * @Date:   2018-06-23T15:43:13+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-23T16:13:21+08:00
 */

// 素数

#include <cstdio>
#include <cmath>

const int N = 11111;

// 判断n是否为素数
bool isPrime(int n)
{
    if (n <= 1) {
        return false;
    }

    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i ++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// hashTable[i] == false，则i号位未被占用
bool hashTable[N] = {0};

int main()
{
    int n, tSize, a;

    scanf("%d%d", &tSize, &n);

    // 确定tSize
    while (isPrime(tSize) == false) {
        tSize ++;
    }

    for (int i = 0; i < n; i ++) {
        scanf("%d", &a);
        int m = a % tSize;

        // m号位未被占用
        if (hashTable[m] == false) {
            hashTable[m] = true;
            if (i == 0) {
                printf("%d", m);
            } else {
                printf(" %d", m);
            }
        } else {
            int step;

            // 二次方探查法（只往正向解决冲突）
            for (step = 1; step < tSize; step ++) {
                m = (a + step * step) % tSize;
                if (hashTable[m] == false) {
                    hashTable[m] = true;
                    if (i == 0) {
                        printf("%d", m);
                    } else {
                        printf(" %d", m);
                    }
                    // 跳出循环
                    break;
                }
            }

            // 找不到插入的地方
            if (step >= tSize) {
                if (i > 0) {
                    printf(" ");
                }

                printf("-");
            }
        }
    }

    return 0;
}
