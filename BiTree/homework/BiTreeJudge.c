/*判断一个遍历序列是否是一个二叉树的后序遍历结果*/
#include <stdio.h>

/*使用递归定义
划分左右子树,左子树所有元素比根节点小,右子树所有元素比根节点大
满足这一条件则是后序遍历,否则不是*/
int BiTreeJudge(int *arr, int start, int end) {
    //考虑空数组和单子树 
    if (start >= end) {
        return 1;
    } 
    //标记根节点
    int root = arr[end];
    //寻找第一个大于根节点的数
    int i;
    for (i = start; arr[i] < root; i++);
    int point = i;
    //检查右子树是否都大于根节点
    for (int i = point; i < end; i++) {
        if (arr[i] < root) 
            return 0;
    }
    //递归划分左右子树
    BiTreeJudge(arr, start, point - 1);
    BiTreeJudge(arr, point - 1, end - 1);
}

int main() {
    int arr[100];
    int i;
    for (i = 0; ; i++) {
        scanf("%d", &arr[i]);
        if (getchar() == '\n')
        break;
    }

    int state = BiTreeJudge(arr, 0, i);
    if (state == 1) {
        printf("true");
    }
    else {
        printf("false");
    }

    return 0;
}