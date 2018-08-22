/*
 * @Author: lee 
 * @Date: 2018-08-22 23:27:52 
 * @Last Modified by: lee
 * @Last Modified time: 2018-08-22 23:46:51
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100005;

// 定义静态链表
struct Node {
    int address, data, next;
    // 结点是否在连表上
    bool flag;
} node[maxn];

bool cmp(Node a, Node b) {
    // 只要a和b中有一个无效结点，就把它放在后面
    if (a.flag == false || b.flag == false) {
        return a.flag > b.flag;
    } else {
        // 如果都是有效结点，则按要求排序
        return a.data < b.data;
    }
}

int main()
{
    // 初始化
    for (int i = 0; i < maxn; i ++) {
        node[i].flag = false;
    }

    int n, begin, address;
    scanf("%d%d", &n, &begin);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }
    
    int count = 0, p = begin;
    // 枚举链表，对flag进行标记，同时计数有效结点的个数
    while (p != -1) {
        node[p].flag = true;
        count ++;
        p = node[p].next;
    }

    // 特判，新链表中没有结点时输出0 -1
    if (count == 0) {
        printf("0 -1");
    } else {
        // 筛选有效结点，并按data从小到大排序
        sort(node, node + maxn, cmp);
        // 输出结果
        // 防止-1被%05d化，提前判断
        printf("%d %05d\n", count, node[0].address);
        for (int i = 0; i < count; i ++) {
            if (i != count - 1) {
                printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
            } else {
                printf("%05d %d -1", node[i].address, node[i].data);
            }
        }
    }

    return 0;
}