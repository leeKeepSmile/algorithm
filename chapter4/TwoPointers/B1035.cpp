/**
 * @Author: lee
 * @Date:   2018-06-13T10:16:45+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-13T16:56:18+08:00
 */

// two pointers

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 110;

int n;
// 是否为插入排序或归并排序
bool isInsertionSort = false, isMergeSort = false;
// origin[]为原始序列；mid为某排序算法产生的中间序列；temp数组存放原始序列。
int origin[MAX_N], mid[MAX_N], temp[MAX_N];

// 判断两个数组是否相等
bool cmpArray(int a[], int b[])
{
    for (int i = 0; i < n; i ++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

// 打印数组
void printArray(int a[])
{
    for (int i = 0; i < n; i ++) {
        printf("%d", a[i]);

        if (i != n - 1) {
            printf(" ");
        }
    }

    printf("\n");
}

// 插入排序
void insertionSort(int a[], int left, int right)
{
    for (int i = left + 1; i <= right; i ++) {
        int j = i - 1;
        int temp = a[i];

        while (a[j] > temp) {
            a[j + 1] = a[j];
            j --;
        }

        a[j + 1] = temp;

        // 是插入排序，则输出下一次迭代的结果
        if (isInsertionSort) {
            printf("Insertion Sort\n");
            printArray(a);
            break;
        }

        // 如果当前迭代后的数组等于mid数组
        if (cmpArray(a, mid)) {
            isInsertionSort = true;
        }
    }
}

// 将两个区间合并
void merge(int a[], int l1, int r1, int l2, int r2)
{
    int i = l1, j = l2;
    // 将归并后的数据放入temp数组，index为temp数组的下标
    int temp[MAX_N], index = 0;

    while (i <= r1 && j <= r2) {
        if (a[i] <= a[j]) {
            temp[index ++] = a[i ++];
        } else {
            temp[index ++] = a[j ++];
        }
    }

    // 将剩余数据也插入temp数组
    while (i <= r1) {
        temp[index ++] = a[i ++];
    }
    while (j <= r2) {
        temp[index ++] = a[j ++];
    }

    // 将合并后的序列赋值回原数组
    for (int i = 0; i < index; i ++) {
        a[l1 + i] = temp[i];
    }
}

// 归并排序-非递归
bool mergeSort(int a[])
{
    for (int step = 2; step / 2 < n; step *= 2) {
        // 如果不是初始序列并且a数组和mid数组相等
        if (step != 2 && cmpArray(a, mid)) {
            isMergeSort = true;
        }

        for (int i = 0; i < n; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 < n) {
                merge(a, i, mid, mid + 1, min(i + step - 1, n - 1));
            }
        }

        if (isMergeSort) {
            printf("Merge Sort\n");
            printArray(a);

            return true;
        }
    }

    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &origin[i]);
        temp[i] = origin[i];
    }
    for (int i = 0; i < n; i ++) {
        scanf("%d", &mid[i]);
    }

    // 如果不是归并排序，则为插入排序
    if (!mergeSort(origin)) {
        insertionSort(temp, 0, n - 1);
    }

    return 0;
}
