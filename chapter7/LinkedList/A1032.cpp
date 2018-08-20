#include <cstdio>
#include <cstring>

const int MAX_N = 100010;

struct Node{
    // 数据域
    char data;
    // 指针域
    int next;
    // 结点是否在第一条链表中出现
    bool flag;
}node[MAX_N];

int main()
{
    for (int i = 0; i < MAX_N; i ++) {
        node[i].flag = false;
    }

    // s1,s2分别为两条链表的首地址
    int s1, s2, n;
    scanf("%d%d%d", &s1, &s2, &n);
    
    // 结点地址与后继结点地址
    int address, next;
    // 数据
    char data;
    for (int i = 0; i < n; i ++) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].data = data;
        node[address].next = next;
    }

    int p;
    // 枚举第一条链表的所有结点，令其出现次数为1
    for (p = s1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    for (p = s2; p != -1; p = node[p].next) {
        // 找到第一个已经在第一条链表中出现的结点
        if (node[p].flag == true) {
            break;
        }
    }

    if (p != -1) {
        printf("%05d\n", p);
    } else {
        printf("-1\n");
    }

    return 0;
}