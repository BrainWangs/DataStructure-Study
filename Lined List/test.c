#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define Error -1

/* 定义结点 */
typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

/* 初始化 */
int Initialize(LinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    if (!(*L)) return Error;
    (*L)->data = 0;
    (*L)->next = *L; // 自指针形成循环链表
    return OK;
}

/* 取值 */
int GetElem(LinkList L, int i, int *e) {
    if (i < 1) {
        printf("Invalid index\n");
        return Error;
    }
    LinkList p = L->next;
    int j = 1;
    while (p != L && j < i) {
        p = p->next;
        j++;
    }
    if (p == L || j > i) {
        printf("GetElem Error: Index out of bounds\n");
        return Error;
    }
    *e = p->data;
    return OK;
}

/* 查找 */
LNode *LocateElem(LinkList L, int e) {
    LinkList p = L->next;
    while (p != L && p->data != e) {
        p = p->next;
    }
    if (p == L) {
        printf("Locate Error: Element not found\n");
        return NULL;
    }
    return p;
}

/* 插入 */
int InsertElem(LinkList L, int i, int e) {
    if (i < 1) {
        printf("Invalid position\n");
        return Error;
    }
    LinkList p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j != i - 1) {
        printf("Insert Error: Invalid position\n");
        return Error;
    }
    LinkList s = (LNode *)malloc(sizeof(LNode));
    if (!s) return Error;
    s->data = e;
    s->next = p->next;
    p->next = s;
    printf("Inserted successfully!\n");
    return OK;
}

/* 删除 */
int DeleteElem(LinkList L, int i) {
    if (i < 1) {
        printf("Invalid position\n");
        return Error;
    }
    LinkList p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L || j != i - 1) {
        printf("Delete Error: Invalid position\n");
        return Error;
    }
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    printf("Deleted successfully!\n");
    return OK;
}

/* 前插法 */
int CreatList_H(LinkList L, int length) {
    int e;
    for (int i = 1; i <= length; i++) {
        printf("Please input a number: ");
        scanf("%d", &e);
        InsertElem(L, i, e);
    }
    return OK;
}

int main() {
    LinkList L;
    Initialize(&L);
    printf("Input the list length: ");
    int length;
    scanf("%d", &length);
    CreatList_H(L, length);

    int e;
    if (GetElem(L, 2, &e) == OK) {
        printf("Element at position 2 is %d\n", e);
    }

    return 0;
}
