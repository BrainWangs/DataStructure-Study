#include <stdio.h>
#include <stdlib.h>
typedef struct LNode *LinkList;
struct LNode
{
    int data;
    LinkList next, pre; 
};
LinkList CreateLink(int n)
{
    LinkList l;
    l = (LinkList)malloc(sizeof(struct LNode));
    l->next = l->pre = l; // 因为创建头结点，所以只有一个结点故要自己与自己相连
    LinkList p = l, q;
    while (n--)
    {
        q = (LinkList)malloc(sizeof(struct LNode));
        scanf("%d", &q->data);
        p->next = q;
        q->pre = p;
        q->next = l;
        l->pre = q;
        p = q;
    }
    return l;
} // 创建初始化一个循环链表的操作
LinkList merge(LinkList l)
{
    LinkList p = l->next;
    int m = p->data;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p); // 删除第一个元素
    LinkList r = l->next;
    while (r->data < m && r->next != l)
    {
        r = r->next;
    } // 通过比较遍历找到插入点 但要注意可能到最后都没找到比删除的元素还要大的结点 所以要再讨论是否到了尾结点
    if (r->next != l)
    {
        LinkList q;
        q = (LinkList)malloc(sizeof(struct LNode));
        q->data = m;                   // 1
        q->pre = r->pre;               // 2
        q->next = r;                   // 3
        r->pre->next = q;              //4
        r->pre = q;                    // 5重要的五步
    } // 在尾结点之前找到了比大的故插入进去
    else
    {
        LinkList q;
        q = (LinkList)malloc(sizeof(struct LNode));
        q->data = m;
        r->next = q;
        q->pre = r;
        q->next = l;
        l->pre = q;
    } // 遍历到了尾还没有找到大的元素
    return l;
}
void show(LinkList l)
{
    LinkList p = l->next;
    while (p != l)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int main() // 主函数
{
    int n;
    LinkList L, K;
    scanf("%d", &n);
    L = CreateLink(n);
    K = merge(L);
    show(K);
    return 0;
}
