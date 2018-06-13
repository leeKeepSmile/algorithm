/**
 * @Author: lee
 * @Date:   2018-06-13T16:57:56+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-13T18:00:44+08:00
 */

// two pointers

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 110;

int n;
// origin为原始序列；mid为某次迭代的序列；temp为原始序列的备份
int origin[MAX_N], mid[MAX_N], tempOrigin[MAX_N];

// 判断两个数组是否相等
bool isSame(int a[], int b[])
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
bool insertionSort()
{
    bool flag = false;

    for (int i = 1; i < n; i ++) {
        // 如果不是原始序列并且当前迭代序列与mid数组相同
        if (i != 1 && isSame(tempOrigin, mid)) {
            flag = true;
        }

        int j = i;
        int temp = tempOrigin[i];

        while (j > 0 && tempOrigin[j - 1] > temp) {
            tempOrigin[j] = tempOrigin[j - 1];
            j --;
        }

        tempOrigin[j] = temp;

        // 返回true之前，再迭代一次
        if (flag == true) {
            return true;
        }
    }

    return false;
}

// 归并排序，以下是最简单的写法；归并排序有更快的算法，见B1035.cpp。
bool mergeSort()
{
    bool flag = false;

    for (int step = 2; step / 2 < n; step *= 2) {
        // 如果不是原始序列并且当前迭代序列等于mid序列
        if (step != 2 && isSame(tempOrigin, mid)) {
            flag = true;
        }

        for (int i = 0; i < n; i += step) {
            sort(tempOrigin + i, tempOrigin + min(i + step, n));
        }

        // 在返回true之前再进行一次迭代
        if (flag == true) {
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
        tempOrigin[i] = origin[i];
    }
    for (int i = 0; i < n; i ++) {
        scanf("%d", &mid[i]);
    }

    // 输出结果
    if (insertionSort()) {
        printf("Insertion Sort\n");
        printArray(tempOrigin);
    } else {
        // 还原原始序列
        for (int i = 0; i < n; i ++) {
            tempOrigin[i] = origin[i];
        }

        // 归并排序
        mergeSort();
        printf("Merge Sort\n");
        printArray(tempOrigin);
    }

    return 0;
}
