/*二叉树递归遍历*/
#include <stdio.h>
#include <stdlib.h>
#define Error -1
#define OK 1

/*二叉链表*/
typedef struct BiTreeNode 
{   int data;
    struct BiTreeNode *lchild, *rchild; //左链域,右链域
}BiTreeNode, *BiTreePtr;
/*三叉链表*/
typedef struct TriTreeNode
{   int data;
    struct TriTreeNode *lchild, *rchild, *parent; //左链域,右链域,根
}TriTreeNode, *TriTreePtr;

/*三种遍历的区别在于访问data域的时机不同,并无本质区别*/
/*先序遍历*/
int Traverse_1(BiTreePtr T) {
    if (T) {
        printf("%d\n", T->data);
        Traverse(T->lchild);
        Traverse(T->rchild);
    }
    return OK;
}
/*中序遍历*/
int Traverse_2(BiTreePtr T) {
     if (T) {
        Traverse(T->lchild);
        printf("%d\n", T->data);
        Traverse(T->rchild);
    }
    return OK;
}
/*后续遍历*/
int Traverse_3(BiTreePtr T) {
     if (T) {
        Traverse(T->lchild);
        Traverse(T->rchild);
        printf("%d\n", T->data);
    }
    return OK;
}