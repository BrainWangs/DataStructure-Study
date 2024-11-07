#include <stdio.h>
/*折半查找 基本模版*/

// int Select_bin(int *arr, int target, int n) {
//     int low = 0;
//     int high = n - 1;
//     int mid = (low + high )/ 2;
//     int result = -1; //这四个都是下标
//     for (int i = 0; i < n; i++) {
//         if (arr[mid] > target) {
//             high = mid - 1;
//             mid = (low + high ) / 2;
//         }
//         else if (arr[mid] < target) {
//             result = mid;
//             low = mid + 1;
//             mid = (low + high ) / 2;
//         }
//     }
//     return result;
// }

int Select_Binary(int *arr, int target, int n) {
    int low = -1;
    int high = n;
    while (low + 1 != high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] < target) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int target;
    int arr[100];
    int n = 0;
    for (int i = 0; ; i++) {
        scanf("%d", &arr[i]);
        n++;
        if (getchar() == '\n')
            break;
    }
    scanf("%d", &target);
    int result = Select_Binary(arr, target, n);
    printf("%d", result);

    return 0;
}