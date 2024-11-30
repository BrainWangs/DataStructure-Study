#include <stdio.h>
/*gpt编写*/
#define MAX_SIZE 100

// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序
int selectionSort(int arr[], int n) {
    int i, j, minIndex, comparisons = 0;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
    return comparisons;
}

// 冒泡排序
int bubbleSort(int arr[], int n) {
    int i, j, temp, comparisons = 0;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break; // 如果没有交换，排序完成
    }
    return comparisons;
}

// 堆排序的调整函数
void adjust(int arr[], int i, int n, int *comparisons) {
    int j, temp;
    temp = arr[i];
    j = 2 * i + 1;

    while (j < n) {
        if (j + 1 < n && arr[j] < arr[j + 1]) {
            j++;
        }
        (*comparisons)++;
        if (temp >= arr[j]) break;
        arr[(j - 1) / 2] = arr[j]; //(j-1)/2即上一个j, 也就是双亲节点
        j = 2 * j + 1;
    }
    arr[(j - 1) / 2] = temp;
}

// 堆排序
int heapSort(int arr[], int n) {
    int i, comparisons = 0;
    // 建立堆
    for (i = n / 2 - 1; i >= 0; i--) {
        adjust(arr, i, n, &comparisons);
    }
    // 排序
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        adjust(arr, 0, i, &comparisons);
    }
    return comparisons;
}

// 归并排序的合并函数
int merge(int arr[], int tmp[], int left, int leftend, int rightend) {
    int i = left, j = leftend + 1, q = left, comparisons = 0;
    while (i <= leftend && j <= rightend) {
        comparisons++;
        if (arr[i] <= arr[j]) {
            tmp[q++] = arr[i++];
        } else {
            tmp[q++] = arr[j++];
        }
    }
    //arr的两段数组长度不相等其中一个到达边界而退出,把剩下的直接写入tmp
    while (i <= leftend) tmp[q++] = arr[i++];
    while (j <= rightend) tmp[q++] = arr[j++];
    for (i = left; i <= rightend; i++) arr[i] = tmp[i]; //tmp覆盖arr
    return comparisons;
}

// 归并排序
int mergeSort(int arr[], int tmp[], int left, int right) {
    int mid, comparisons = 0;
    if (left < right) {
        mid = (left + right) / 2;
        comparisons += mergeSort(arr, tmp, left, mid);
        comparisons += mergeSort(arr, tmp, mid + 1, right);
        comparisons += merge(arr, tmp, left, mid, right);
    }
    return comparisons;
}

// 快速排序的分区函数
int quickSortPartition(int arr[], int left, int right) {
    int i, last, comparisons = 0;
    last = left;
    for (i = left + 1; i <= right; i++) {
        comparisons++;
        if (arr[i] < arr[left]) {
            swap(&arr[++last], &arr[i]);
        }
    }
    swap(&arr[left], &arr[last]);
    return last;
}

// 快速排序
int quickSort(int arr[], int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int pivotIndex = quickSortPartition(arr, left, right);
        comparisons += (right - left);
        comparisons += quickSort(arr, left, pivotIndex - 1);
        comparisons += quickSort(arr, pivotIndex + 1, right);
    }
    return comparisons;
}

int main() {
    int n, mode, comparisons;
    int arr[MAX_SIZE], tmp[MAX_SIZE];
    
    // 读取输入
    scanf("%d %d", &n, &mode);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 根据选择的排序方式调用对应的排序算法
    switch (mode) {
        case 1:
            comparisons = selectionSort(arr, n);
            break;
        case 2:
            comparisons = bubbleSort(arr, n);
            break;
        case 3:
            comparisons = heapSort(arr, n);
            break;
        case 4:
            comparisons = mergeSort(arr, tmp, 0, n - 1);
            break;
        case 5:
            comparisons = quickSort(arr, 0, n - 1);
            break;
        default:
            return 1;
    }

    // 输出排序结果和比较次数
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n%d\n", comparisons);

    return 0;
}
