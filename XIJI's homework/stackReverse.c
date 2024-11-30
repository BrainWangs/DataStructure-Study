#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10000  // 设置栈的最大容量

// 栈的结构体定义
typedef struct {
    char data[MAX_SIZE];
    int top;  // 栈顶指针
} Stack;

// 栈的初始化
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否满
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

// 出栈操作
char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';  // 如果栈为空，返回空字符
}

// 主函数实现
int main() {
    char input[10000];  // 用于存储输入的字符串
    fgets(input, sizeof(input), stdin);  // 读取一行输入

    // 去除末尾的 '@' 和换行符
    int len = strlen(input);
    if (input[len - 1] == '@') {
        input[len - 1] = '\0';  // 去掉 '@'
        len--;  // 更新字符串长度
    }
    // 去除末尾的换行符 '\n'（如果存在）
    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';  // 去掉换行符
    }

    // 查找 '&' 的位置
    char *ampersand = strchr(input, '&');
    if (ampersand == NULL) {
        printf("no\n");
        return 0;
    }

    // 拆分序列1和序列2
    int len1 = ampersand - input;  // 序列1的长度
    char seq1[10000], seq2[10000];

    strncpy(seq1, input, len1);
    seq1[len1] = '\0';  // 确保序列1是一个正确的字符串

    strcpy(seq2, ampersand + 1);  // 获取序列2

    // 使用栈来检查逆序
    Stack s;
    initStack(&s);

    // 将序列1的字符入栈
    for (int i = 0; i < len1; i++) {
        push(&s, seq1[i]);
    }

    // 检查序列2的字符是否与栈中字符匹配
    for (int i = 0; i < strlen(seq2) - 1; i++) {
        char c = pop(&s);
        if (c != seq2[i]) {
            printf("no\n");
            return 0;
        }
    }

    // 如果栈空且序列2已遍历完，则说明是逆序
    if (isEmpty(&s)) {
        printf("%d\n", len1);
    } else {
        printf("no\n");
    }

    return 0;
}
