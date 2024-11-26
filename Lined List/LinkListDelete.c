/*单链表结点的遍历与删除操作*/
#include <stdio.h>

typedef struct ElemType
{
    int serial;
    char name[50];
    int grade;
} ElemType;

typedef struct LNode 
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;


void deleteNode_even(LinkList L) {
    if (!L || !(L->next)) return;
    LinkList pre = L, p = L->next;
    while (p) {
        if (p->data.serial % 2 == 0) {
            pre->next = p->next;  // 删除p节点
            free(p);
            p = pre->next;  // 继续遍历
        } else {
            pre = p;
            p = p->next;
        }
    }
}
