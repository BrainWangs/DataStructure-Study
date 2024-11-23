#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define OK 1
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;
typedef struct LNode
{
    ElemType value;
    struct LNode *next;
} LNode, *LinkList;

Status InitList_L(LinkList *L)
{
    (*L) = (LinkList)malloc(sizeof(LNode));
    if (!(*L))
        exit(OVERFLOW);
    (*L)->next = NULL;

    return OK;
}

Status CreateList_HL(LinkList *L)
{
    ElemType tmp;
    LinkList q, p = (*L);
    while (scanf("%d", &tmp))
    {
        q = (LinkList)malloc(sizeof(LNode));
        if (!q)
            exit(OVERFLOW);
        q->value = tmp;
        q->next = p->next;
        p->next = q;
        p = p->next;
        if (getchar() != ' ')
        {
            q->next = NULL;
            break;
        }
    }

    return OK;
}

Status MergeList_L(LinkList L1, LinkList L2, LinkList *L3)
{
    LinkList p1 = L1->next;
    LinkList p2 = L2->next;
    LinkList p3 = (*L3);
    LinkList q = NULL;
    while (p1 && p2)
    {
        if (p1->value <= p2->value)
        {
            if (q == NULL || p1->value > q->value)
            {
                q = (LinkList)malloc(sizeof(LNode));
                q->value = p1->value;
                q->next = p1->next;
                p3->next = q;
                p3 = p3->next;
            }
            p1 = p1->next;
        }
        else
        {
            if (q == NULL || p2->value > q->value)
            {
                q = (LinkList)malloc(sizeof(LNode));
                q->value = p2->value;
                q->next = p2->next;
                p3->next = q;
                p3 = p3->next;
            }
            p2 = p2->next;
        }
    }
    if (!p1)
    {
        while (p2)
        {
            if (p2->value > q->value)
            {
                q->next = p2;
                q = q->next;
            }
            p2 = p2->next;
        }
        q->next = NULL;
    }
    else
    {
        while (p1)
        {
            if (p1->value > q->value)
            {
                q->next = p1;
                q = q->next;
            }
            p1 = p1->next;
        }
        q->next = NULL;
    }

    return OK;
}

Status PrintList_L(LinkList L)
{
    LinkList p = L->next;
    while (p)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");

    return OK;
}

int main()
{
    LinkList L1, L2, L3;
    InitList_L(&L1);
    InitList_L(&L2);
    InitList_L(&L3);
    CreateList_HL(&L1);
    CreateList_HL(&L2);
    MergeList_L(L1, L2, &L3);
    PrintList_L(L3);
    return 0;
}
