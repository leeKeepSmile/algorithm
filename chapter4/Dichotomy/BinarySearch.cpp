/**
 * @Author: lee
 * @Date:   2018-06-10T20:36:48+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-10T20:43:56+08:00
 */

// 二分查找算法

#include <cstdio>

// a[]为递增数组；left为二分下界；right为二分上界；x为欲查询的数。
int binarySearch(int a[], int left, int right, int x)
{
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;

        if (a[mid] == x) {
            return mid;
        } else if (a[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // 未找到x则返回-1
    return -1;
}

int main()
{
    int a[10] = {1, 3, 4, 6, 7, 8, 10, 11, 12, 15};
    printf("%d %d\n", binarySearch(a, 0, 9, 6), binarySearch(a, 0, 9, 9));

    return 0;
}
