/*单链式栈*/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define Error -1

/*定义链式栈的结点*/
typedef struct SNode
{
    int data;
    struct SNode *next;
} SNode, *LinkStack;

/*初始化*/ /*LinStack S 作为栈顶指针*/
int Init_LkStack(LinkStack *S)
{              // 二级指针,注意
    *S = NULL; // 空栈没有结点,栈顶指针指向空
    return OK;
}
/*入栈*/ /*创建新结点入栈*/
int Push_LkStack(LinkStack *S, int e)
{
    LinkStack p = (SNode *)malloc(sizeof(SNode));
    p->data = e;
    p->next = *S; // S指向新元素入栈前的顶栈结点
    *S = p;       // S必须 应该使用二级指针
    return OK;
}
/*出栈*/
int Pop_LkStack(LinkStack *S, int *e)
{
    if (!*S)
    {
        printf("Stack Empty\n");
        return Error;
    }
    LinkStack p = *S; // 为了释放当前结点空间,要借助中间量p
    *e = p->data;
    *S = p->next; //======================================<<<<<
    free(p);
    return OK;
}
/*取栈顶元素*/
int GetTop_LkStack(LinkStack S)
{
    if (!S)
    {
        printf("Stack Empty\n");
        return Error;
    }
    return S->data;
}

/*分治法遍历查找链式栈*/
void TraverseList(LinkStack S)
{
    if (S == NULL)
    {
        printf("Done\n"); // 基准条件
        return;
    }
    else
    {
        printf("%d.st\n", S->data); //<<<<<<<<问题,最后会多输出一个数
                                    // 问题已解决,是初始化没有使用二级指针导致出问题,但是不知道具体原因
        TraverseList(S->next);      // 递归部分,会倒序输出
    }
}

int main()
{
    LinkStack S;      // 创建
    Init_LkStack(&S); // 初始化

    printf("Input the length\n");
    int n, e;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &e);
        Push_LkStack(&S, e);
        printf("%d.st elem\n", S->data);
    }

    TraverseList(S);

    return 0;
}