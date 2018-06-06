/**
 * @Author: lee
 * @Date:   2018-06-06T12:43:34+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-06T13:07:05+08:00
 */

// 散列

// 注意点：hashTable的数组大小不能只设置500，因为（m - face[i]）可能比
// 500来的大，所以数组大小要设置大一点，不然其中一个测试点会不通过。

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int face[100000];
    // 面值 => 该面值的硬币个数
    int hashTable[1005] = {0};

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &face[i]);
        hashTable[face[i]] ++;
    }

    // 从小到大排序面值
    bool hasSolution = false;
    sort(face, face + n);
    for (int i = 0; i < n; i ++) {
        // 当前面值大于m的一半时，跳出循环
        if (face[i] > m / 2) {
            break;
        }

        // 设两个硬币的面值为v1, v2.若v1 != v2且v2面值的硬币存在时，输出v1 v2
        // 若v1 = v2时，则该面值的硬币数量必须大于1
        if (
            (face[i] != m - face[i] && hashTable[m - face[i]] > 0) ||
            (face[i] == m - face[i] && hashTable[face[i]] > 1)
        ) {
            hasSolution = true;
            printf("%d %d", face[i], m - face[i]);
            break;
        }
    }

    if (!hasSolution) {
        printf("No Solution");
    }

    return 0;
}
