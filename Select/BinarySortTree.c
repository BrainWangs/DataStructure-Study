/*二叉排序树的实现*/
#include <stdio.h>

typedef struct BSNode {
    int elem;
    struct BSNode *lchild, *rchild;
} BSNode, *BSTree;

/*二叉排序树插入*/
void BST_insert(BSTree T, int elem) {
    //当前根节点为空时(空树或叶子结点)
    if (!T) {
        T = (BSNode *)malloc(sizeof(BSNode));
        T->elem = elem;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else {
        //比较插入元素和当前根节点下的元素大小,决定插入左子树还是右子树
        if (elem < T->elem)  
            BST_insert(T->lchild, elem);
        else if (elem > T->elem)
            BST_insert(T->rchild, elem);
    }
}

/*二叉排序树创建--反复调用插入函数*/
#define FLAG -1
void BST_create(BSTree T) {
    T = NULL;
    int elem;
    scanf("%d", &elem);
    while (elem != FLAG) { //使用FLAG作为结束标志
        BST_insert(T, elem);
        scanf("%d", &elem);
    } 
}

/*二叉排序树查找*/
BSNode* BST_select(BSTree T, int key) {
    //当树为空时,或查找到指定元素
    if (!T || T->elem == key) {
        return T;
    }
    //否则, 根据关键字和根节点的大小关系决定递归子树
    else if (key < T->elem) return BST_select(T->lchild, key);
    else if (key > T->elem) return BST_select(T->rchild, key);
}