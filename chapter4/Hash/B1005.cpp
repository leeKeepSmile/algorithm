/**
 * @Author: lee
 * @Date:   2018-06-06T12:07:27+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-06T12:39:20+08:00
 */

// 散列

// 注意点，hashTable数组的大小应该设置大一点，否则会出现段错误，因为(3n + 1)可能就是超过
// 100以上的数字.

#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    // num为非关键数的个数
    int k;
    int a[100];
    // n => 是否为被覆盖的数
    bool hashTable[10000] = {false};

    scanf("%d", &k);
    for (int i = 0; i < k; i ++) {
        scanf("%d", &a[i]);

        int n = a[i];
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = (3 * n + 1) / 2;
            }

            hashTable[n] = true;
        }
    }

    // 关键数的个数
    int keyNumAmount = 0;
    for (int i = 0; i < k; i ++) {
        if (!hashTable[a[i]]) {
            keyNumAmount ++;
        }
    }

    // 从小大大排序
    sort(a, a + k, cmp);
    for (int i = 0; i < k; i ++) {
        if (!hashTable[a[i]]) {
            printf("%d", a[i]);
            keyNumAmount --;

            if (keyNumAmount > 0) {
                printf(" ");
            } else {
                break;
            }
        }
    }

    return 0;
}
