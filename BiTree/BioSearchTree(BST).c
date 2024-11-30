#include <stdio.h>
#include <stdlib.h>
/*二叉搜索树(二叉排序树)的构建*/


/*二叉链表*/
typedef struct BiTreeNode 
{   int data;
    struct BiTreeNode *lchild, *rchild; 
}BTNode, *BTPtr;

void insertBST(BTPtr *T, int key) {
    if (!(*T)) {
        BTPtr S = (BTNode *)malloc(sizeof(BTNode));
        S->data = key;
        S->lchild = NULL;
        S->rchild = NULL;
        *T = S;
    }
    else if (key < (*T)->data)
        insertBST(&((*T)->lchild), key);
    else if (key > (*T)->data)
        insertBST(&((*T)->rchild), key);

}

/*创建二叉搜索树*/
void createBST(BTPtr *T, int arr[], int n) {
    //T是二级指针
    *T = NULL;
    int i = 0;
    while (i < n) {
        insertBST(T, arr[i]);
        i++;
    }
}

void printBST(BTPtr T) {
    if (!T) return;

    printBST(T->lchild);
    printf("%d ", T->data);
    printBST(T->rchild);
}


int main() {
    int n;    
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // getchar();
    BTPtr T;
    createBST(&T, arr, n);
    printBST(T);
    return 0;
}