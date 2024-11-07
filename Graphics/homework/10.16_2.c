#include <stdio.h>
#include <stdlib.h>

int BTreeLast(int *arr, int first, int last) {
    int i, mid;
    for (i = first; i < last && arr[i] < arr[last]; i++) { //last一定是根节点
    } //当找到第一个不小于根节点的数时退出,剩下的元素在右子树上
    mid = i;
    for (i = mid; i < last && arr[i] > arr[last]; i++) {
    }
    if (i < last) {
        return 0;
    }
    if (first < mid - 1) {
            if (! BTreeLast(arr, first, mid - 1)) {
            return 0;
        }
    }
    if (mid < last - 1) {
            if (! BTreeLast(arr, mid, last - 1)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int arr[100];
    int i = 0;
    while (1) {
        if (scanf("%d ", &arr[i]) != 0) {

        }
        i++;
    }
   
    return 0;
}