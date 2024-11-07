/*循环链表 Circular Linked List*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define Error -1

/*定义结点*/
typedef struct LNode
{
    int data;             //数据域
    struct LNode *next;   //指针域
}LNode, *LinkList;  //LinkList为定义的Lnode指针类型

/*初始化*/
int Initialize(LinkList *L) {
    (*L) = (LNode *)malloc(sizeof(LNode));
    (*L) -> data = 0;
    (*L) -> next = (*L); //========不同点==========
    return OK;
}

/*取值*/
int GetElem(LinkList L, int i, int *e) {
    LinkList p = L -> next;
    int j = 1;
    while(p != L && j < i) {
        p = p -> next;
        j++;
    }
    if(p == L) {
        printf("p == L Error\n");
        return Error;
    } 
    else if(j > i) {
        printf("j > i Error\n");
        return Error;
    }
    *e = p -> data;
    return OK;
}

/*查找*/
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

/*插入*/
int InsertElem(LinkList *L, int i, int e) {
    LinkList p = *L;
    int j = 0;
    while(p -> next != *L && j < i - 1) {
        p = p -> next;
        j++;
    }
    if(p -> next == *L && j > i - 1) { //注意是&&
        printf("Insert Error\n");
        return Error;
    }
    LinkList s = (LNode *)malloc(sizeof(LNode));
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    printf("Successfully!!!\n");
    return OK;
}

/*删除*/
int DeleteElem(LinkList *L, int i) {
    LinkList p = *L;
    int j = 0;
    while(p -> next != *L && j < i - 1) {
        p = p -> next;
        j++;
    }
    if(p -> next == *L || j > i) {
        printf("Delete Error\n");
        return Error;
    }
    LinkList q = p -> next;
    p -> next = q -> next;
    free(q);
    return OK;
}

/*前插法*/
int CreatList_H(LinkList *L, int length) {
    int e;
    for(int i = 1; i <= length; i++) {
        printf("Please input a int number\n");
        scanf("%d", &e);
        InsertElem(&(*L), i, e); //注意写法 (*L)才是链表的一级指针
    }
    return OK;
}

/*后插法*/
int CreatList_R(LinkList *L, int length) {
    LinkList r = *L;
    int e = 0;
    for(int i = 1; i <= length; i++) {
        printf("Please input a int number\n");
        scanf("%d", &e);
        LinkList p = (LNode *)malloc(sizeof(LNode));
        p -> data = e;
        p -> next = *L; //=========唯一区别============
        r -> next = p;
        r = p;
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

/*两表合并*/
int MergeList(LinkList *L1, LinkList *L2) {
    LinkList p = *L1;
    LinkList q = *L2;
    
    while(p -> next != *L1) {
        p = p -> next;
    }
    p -> next = q -> next; //L1的尾链接L2的首元结点
    while(q -> next != *L2) {
        q = q -> next;
    }
    q -> next = *L1; //L2的尾链接L1的头结点
    free(*L2); //释放L2头结点
    *L2 = NULL;
    return OK;
}


int main() {
    LinkList L1;
    Initialize(&L1);
    printf("input the list length with a number\n");
    int length; 
    scanf("%d", &length);
    CreatList_R(&L1, length);

    // int e = 0;
    // GetElem(L, 2, &e);
    // printf("the node %d is %d\n", 2, e);

    // DeleteElem(&L, 2);
    // GetElem(L, 2, &e);
    // printf("the node %d is %d\n", 2, e);
    printf("the L1 length is %d \n", ListLength(L1));

    LinkList L2;
    Initialize(&L2);
    printf("input the list length with a number\n");
    scanf("%d", &length);
    CreatList_R(&L2, length);
    
    MergeList(&L1, &L2);
    length = ListLength(L1);
    printf("Now the L1 length is %d \n", length);
    /*合并表验证*/
    LinkList p = L1 -> next;
    for(int i = 1; i <= length; i++) {
        printf("%-4d", p -> data);
        p = p -> next;
    }

    return 0;
}