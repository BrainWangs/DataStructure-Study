/*输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，
使得它们的和正好是输入的那个数字。要求时间复杂度是O(n)。
如果有多对数字的和等于输入的数字，输出任意一对即可      */
#include <stdio.h>
int arrlength(int*);
int sortAdd(int *, int);

/*使用头指针,尾指针*/
int sortAdd(int *arr, int result) {
    int length = arrlength(arr);
    int *head = &arr[0];
    int *rear = &arr[length - 1];

    while (*head + *rear != result) {
        if (*head + *rear < result) {
            head++;
            continue;
        }
        else if (*head + *rear > result) {
            rear--;
            continue;
        }
        if (head == rear) { //相遇时仍找不到说明不存在
            printf("NULL\n");
            return -1;
        }
    }
    printf("%d %d", *head, *rear);
    return 0;
}

int arrlength(int *arr) {
    int count = 0;
    for (count; arr[count] != NULL; count++) {
    }
    return count - 1; //返回数组最大下标
}

int main() {
    int result;
    int arr[100];
    for (int i = 0; ; i++) {
        scanf("%d", &arr[i]);
        if (getchar() == '\n')
            break;
    }
    scanf("%d", &result);
    sortAdd(arr, result);

    return 0;
}