/**
 * @Author: lee
 * @Date:   2018-06-12T20:07:27+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-12T20:32:49+08:00
 */

// two pointers

// 二路归并排序算法

#include <cstdio>

const int MAX = 100;

// 将a数组的两个区间内的值合并为有序数组
void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    // temp数组临时存放合并后的数组，index为其下标
    int temp[MAX], index = 0;

    while (i <= r1 && j <= r2) {
        if (a[i] <= a[j]) {
            temp[index ++] = a[i ++];
        } else {
            temp[index ++] = a[j ++];
        }
    }

    // 将剩余数据放入temp数组中
    while (i <= r1) {
        temp[index ++] = a[i ++];
    }
    while (j <= r2) {
        temp[index ++] = a[j ++];
    }

    // 替换a数组
    for (int i = 0; i < index; i ++) {
        a[l1 + i] = temp[i];
    }
}

// 递归，归并排序
void mergeSort(int a[], int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, mid + 1, right);
    }
}

int main()
{
    int a[6] = {1, 3, 2, 6, 5, 4};

    // 二路归并排序
    mergeSort(a, 0, 5);
    for (int i = 0; i < 6; i ++) {
        printf("%d", a[i]);

        if (i != 5) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
