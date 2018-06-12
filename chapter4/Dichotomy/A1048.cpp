/**
 * @Author: lee
 * @Date:   2018-06-12T16:49:31+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-12T17:04:45+08:00
 */

// 二分

// 以下是用二分查找法解决该问题，亦可以用hash来解决该问题，见Hash/A1048_better.cpp

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100010;

int a[MAX_N];

// 在a数组中找到与x相同的数的位置，如果未找到返回-1
int binarySearch(int left, int right, int x)
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

    return -1;
}

int main()
{
    int n, m, i;

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
    }

    // 从小到大排列a数组
    sort(a, a + n);
    for (i = 0; i < n; i ++) {
        int j = binarySearch(0, n - 1, m - a[i]);

        if (j != -1 && j != i) {
            printf("%d %d\n", a[i], a[j]);
            break;
        }
    }

    // 如果未找到
    if (i == n) {
        printf("No Solution\n");
    }
}
