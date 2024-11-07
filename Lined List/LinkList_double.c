/*双向循环链表 Double Linked List*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define Error -1

/*定义双向结点*/
typedef struct LNode
{
    int data;             
    struct LNode *prior;
    struct LNode *next;   
}LNode, *LinkList;  

/*初始化*/
int Initialize(LinkList *L) {
    *L = (LNode *)malloc(sizeof(LNode));
    (*L) -> data = 0;
    (*L) -> prior = *L;
    (*L) -> next = *L;
    return OK;
}

/*取值*/    /*根据位置i查找并返回指针p*/
LNode *GetElem(LinkList L, int i) {
    LinkList p = L -> next; // L->next还是L,循环链表
    int j = 1;
    while(p != L && j < i) {
        p = p -> next;
        j++;
    }
    // if(p == L || j > i) {
    //     printf("GetElem Error\n");
    //         return NULL;
    // }
    return p;
}

/*查找*/    /*根据元素e查找对应位置i*/
LNode *LocateElem(LinkList L, int e) {
    LinkList p = L -> next;
    while(p -> data != e && p != L) {
        p = p -> next;
    }
    if(p == L) {
        printf("Locate Error\n");
        return NULL;
    }
    return p;
}

/*插入*/    /*在位置i插入, 当前位置结点i后移*/
int InsertElem(LinkList *L, int i, int e) {
    LinkList p = GetElem(*L, i);
    LinkList s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;
    s -> prior = p -> prior; //从前驱开始改
    p -> prior -> next = s;
    s -> next = p;
    p -> prior = s;
    return OK;
}
/*插入*/    /*当前位置结点i前移*/
// int InsertElem(LinkList *L, int i, int e) {
//     LinkList p = GetElem(*L, i - 1); //通过i-1位置操作
//     LinkList s = (LNode *)malloc(sizeof(LNode));
//     s -> data = e;
//     s -> next = p -> next; //从后继开始改,顺序不能更改
//     p -> next -> prior = s;
//     s -> prior = p;
//     p -> next = s;
//     return OK;
// }

/*删除*/
int DeleteElem(LinkList *L, int i) {
    LinkList p = GetElem(*L, i);
    p -> prior -> next = p -> next;
    p -> next -> prior = p -> prior;
    free(p);
    return OK;
}

/*前插法*/
int CreatList_H(LinkList *L, int length) {
    int e = 0;
    if(length < 1) return Error;
    printf("please input  numbers \n");
    for(int i = 1; i <= length; i++) {
        scanf("%d", &e);
        InsertElem(&(*L), i, e);
    }
    return OK;
}

/*后插法*/
int CreatList_R(LinkList *L, int length) {
    LinkList r = *L;
    int e = 0;
    if(length < 1) return Error;
    for(int i = 1; i <= length; i++) {
        scanf("%d", &e);
        LinkList s = (LNode *)malloc(sizeof(LNode));
        s -> data = e;
        s -> prior = r;
        r -> next = s;
        s -> next = *L;
        r = s;
    }
    return OK;
}
/*求表长*/
int ListLength(LinkList L) {
    LinkList p = L;
    int length = 0;
    while(p -> next != L) {
        p = p -> next;
        length++;
    }
    return length;
}

/*合并表*/
int MergeList(LinkList *L1, LinkList *L2) {
    LinkList p = *L1;
    LinkList q = *L2;
    while(p -> next != *L1) {
        p = p -> next;
    }
    q -> next -> prior = p -> next;
    p -> next = q -> next;
    while(q -> next != *L2) {
        q = q -> next;
    }
    q -> next = *L1;
    free(*L2);
    *L2 = NULL;
    return OK;

}




int main() {
    LinkList L;
    Initialize(&L);
    printf("Please input the length\n");
    int length;
    scanf("%d", &length);
    CreatList_H(&L, length);

    printf("List is here :\n");
    for(int i = 1; i <= length; i++){
        LinkList p = GetElem(L, i);
        printf("%3d", p -> data);
    }

    DeleteElem(&L, 2);
    printf("\nNow the List is here :\n");
    for(int i = 1; i <= length; i++){
        LinkList p = GetElem(L, i);
        printf("%3d", p -> data);
    }
    printf("\n");
    /*合并表验证*/
    LinkList L2;
    Initialize(&L2);
    printf("Please input the length\n");
    scanf("%d", &length);
    CreatList_H(&L2, length);

    MergeList(&L, &L2);
    length = ListLength(L);
    printf("\nNow the List is here :\n");
    for(int i = 1; i <= length; i++){
        LinkList p = GetElem(L, i);
        printf("%3d", p -> data);
    }

    return 0;
}