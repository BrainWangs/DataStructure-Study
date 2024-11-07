#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

/*使用邻接矩阵的DFS*/

int visited[MAX_VERTICES]; // 记录顶点是否被访问
int cc[MAX_VERTICES];      // 记录顶点所属的连通分量编号
int numCC = 0;             // 连通分量的数量

void DFS(int v, int adjMatrix[][MAX_VERTICES], int nVertices) { //传入形参当前结点v,邻接矩阵数组,节点个数nVer
    int i;
    visited[v] = 1; // 标记顶点v为已访问
    cc[v] = numCC; // 将顶点v分配到当前连通分量

    for (i = 0; i < nVertices; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) { // 检查是否存在边且顶点i未被访问
            DFS(i, adjMatrix, nVertices); // 对顶点i进行DFS
        }
    }
}

void findCC(int adjMatrix[][MAX_VERTICES], int nVertices) {
    int i;
    for (i = 0; i < nVertices; i++) {
        visited[i] = 0; // 初始化visited数组
        cc[i] = -1;     // 初始化cc数组
    }

    for (i = 0; i < nVertices; i++) {
        if (!visited[i]) { // 如果顶点i未被访问
            numCC++; // 增加连通分量的数量
            DFS(i, adjMatrix, nVertices); // 从顶点i开始DFS
        }
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    int nVertices, i, j;

    // 输入顶点数
    // printf("Enter number of vertices: ");
    scanf("%d", &nVertices);

    // 初始化邻接矩阵
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    // 输入边信息
    // printf("Enter edges (u v):\n");
    for (i = 0; i < nVertices; i++) {
        for (j = 0; j < nVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // 寻找连通分量
    findCC(adjMatrix, nVertices);

    // 输出连通分量
    // printf("Connected Components:\n");
    // for (i = 0; i < nVertices; i++) {
    //     printf("Vertex %d is in component %d\n", i, cc[i]);
    // }
    printf("%d", numCC);

    return 0;
}