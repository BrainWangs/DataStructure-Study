#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// 栈结构体
typedef struct {
    int data[MAX_SIZE]; // 存储栈元素
    int top;             // 栈顶指针
} Stack;

// 初始化栈
void initStack(Stack *stack) {
    stack->top = -1; // 初始栈为空
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 判断栈是否满
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->data[++(stack->top)] = value;
    }
}

// 出栈操作
int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
    return -1; // 如果栈为空，返回-1
}

int main() {
    int n;
    scanf("%d", &n); // 输入序列的长度

    int input[n], output[n];
    
    // 输入序列
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    // 输出序列
    for (int i = 0; i < n; i++) {
        scanf("%d", &output[i]);
    }

    Stack stack;
    initStack(&stack); // 初始化栈
    int inputIndex = 0; // 用于追踪输入序列的当前位置
    int popCount = 0;    // 出栈次数

    // 模拟栈的入栈和出栈过程
    for (int i = 0; i < n; i++) {
        // 试图将元素入栈直到栈顶为输出序列[i]
        while (inputIndex < n && (isEmpty(&stack) || stack.data[stack.top] != output[i])) {
            push(&stack, input[inputIndex++]); // 入栈操作
        }

        // 检查栈顶元素是否是当前输出序列的元素
        if (stack.data[stack.top] == output[i]) {
            pop(&stack);    // 出栈操作
            popCount++;     // 增加出栈次数
        } else {
            // 如果栈顶元素不匹配当前输出序列的元素，说明无法实现
            printf("0\n");
            return 0;
        }
    }

    // 如果所有的出栈操作都成功，则输出总的出栈次数
    printf("%d\n", popCount);
    return 0;
}
