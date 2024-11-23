/*单链表 LInked List */
#include <stdio.h>
#include <stdlib.h>
// #include "LinkListMethods.h"
#define Error -1
#define OK 1

/*定义结点*/
typedef struct LNode
{
    int data;           // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;     // LinkList为定义的Lnode指针类型

int initialize(LinkList *L)
{                                        // 注意传入的是指针的指针, L是二级指针,*L是一级指针
    *L = (LNode *)malloc(sizeof(LNode)); // 使用malloc申请内存,malloc返回指针,赋给头指针*L
    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}
/*取值*/ /*取出位置i的结点数据并赋值给e*/
int GetElem(LinkList L, int i, int *e)
{
    LinkList p = L->next; // 创建指针p指向首元结点
    int j = 1;
    while (p && j < i)
    {                // 当p指向的不是空 且 计数器j小于目标点i时 当j=i-1时执行并退出
        p = p->next; // 使p向后移动一位
        j++;
    }
    if (!p || j > i)
    {
        printf("Error");
        return Error;
    }
    *e = p->data; // 获取地址上的值 进行修改
    return OK;
}
/*查找*/ /*根据给定值e比较并返回指针*/
LNode *LocateElem(LinkList L, int e)
{ // 理论上不使用二级指针好像也能正常运行
    LinkList p = L->next;
    while (p != NULL && p->data != e)
    { // 考虑p为null的情况
        p = p->next;
    }
    if (p == NULL)
    { // 若p因为空而退出while,提示错误信息
        // printf("Error");
        return NULL;
    }
    return p;
}

/*根据位置i查找并返回指针*/
LNode *LocateList(LinkList L, int i)
{
    LinkList p = L->next;
    int j = 1;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || j > i)
    {
        printf("Error\n");
        return NULL;
    }
    return p;
}

/*插入*/ /*在位置i插入数据e*/
int ListInsert(LinkList *L, int i, int e)
{
    LinkList p = *L;
    int j = 0;
    while (p && j < i - 1)
    { // 在位置i插入,指针p应该指向i-1的位置
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    { // i<=0时触发
        printf("Error");
        return Error;
    }
    LinkList s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/*删除*/ /*删除位置i的结点*/
int ListDelete(LinkList *L, int i)
{
    LinkList p = *L; // p指向首元结点
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
    {
        printf("Error");
        return Error;
    }
    LinkList q = p->next; // 用中间变量储存结点i方便后续释放内存操作
    p->next = q->next;    // 跳过位置i指向i+1结点
    free(q);
    return OK;
}

/*前插法*/
int CreatList_H(LinkList *L, int length)
{
    int e = 0;
    for (int i = 1; i <= length; i++)
    {
        printf("Please input the %d.st number\n", i);
        scanf("%d", &e);
        ListInsert(&(*L), i, e);
    }
    return OK;
}

/*后插法*/
int CreatList_R(LinkList *L, int length)
{
    LinkList r = *L; // 创建尾指针
    int e = 0;
    for (int i = 1; i <= length; i++)
    {
        printf("Please input the %d.st number\n", i);
        scanf("%d", &e);
        LinkList p = (LNode *)malloc(sizeof(LNode)); // 创建一个结点p
        p->data = e;
        r->next = p; // r -> next 是最后一个结点的指针域
        p->next = NULL;
        r = p;
    }
    return OK;
}

/*求表长*/
int ListLength(LinkList L)
{
    LinkList p = L;
    int length = 0;
    while (p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

/*两表合并*/
int MergeList(LinkList *L1, LinkList *L2)
{
    LinkList p = *L1;
    while (p->next != NULL)
    { // 找到L1的尾结点
        p = p->next;
    }
    p->next = (*L2)->next; // 将L1的尾结点指向L2的首元结点
    free(*L2);             // 释放L2的头结点
    *L2 = NULL;            // 将L2指针设置为NULL，避免野指针
    return OK;
}

/*遍历两个表的并集的值, 从小到大输出*/
int listSortprint(LinkList L1, LinkList L2)
{
    LinkList p1 = L1->next;
    LinkList p2 = L2->next;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            printf("%d ", p1->data);
            p1 = p1->next;
        }
        else if (p1->data > p2->data) {
            printf("%d ", p2->data);
            p2 = p2->next;
        }
        else if (p1->data == p2->data) {
            printf("%d ", p1->data);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        printf("%d ", p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        printf("%d ", p2->data);
        p2 = p2->next;
    }

    return 0;
}

int main()
{
    // LinkList L;
    // initialize(&L);
    // printf("输入创建的节点个数:\n");
    // int size;
    // scanf("%d", &size);
    // CreatList_R(&L, size);

    // printf("%d\n", ListLength(L));

    // LinkList L2;
    // initialize(&L2);
    // printf("输入创建的节点个数:\n");
    // scanf("%d", &size);
    // CreatList_R(&L2, size);

    // MergeList(&L, &L2);
    // int len = ListLength(L);
    // printf("here is the list :\n");
    // for (int i = 1; i <= len; i++)
    // {
    //     LinkList p = LocateList(L, i);
    //     printf("%-3d", p->data);
    // }

    LinkList La, Lb;
    initialize(&La);
    initialize(&Lb);
    int a, b;
    for (int i = 0;; i++)
    {
        if (scanf("%d", &a) != 1) {
            break;
        }
        if (LocateElem(La, a) != NULL) {
            i--;
            continue;
        }
        ListInsert(&La, i + 1, a);
        if (getchar() == '\n')
            break;
        
    }
    for (int i = 0;; i++)
    {
        if (scanf("%d", &b) != 1) {
            break;
        }
        if (LocateElem(Lb, b) != NULL) {
            i--;
            continue;
        }
        ListInsert(&Lb, i + 1, b);
        if (getchar() == '\n')
            break;
        
    }

    listSortprint(La, Lb);



    return 0;
}