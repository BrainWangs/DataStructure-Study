#include<stdio.h>
 
int BinarySearch(int *arr, int *c, int key, int n, int count) {
    int low = 0;
    int high = n - 1;
    int mid = low + high / 2;
    int result = -1; //这四个都是下标
    for (int i = 0; i < n; i++) {
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            high = mid - 1;
            mid = (low + high) / 2;
            c[i] = mid;
            count++;

        }
        else if (arr[mid] < key) {
            result = mid;
            low = mid + 1;
            mid = (low + high) / 2;
            c[i] = mid;
            count++;
        }
    }
    printf("&lsquo;no&rsquo;");
    return -1;
}

int main() {
    int arr[100]; int c[100];
    int i = 0;
    int N;
    scanf("%d", &N);
    for (i;i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    scanf("%d", &key);
    int count = 0;
    int result = BinarySearch(arr, c, key, i, count);
    if (result != -1) {
        printf("%d\n", arr[result]);
        for (int i = 0; i < count; i++) {
            printf("%d,", c[i]);
        }
    }

}