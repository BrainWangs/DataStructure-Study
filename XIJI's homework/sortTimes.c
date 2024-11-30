#include <stdio.h>
#include <stdlib.h>
/*返回指定排序的比较次数*/
int count = 0;

/*选择排序*/
void chooseSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[minPos])
                minPos = j;
        }
        temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
}
/*冒泡排序*/
void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*堆排序*/
void adjustHeap(int arr[], int s, int n) {
    int temp = arr[s]; // 保存根节点值
    
    /*寻找s的左右孩子中最大的那个, 初始为左孩子*/
    for (int i = 2 * s; i <= n; i *= 2) {
        // 如果arr[i] < arr[i + 1], 即左孩子小于右孩子, i++则是选择右孩子
        if (i < n && arr[i] < arr[i + 1])
            i++;
        // 如果根节点大于它的两个孩子,则已经是堆,不需要调整
        count++;
        if (temp >= arr[i]) {
            break;
        }
        // 交换根节点和最大孩子,这里先将孩子i覆盖到s
        else {
            arr[s] = arr[i];
            s = i; // 注意这里
        }
    }
    arr[s] = temp;
}
/*对于完全二叉树,大于n/2的都是叶子结点,从叶子结点向上调整,建立大根堆*/
void createHeap(int arr[], int n) {
    // 注意原始数组arr[]的0位应该弃用,从1位开始,否则不满足双亲与孩子的下标关系
    for (int i = n / 2; i > 0; i--) {
        adjustHeap(arr, i, n);
    }
}

/*堆排序*/
void heapSort(int arr[], int n) {
    createHeap(arr, n); // 建堆
    int temp;
    for (int i = n; i > 0; i--)
    {
        /*交换堆末尾和根结点*/
        temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        adjustHeap(arr, 1, i - 1);
    }
}

/*二路归并*/
void merge(int x[], int tmp[], int left, int leftend, int rightend)
{
    int i = left, j = leftend + 1, q = left;
    while (i <= leftend && j <= rightend)
    {   
        count++;
        if (x[i] <= x[j])
        {
            tmp[q++] = x[i++];
        }
        else
            tmp[q++] = x[j++];
    }

    while (i <= leftend)

        tmp[q++] = x[i++];

    while (j <= rightend)

        tmp[q++] = x[j++];

    for (i = left; i <= rightend; i++)

        x[i] = tmp[i];
}

int S[100];
void MSort(int R[], int T[], int low, int high)
{ // R[low..high]归并排序后放入T[low..high]中

    if (low == high)
        T[low] = R[low];
    else
    {
        int mid = (low + high) / 2;
        MSort(R, S, low, mid); 
        MSort(R, S, mid + 1, high);

        merge(S, T, low, mid, high);
    } 
}
void MergeSort(int L[], int n)
{ // 对顺序表L进行归并排序
    MSort(L, L, 1, n);
}


/*快排*/
int sort(int arr[], int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        for (; low < high && arr[high] >= pivot; high--) count++;
        arr[low] = arr[high];
        for (; low < high && arr[low] <= pivot; low++) count++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low; // 返回pivot的下标
}

void fastSort(int arr[], int low, int high)
{
    if (low >= high) return;
    int pivotPos = sort(arr, low, high);
    fastSort(arr, low, pivotPos - 1);
    fastSort(arr, pivotPos + 1, high);
}

int main()
{
    //count = 0; // init
    int n, function;
    scanf("%d %d", &n, &function);
    int *arr = NULL;
    if (function == 3)
    {
        arr = (int *)malloc((sizeof(int) * n + 1));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    else
    {
        arr = (int *)malloc((sizeof(int) * n));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }
    int temp[100];
    switch (function)
    {
    case 1:
        chooseSort(arr, n);
        break;
    case 2:
        bubbleSort(arr, n);
        break;
    case 3:
        heapSort(arr, n); // 注意堆排序传的是元素个数或者说末尾下标
        break;
    case 4:
        MergeSort(arr, n);
        break;
    case 5:
        fastSort(arr, 0, n - 1);
    }

    if (function == 3) {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");    
    printf("%d", count);

    return 0;
}