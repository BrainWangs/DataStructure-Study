/*插入排序*/
#include <stdio.h>

void insertSort(int *arr, int n) {
    int j;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; temp < arr[j] && j >= 0; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

int main() {
    int arr[5] = {4, 5, 5, 3, 2};
    insertSort(arr, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}