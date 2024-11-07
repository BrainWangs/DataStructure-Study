#include <stdio.h>
#define MAXNUM 100 //定义邻接矩阵能表示的最大顶点数 n阶矩阵
#define MAXINT 32767

typedef struct 
{
    char vexs[MAXNUM]; //顶点表 用于存放顶点信息(字母编号)
    int matrix[MAXNUM][MAXNUM]; //邻接矩阵
    int vexnum, arcnum; //当前存储的顶点数,边数
}AMGraph;

/*邻接矩阵法创建无向网*/
void AMCreatGraph(AMGraph *G) {
    scanf("%d %d", &(G->vexnum), &(G->arcnum)); //总顶点数,总边数
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%c ", &(G->vexs[i])); //输入顶点信息
    }
    for (int i = 0; i < G->vexnum; i++) {
        for (int j = 0; j < G->vexnum; j++) {
            G->matrix[i][j] = MAXINT; //初始化为最大权值,表示不连通
        }
    }
/*===================初始化=========================*/
    char v1, v2;
    int weight;
    for (int i = 0; i < G->arcnum; i++) {
        scanf("%c %c %d", &v1, &v2, &weight); //指定两个顶点,指定权值,建立关系
        int x = LocateVex(*G, v1);
        int y = LocateVex(*G, v2);
        G->matrix[x][y] = weight;
        G->matrix[y][x] = weight;   //无向图的邻接矩阵具有对称性
    }
/*=====================结束==========================*/
}

/*根据字符查找顶点表 返回顶点下标*/
int LocateVex(AMGraph G, char vex) {
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vexs[i] == vex) {
            return i;
        }
    }
    return -1;
}

