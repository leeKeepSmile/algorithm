/**
 * @Author: lee
 * @Date:   2018-06-24T13:47:01+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-24T14:12:04+08:00
 */

// 质因子分解

// 注意n==1的情况，直接输出1=1

#include <cstdio>
#include <cmath>

const int MAX_N = 100010;

int prime[MAX_N], pNum = 0;
// 如果i为素数，则p[i]为false;否则，p[i]为true
bool p[MAX_N] = {0};

// 埃氏筛法，生成素数表
void findPrime()
{
    for (int i = 2;i < MAX_N; i ++) {
        if (p[i] == false) {
            prime[pNum ++] = i;
            for (int j = i + i; j < MAX_N; j += i) {
                p[j] = true;
            }
        }
    }
}

struct factor {
    // x为质因子，cnt为其个数
    int x, cnt;
} fac[10];

int main()
{
    // num为n不同质因子的个数
    int n, num = 0;

    scanf("%d", &n);
    // 生成素数表
    findPrime();

    // 特判n==1的情况
    if (n == 1) {
        printf("1=1");
    } else {
        printf("%d=", n);

        int sqr = (int)sqrt(1.0 * n);
        for (int i = 0; i < pNum && prime[i] <= sqr; i ++) {
            // 如果prime[i]是n的质因子
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;

                while (n % prime[i] == 0) {
                    fac[num].cnt ++;
                    n /= prime[i];
                }

                num ++;
            }

            // 当n = 1的时候跳出循环，节约时间。
            if (n == 1) {
                break;
            }
        }

        // 如果n无法被根号n以内的质因子除尽
        if (n != 1) {
            // 那么一定有一个大于根号n的质因子
            fac[num].x = n;
            fac[num ++].cnt = 1;
        }

        // 输出结果
        for (int i = 0; i < num; i ++) {
            if (i > 0) {
                printf("*");
            }
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1) {
                printf("^%d", fac[i].cnt);
            }
        }
    }

    return 0;
}
