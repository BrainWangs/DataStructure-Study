#include <stdio.h>
#include <stdlib.h> 

/*s为要调整的结点下标,n为数组长度-1,数组空间大小n+1,下标0~n*/
/*调整为大根堆*/
int adjustHeap(int arr[], int s, int n) {
    int temp = arr[s]; //保存根节点值
    /*寻找s的左右孩子中最大的那个, 初始为左孩子*/
    for (int i = 2 * s; i <= n; i *= 2) {
        //如果arr[i] < arr[i + 1], 即左孩子小于右孩子, i++则是选择右孩子
        if (i < n && arr[i] < arr[i + 1]) i++;
        //如果根节点大于它的两个孩子,则已经是堆,不需要调整
        if (temp >= arr[i]) break;
        //交换根节点和最大孩子,这里先将孩子i覆盖到s
        else {
            arr[s] = arr[i];
            s = i; //注意这里
        }
    }
    //如果break来到这里,相当于没有交换
    //如果循环结束来到这里,此时s=i,实际上是把根节点的值覆盖到位置i,完成了交换
    arr[s] = temp;
    return 0;
}

/*对于完全二叉树,大于n/2的都是叶子结点,从叶子结点向上调整,建立大根堆*/
void createHeap(int arr[], int n) {
    //注意原始数组arr[]的0位应该弃用,从1位开始,否则不满足双亲与孩子的下标关系
    for (int i = n / 2; i > 0; i--) {
        adjustHeap(arr, i, n);
    }
}

/*堆排序*/
void heapSort(int arr[], int n) {
    createHeap(arr, n); //建堆
    int temp;
    for (int i = n; i > 0; i--) {
        /*交换堆末尾和根结点*/
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        adjustHeap(arr, 1, i - 1);
    }
}

int main() {
    int arr[6] = {0, 9, 2, 4, 3, 7}; //n=6-1

    heapSort(arr, 5);

    for (int i = 1; i <= 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
