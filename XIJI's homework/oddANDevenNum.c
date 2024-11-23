/*
【问题描述】调整输入数组A[0..n]，将其分为两部分，左边所有元素为奇数，右边所有元素为偶数
【输入形式】a0，b1，b2，a1，a2，b3，a3，a4
【输出形式】a0,a1,a2,a3,a4,b1,b2,b3
【样例输入】1，2，33，8，5
【样例输出】1，33，5，2，8
*/
#include <stdio.h>

void Sortfunc(int *arr, int n) {
    //对于原数组有n个元素, 用长度为2n的新数组储存排序元素
    int odd = 0;  //0~n-1
    int even = n; //n~2n-1
    int newArr[2 * n];
    //判断数字是偶数则放到even, 否则放到odd
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            newArr[even] = arr[i];
            even++;
        }
        else {
            newArr[odd] = arr[i];
            odd++;
        }
    }

    //输出(这个逗号的判别太麻烦了)
    for (int i = 0; i < odd; i++) {
        printf("%d", newArr[i]);
        if (even == n) {
            if (i + 1 < odd) {
                printf(",");
            }
        }
        else {
            if (i + 1 <= odd) {
                printf(",");
            }
        }        
    }
    for (int i = n; i < even; i++) {
        printf("%d", newArr[i]);
        if (i + 1 < even) {
            printf(",");
        }
    }
}

int main() {
    int n = 0;
    int arr[100];
    //记录输入元素个数
    for (int i = 0; i < 100; i++) {
        scanf("%d", &arr[i]);
        n++;
        if (getchar() == '\n') break;
    }

    Sortfunc(arr, n);


    return 0;
}
