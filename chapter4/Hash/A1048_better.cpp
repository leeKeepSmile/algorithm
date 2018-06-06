/**
 * @Author: lee
 * @Date:   2018-06-06T13:16:25+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-06T14:13:30+08:00
 */

// 散列
// A1048更好的算法
// 因为知道了面值的个数，并且都存入hashTable[]这个数组中，所以从i到m遍历，
// 自然就是从小面值到大面值，所以无需存储输入面值数据，也不用将输入数据进行排序。

#include <cstdio>

int main()
{
    int n, m, face;
    int hashTable[1001] = {0};

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &face);
        hashTable[face] ++;
    }

    for (int i = 1; i < m; i ++) {
        if (hashTable[i] && hashTable[m - i]) {
            // v1面值为m一半时，需要有2个或以上该面值的硬币
            if (i == m - i && hashTable[i] <= 1) {
                continue;
            }

            printf("%d %d", i, m - i);
            return 0;
        }
    }

    printf("No Solution");

    return 0;
}
