/*二叉树遍历算法的应用*/
#include <stdio.h>
#include <stdlib.h>
#define Error -1
#define OK 1

/*二叉链表*/
typedef struct BiTreeNode 
{   char data;
    struct BiTreeNode *lchild, *rchild; 
}BiTreeNode, *BiTreePtr;

/*先序遍历建立二叉链表*/    /*当输入#号时表示空树*/
char ch;
int CreatBiTree(BiTreePtr T) {
    ch = getchar(); //只接受字符输入
    if (ch == '#') {
        T = NULL; //基准条件,递归退出条件
    }
    else {
        T->data = ch;
        CreatBiTree(T->lchild);
        CreatBiTree(T->rchild);
    }
    return OK;
}
/*复制二叉树*/  /*按照先序遍历复制二叉树*/
int CopyBiTree(BiTreePtr T, BiTreePtr *NewT) {
    if (T == NULL) {
        *NewT = NULL;
    }
    else {
        (*NewT)->data = T->data;
        CopyBiTree(T->lchild, (*NewT)->lchild);
        CopyBiTree(T->rchild, (*NewT)->rchild);
    }
    return OK;
}
/*计算二叉树的深度*/
int DepthBiTree(BiTreePtr T) {
    if (T == NULL) {
        return 0;
    }
    else {
        int m = DepthBiTree(T->lchild);
        int n = DepthBiTree(T->rchild);
        return m > n ? (m + 1) : (n + 1);
    }
}