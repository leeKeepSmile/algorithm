/**
 * @Author: lee
 * @Date:   2018-06-12T22:33:03+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-12T23:02:47+08:00
 */

// two pointers

// 快速排序

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// 对区间[left, right]进行划分
int partition(int a[], int left, int right)
{
    // 随机获取a数组的某一值，这样可以避免存在一组特定的数据会使算法出现最坏情况，
    // 时间复杂度达到O(n^2)。
    int p = (int)(round(1.0 * rand() / RAND_MAX * (right - left) + left));

    // 交换a[p]和a[left]
    swap(a[p], a[left]);
    // 将a[left]存入至temp
    int temp = a[left];
    // 左边的数不超过temp，右边的数大于temp
    while (left < right) {
        while (left < right && a[right] > temp) {
            right --;
        }
        // 将a[right]给a[left]，即将小的数放左边
        a[left] = a[right];
        while (left < right && a[left] <= temp) {
            left ++;
        }
        // 将a[left]给a[right]，即将大的数放邮编
        a[right] = a[left];
    }

    // temp放在最后left == right的位置上
    a[left] = temp;

    // 返回temp所在的下标
    return left;
}

// 快速排序
void quickSort(int a[], int left, int right)
{
    // 区间长度超过1
    if (left < right) {
        int pos = partition(a, left, right);

        quickSort(a, left, pos);
        quickSort(a, pos + 1, right);
    }
}

int main()
{
    // 生成随机数种子
    srand((unsigned)time(NULL));

    int a[11] = {35, 18, 16, 72, 24, 65, 12, 88, 46, 28, 55};
    // 快速排序
    quickSort(a, 0, 10);

    for (int i = 0; i < 11; i ++) {
        printf("%d", a[i]);

        if (i != 10) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}
