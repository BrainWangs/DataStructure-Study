/*哈夫曼树*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define Error -1


/*哈夫曼树存储结构*/    /*存储于1维数组中*/
typedef struct 
{
    int weight; //结点的权值
    int parent, lchild, rchild; //双亲,左孩子,右孩子下标
}HTNode, *HuffmanTree;

int Select(HuffmanTree T, int i, int *s1, int *s2);

/*哈夫曼树的构建*/
int CreatHuffmanTree(HuffmanTree *T, int n) {
    int m = 2 * n - 1;
    *T = (HTNode *)malloc(sizeof(HTNode) * m + 1); //创建2n个空间的一维数组
    for (int i = 1; i <= m; i++) { //初始化,从下标1到m
        (*T)[i].parent = 0;
        (*T)[i].lchild = 0;
        (*T)[i].rchild = 0;
    }
    for (int i = 1; i <= m; i++) { //输入权值weight
        scanf("%d", &(*T)[i].weight);
    }
/*=======================================================*/

    int s1, s2;
    for (int i = n + 1; i <= m ; i++) { //m=2n-1 是数组的末尾下标
        SelectMin(*T, i - 1, &s1, &s2); //注意是i-1,此时的i为空, 权值为0
        T[s1]->parent = i;  T[s2]->parent = i;
        T[i]->weight = T[s1]->weight + T[s2]->weight;
        T[i]->lchild = s1;  T[i]->rchild = s2;
    }
}



/*遍历求数组中最小的两个元素数组下标*/
void SelectMin(HuffmanTree T , int n, int* s1, int* s2) {
    int min1 = 1;
    int min2 = 2;
    for (int i = 3; i <= n; i++) {
        if (T[i].weight < T[min1].weight) {
            min2 = min1;
            min1 = i;
        }
        else if (T[i].weight < T[min2].weight) {
            min2 = i;
        }
    }
    *s1 = min1;
    *s2 = min2;     
}

/*哈夫曼树编码*/

