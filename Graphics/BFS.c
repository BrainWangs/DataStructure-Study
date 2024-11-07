/*广度优先遍历*/
#include <stdio.h>
#define MAXNUM 100 //定义邻接矩阵能表示的最大顶点数 n阶矩阵
#define MAXINT 32767

typedef struct 
{
    char vexs[MAXNUM]; //顶点表 用于存放顶点信息(字母编号)
    int matrix[MAXNUM][MAXNUM]; //邻接矩阵
    int vexnum, arcnum; //当前存储的顶点数,边数
}AMGraph;

/*邻接矩阵的广度优先算法*/
void BFS_AMG(AMGraph G, int v) {
    int visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = 0;
    }
    SqQueue Q; //入队和出队的都是顶点下标
    InitQueue(&Q);
/*====================初始化=====================*/
    EnQueue(&Q, v);
    printf("%c", G.vexs[v]); //访问操作
    visited[v] = 1;
    int u;
    while (QueueLength != 0) { //当队列不为空,就执行如下循环
        DeQueue(&Q, u); 
        for (int i = 0; i < G.vexnum; i++) { //把出队元素作为矩阵的行,依次查询行列,找未访问过的邻接顶点
            if (G.matrix[u][i] == 1 && visited[i] == 0) { 
                EnQueue(&Q, i);
                printf("%c", G.vexs[i]);
                visited[i] = 1;
            }
        }
    }
/*==================================================*/
}





/*====================广度优先要借助循环队列实现===================*/
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
/*================================================================*/