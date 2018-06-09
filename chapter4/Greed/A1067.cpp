/**
 * @Author: lee
 * @Date:   2018-06-09T18:30:20+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-09T21:27:02+08:00
 */

// 贪心

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;

int main()
{
    int n, num, swapTimes = 0;
    // 数字 => 所在位置
    int pos[MAX_N];

    // 录入数据
    scanf("%d", &n);
    // 剩余未在正确位置的数字总数
    int left = n - 1;
    for (int i = 0; i < n; i ++) {
        scanf("%d", &num);
        // 记录num所在位置
        pos[num] = i;
        // 如果有除0以外的数在正确位置上
        if (num == i && num != 0) {
            left --;
        }
    }

    // k存放除0外当前不在本位上的最小的数
    int k = 1;
    while (left > 0) {
        // 如果0在本位上，则寻找一个当前不在本位上的数与0交换
        if (pos[0] == 0) {
            while (k < n) {
                // 如果找到不在本位上的数，则与0交换
                if (pos[k] != k) {
                    swap(pos[0], pos[k]);
                    swapTimes ++;
                    break;
                }
                k ++;
            }
        }

        // 0不在本位时交换pos[0]与pos[pos[0]]
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            swapTimes ++;
            left --;
        }
    }

    printf("%d\n", swapTimes);

    return 0;
}
