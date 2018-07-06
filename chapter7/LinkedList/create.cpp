/*
 * @Author: lee 
 * @Date: 2018-07-06 12:41:15 
 * @Last Modified by: lee
 * @Last Modified time: 2018-07-06 13:01:27
 */

// 创建链表

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

int main()
{
    int arr[5] = {5, 3, 6, 1, 2};
    node* L = create(arr);
    L = L->next;
    
    while (L != NULL) {
        printf("%d", L->data);
        L = L->next;
    }

    printf("\n");

    return 0;
}