#include <stdio.h>
#include <stdlib.h>

#define MaxQSize 4
#define OK 1
#define Error -1

/*链式队列结点*/
typedef struct QNode 
{
    int data;
    struct QNode *next;
}QNode, *QPtr;

typedef struct LinkQueue 
{
    QPtr front; //front始终指向头结点
    QPtr rear;
}LinkQueue;
/*初始化*/
int InitQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QNode *)malloc(sizeof(QNode));
    if (! Q->front) {
        return Error;
    }
    Q->front->next = NULL; //头结点置空
    return OK;
}

/*入队*/
int EnQueue(LinkQueue *Q, int e) {
    QPtr p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return OK;
}   

/*出队*/
int DeQueue(LinkQueue *Q, int *e) {
    if (Q->front == Q->rear) { //判断队是否为空
        printf("Queue is empty\n");
        return Error;
    }
    QPtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p) { //当被删除的是最后一个元素时,队空
        Q->rear = Q->front;
    }
    free(p); //释放p指向的空间
    p = NULL; //初始化p 避免野指针
    return OK;
}
/*取队头元素*/
int GetHeadQueue(LinkQueue Q) {
    if (Q.front == Q.rear) {
        printf("Queue is empty\n");
        return Error;
    }
    return Q.front->next->data;
}