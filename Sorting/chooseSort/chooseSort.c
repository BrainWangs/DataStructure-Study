#include <stdio.h>
/*简单选择排序*/
int chooseSort(int *arr, int n) {
    int min;
    int temp;
    for (int i = 0; i < n; i++) {
        min = i; //i是未排序数组的第一个
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return 0;
}

int main() {
    int arr[5] = {4, 5, 2, 1, 3};
    chooseSort(arr, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}