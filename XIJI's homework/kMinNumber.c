#include <stdio.h>

// 简单选择排序
int chooseSort(int *arr, int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) { // 遍历到 n - 1
        min = i; // 假设当前元素是最小值
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        // 交换当前位置和最小值的位置
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return 0;
}

int main() {
    int arr[100];
    int i = 0;

    while (1) {
        scanf("%d", &arr[i]);
        i++;
        if (getchar() == '\n') break;
    }
    int k;
    scanf("%d", &k);

    chooseSort(arr, i);

    for (int j = 0; j < k; j++) {
        printf("%d ", arr[j]);
    }


    return 0;
}
