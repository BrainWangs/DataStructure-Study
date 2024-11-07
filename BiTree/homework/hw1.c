/*已知一个二叉树的中序遍历序列和后序遍历序列，求这棵树的前序遍历序列*/
#include <stdio.h>
/*
1.由后序遍历找到根节点
2.由根节点划分中序遍历
3.由划分的新数组递归进入1
4.重复直到所有元素被遍历
5.构建二叉树
6.先序遍历输出
*/

typedef struct BiTreeNode 
{   int data;
    struct BiTreeNode *lchild, *rchild; 
}BiTreeNode, *BiTreePtr;


 int arr_middle[100];
 int arr_behind[100];
 int length1, length2;

int arrLength(int *arr);
int BiTreeCreate(int *head_m, int *rear_m, int *head_b, int *rear_b, BiTreePtr ptr, int length);
int* Locate(int *head, int *rear, int target);

int main() {
    length1 = arrLength(arr_middle);
    length2 = arrLength(arr_behind);
    /*传递四个头尾指针, 思路来自于python的列表切片*/
    int *head_middle = &arr_middle[0];
    int *rear_middle = &arr_middle[length1];
    int *head_behind = &arr_behind[0];
    int *rear_behind = &arr_behind[length2];
    BiTreePtr ptr;

    BiTreeCreate(head_middle, rear_middle, head_behind, rear_behind, ptr, length1);

    return 0;
}

/*接收不定长数组整形输入, 返回数组最大下标*/
int arrLength(int *arr) {
    int i = 0;
    for (i; ;i++) {
        scanf("%d", &arr[i]);
        if (getchar() == '\n') {
            break;
        }
    }
    return i;
}


/*使用四个首尾指针, 每次递归以根节点划分划分中序遍历数组为两个新数组,进入递归,找根节点, 构建二叉树*/
int count = 0;
int BiTreeCreate(int *head_m, int *rear_m, int *head_b, int *rear_b, BiTreePtr ptr, int length1) {
    ptr->data = *rear_b;
    count++;
    if (count == length1)
        return 0;

    int *rear = Locate(head_m, rear_m, *rear_b);
    BiTreeCreate(head_m, rear, head_b, rear, ptr->lchild, length1);

    int *head = Locate(head_m, rear_m, *rear_b);
    BiTreeCreate(head, rear_m, head, rear_b, ptr->rchild, length1);

    return 0;
}

/*遍历列表找到指定值的下标*/
int* Locate(int *head, int *rear, int target) {
        for (head; head <= rear; head++) {
            if (*head == target) {
                return head;
            }
        }
    return NULL;
}



