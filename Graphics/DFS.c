/*深度优先遍历*/
#include <stdio.h>
#define MAXNUM 100 //定义邻接矩阵能表示的最大顶点数 n阶矩阵
#define MAXINT 32767

typedef struct 
{
    char vexs[MAXNUM]; //顶点表 用于存放顶点信息(字母编号)
    int matrix[MAXNUM][MAXNUM]; //邻接矩阵
    int vexnum, arcnum; //当前存储的顶点数,边数
}AMGraph;

/*邻接矩阵深度优先遍历*/
void DFS_AMG(AMGraph G, int v) { //v表示顶点所在邻接矩阵的下标
    int visited[G.vexnum];
    for (int i = 0; i < G.vexnum; i++) { //初始化访问表0
        visited[i] = 0;
    }
    printf("%c", G.vexs[v]);
    visited[v] = 1; //对于已访问的顶点,记为1
    for (int w = 0; w < G.vexnum; w++) { //从v所在行开始从左向右遍历,w表示与v相对的另一个顶点下标
        if (G.matrix[v][w] != MAXINT && visited[w] != 1) { //凡遇到连通顶点且未访问过,进入递归
            DFS_AMG(G, w);
        }
    }
}