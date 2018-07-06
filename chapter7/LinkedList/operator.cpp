/*
 * @Author: lee 
 * @Date: 2018-07-06 13:06:38 
 * @Last Modified by: lee
 * @Last Modified time: 2018-07-06 13:37:10
 */

// 链表的基本操作

#include <cstdio>
#include <cstdlib>

// 链表结点
struct node {
    int data;
    node* next;
};

// 创建链表
node* create(int arr[])
{
    // pre保存当前结点的前驱结点，head为头节点
    node *p, *pre, *head;
    // 创建头结点
    head = new node;
    // 头节点不需要数据域，指针域初始化为NULL
    head->next = NULL;
    pre = head;
    
    for (int i = 0; i < 5; i ++) {
        // 新建结点
        p = new node;
        p->data = arr[i];
        // 新结点指针域设为NULL
        p->next = NULL;
        pre->next = p;
        pre = p;
    }

    // 返回头结点指针
    return head;
}

// head为头结点；x为待查找元素
int search(node* head, int x)
{
    // 计数器
    int count = 0;

    // 从第一个结点开始
    node* p = head->next;
    while (p != NULL) {
        if (p->data == x) {
            count ++;
        }

        p = p->next;
    }

    return count;
}

// 插入元素
// head为头结点；pos为插入位置；x为待插入元素
void insert(node* head, int pos, int x)
{
    node* p = head;
    // 获得插入位置的前一个结点
    for (int i = 0; i < pos - 1; i ++) {
        p = p->next;
    }

    // 新建结点
    node* q = new node;
    // 数据域为x
    q->data = x;
    // 新建结点的下一个结点指向原先插入位置的结点
    q->next = p->next;
    // 前一个位置的结点指向新结点
    p->next = q;
}

// 删除元素
void del(node* head, int x)
{
    // 从第一个结点开始枚举
    node* p = head->next;
    // pre为p的前驱结点
    node* pre = head;

    while (p != NULL) {
        // 如果当前结点数据域为x
        if (p->data == x) {
            pre->next = p->next;
            // 释放p的内存空间
            delete(p);
            p = pre->next;
        } else {
            // 否则p和pre都后移一位
            pre = p;
            p = p->next;
        }
    }
}

int main()
{
    int arr[5] = {5, 3, 6, 1, 2};

    // 创建链表
    node* L = create(arr);
    L = L->next;
    while (L != NULL) {
        printf("%d", L->data);
        L = L->next;
    }
    printf("\n");

    // 查找元素
    printf("search operator: \n");
    node* Ls = create(arr);
    printf("count = %d\n", search(Ls, 2));

    // 插入元素
    node* Li = create(arr);
    insert(Li, 3, 4);
    Li = Li->next;
    while (Li != NULL) {
        printf("%d", Li->data);
        Li = Li->next;
    }
    printf("\n");

    // 删除元素
    node* Ld = create(arr);
    del(Ld, 6);
    Ld = Ld->next;
    while (Ld != NULL) {
        printf("%d", Ld->data);
        Ld = Ld->next;
    }
    printf("\n");

    return 0;
}