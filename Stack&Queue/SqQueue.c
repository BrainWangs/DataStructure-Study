#include <stdio.h>
#include <stdlib.h>

#define MaxQSize 4
#define OK 1
#define Error -1

/*顺序队列存储结构*/
typedef struct SqQueue
{
    int *base;  //指向队列的基地址(数组的指针)
    int front;  //头指针(不是指针) 用与base的相对位置表示队列的头部元素(数组的下标)
    int rear;   //尾指针  同理表示队尾元素
}SqQueue;
/*普通顺序队列存在缺陷,会出现假溢出,因此改用循环顺序队列*/

/*循环队列初始化*/
int InitQueue(SqQueue *Q) {
    Q->base = (int *)malloc(sizeof(int) * MaxQSize);
    if (! Q->base) {
        printf("malloc error\n");
        return Error;
    }
    Q->front = 0;
    Q->rear = 0;
    return OK;
}
/*返回队内元素个数*/
int QueueLength(SqQueue Q) {
    if (! Q.base) {
        printf("Error\n");
        return Error;
    }
    return (Q.front - Q.rear + MaxQSize) % MaxQSize; //考虑可能为负数的情况
}

/*入队*/
int EnQueue(SqQueue *Q, int e) {
    if (Q->front == (Q->rear + 1) % MaxQSize) { //注意实际容量是MaxQSize-1
        printf("Queue is full\n");
        return Error;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MaxQSize;
    return OK; 
}

/*出队*/
int DeQueue(SqQueue *Q, int *e) {
    if (Q->front == Q->rear) {
        printf("Queue is empty\n");
        return Error;
    }
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MaxQSize;
    return OK;
}

/*取队头元素*/
int GetHeadQueue(SqQueue Q) {
    if (Q.front == Q.rear) {
        printf("Queue is empty\n");
        return Error;
    }
    return Q.base[Q.front];
}

int PutQueue(SqQueue *Q, int n) {
    int e;
    printf("Please input %d number\n", n);
    for (int i = 0; i < n; i++) {
        // printf("Input a number\n");
        scanf(" %d", &e);
        EnQueue(Q, e);
    }
    return OK;
}


int main() {
    SqQueue Q;
    InitQueue(&Q);
    PutQueue(&Q, 3);
    int e;
    for (int i = 0; i < 3; i++) {
        DeQueue(&Q, &e);
        printf("the %d.st is %d\n", i + 1, e);
    }

    return 0;
}