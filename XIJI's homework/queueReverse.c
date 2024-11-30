/*
【问题描述】
已知Q是一个非空队列，S是一个空栈。仅使用少量工作变量以及对队列和栈的基本操作，
编写一个算法，将队列Q中的所有元素逆置。
【输入形式】输入的第一行为队列元素个数，第二行为队列从首至尾的元素
【输出形式】输出队列的逆置
【样例输入】
3
1 2 3
【样例输出】
3 2 1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1; // 栈顶指针初始化为-1，表示栈为空

// 入栈操作
void push(int element) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = element; // 元素入栈
    } else {
        printf("Stack Overflow\n");
    }
}

// 出栈操作
int pop() {
    if (top != -1) {
        return stack[top--]; // 元素出栈
    } else {
        printf("Stack Underflow\n");
        return -1; // 栈为空时返回-1
    }
}

// 检查栈是否为空
int isEmpty() {
    return top == -1;
}

int main() {
    int n, i;
    scanf("%d", &n); // 读取队列元素个数

    int queue[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]); // 读取队列元素
        push(queue[i]); // 将队列元素入栈
    }

    // 将元素从栈中弹出并打印，实现逆置
    for (i = 0; i < n; i++) {
        printf("%d ", pop());
    }

    return 0;
}