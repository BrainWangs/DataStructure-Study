#include <stdio.h>
/*快速排序算法*/
int sort(int *arr, int low, int high); //排序函数
int quickSort(int *arr, int low, int high); //递归函数

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (n == 1) {
        printf ("%d ", arr[0]);
    }
    quickSort(arr, 0, n - 1);//调用
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int flag = 0;
int quickSort(int *arr, int low, int high) {
//low和high分别是数组的左右边界
    
    if (low < high) { //递归边界检查
        int pivot = sort(arr, low, high); 
        if (flag == 0) {
            printf("%d ", pivot + 1);
            flag = 1;
        }
        //从左往右划分边界依次递归
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }

    return 0;
}

int sort(int *arr, int low, int high) {
    int pivotValue = arr[low]; 

    while (low < high) {
        //从右向左查找,如果不满足循环条件,退出时的high就是不满足的那个,移动它
        while (low < high && arr[high] >= pivotValue) high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivotValue) low++;
        arr[high] = arr[low];
    }
    
    arr[low] = pivotValue; //low和high相等位置作为pivot的新位置
    return low; //返回pivot的位置下标
}