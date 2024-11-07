// #include <stdio.h>
// #include <stdlib.h>

// void rearrange_array(int arr[], int n) {
//     int *odd_arr = (int *)malloc(n * sizeof(int));  // 动态分配存储奇数的数组
//     int *even_arr = (int *)malloc(n * sizeof(int)); // 动态分配存储偶数的数组
//     int odd_index = 0, even_index = 0;
    
//     // 遍历数组，分别存储奇数和偶数
//     for (int i = 0; i < n; i++) {
//         if (arr[i] % 2 != 0) {
//             odd_arr[odd_index++] = arr[i];
//         } else {
//             even_arr[even_index++] = arr[i];
//         }
//     }
    
//     // 将奇数部分拷贝回原数组
//     for (int i = 0; i < odd_index; i++) {
//         arr[i] = odd_arr[i];
//     }
    
//     // 将偶数部分拷贝回原数组
//     for (int i = 0; i < even_index; i++) {
//         arr[odd_index + i] = even_arr[i];
//     }

//     // 释放动态分配的内存
//     free(odd_arr);
//     free(even_arr);
// }

// int main() {
//     int *arr = NULL;  // 初始化指针用于存储输入的整数
//     int size = 0;     // 当前已输入的整数个数
//     int capacity = 10; // 初始容量
//     int num;

//     // 动态分配初始存储空间
//     arr = (int *)malloc(capacity * sizeof(int));

//     printf("请输入一串整数（空格分隔，回车结束）: ");  //回车指手动输入\n

//     // 使用循环不断读取整数，直到输入结束
//     while (scanf("%d", &num) == 1) {
//         // 如果超过当前容量，重新分配更大的内存空间
//         if (size == capacity) {
//             capacity *= 2;  // 容量加倍
//             arr = (int *)realloc(arr, capacity * sizeof(int));
//         }
//         // 将读取到的整数存储在数组中
//         arr[size++] = num;
//     }
    
//     // 调整数组，将奇数放在左边，偶数放在右边
//     rearrange_array(arr, size);

//     // 输出调整后的数组
//     printf("调整后的数组为: ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     // 释放动态分配的内存
//     free(arr);
    
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rearrange_array(int arr[], int n) {
    int *odd_arr = (int *)malloc(n * sizeof(int));  // 动态分配存储奇数的数组
    int *even_arr = (int *)malloc(n * sizeof(int)); // 动态分配存储偶数的数组
    int odd_index = 0, even_index = 0;
    
    // 遍历数组，分别存储奇数和偶数
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd_arr[odd_index++] = arr[i];
        } else {
            even_arr[even_index++] = arr[i];
        }
    }
    
    // 将奇数部分拷贝回原数组
    for (int i = 0; i < odd_index; i++) {
        arr[i] = odd_arr[i];
    }
    
    // 将偶数部分拷贝回原数组
    for (int i = 0; i < even_index; i++) {
        arr[odd_index + i] = even_arr[i];
    }

    // 释放动态分配的内存
    free(odd_arr);
    free(even_arr);
}

int main() {
    char input[1000];  // 用于存储输入行的字符串
    int *arr = NULL;   // 初始化指针用于存储输入的整数
    int size = 0;      // 当前已输入的整数个数
    int capacity = 10; // 初始容量
    int num;
    char *token;

    // 动态分配初始存储空间
    arr = (int *)malloc(capacity * sizeof(int));

    // 提示用户输入
    printf("请输入一串整数（空格分隔，按Enter结束）: ");
    
    // 使用fgets读取整行输入
    fgets(input, sizeof(input), stdin);

    // 使用strtok分割字符串
    token = strtok(input, " \n");
    while (token != NULL) {
        // 将分割出的字符串转换为整数
        num = atoi(token);
        
        // 如果超过当前容量，重新分配更大的内存空间
        if (size == capacity) {
            capacity *= 2;  // 容量加倍
            arr = (int *)realloc(arr, capacity * sizeof(int));
        }
        
        // 将读取到的整数存储在数组中
        arr[size++] = num;

        // 继续分割下一个整数
        token = strtok(NULL, " \n");
    }

    // 调整数组，将奇数放在左边，偶数放在右边
    rearrange_array(arr, size);

    // 输出调整后的数组
    printf("调整后的数组为: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 释放动态分配的内存
    free(arr);
    
    return 0;
}
