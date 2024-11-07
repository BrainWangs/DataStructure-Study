/*顺序栈*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define OK 1
#define Error -1


typedef struct //创建顺序栈结构体,以int作为栈元素
{
    int *base; //栈底指针
    int *top; //栈顶指针
    int StackSize; //栈的最大容量
}SqStack;

/*初始化*/  /*创建一个空栈*/
int Init_SqStack(SqStack *S) { //必须用指针
    S -> base = (int *)malloc(sizeof(int) * MaxSize); //创建一个大小为MaxSize的int顺序表
    if(! S -> base){
        printf("Init error\n");
        return Error;
    }
    S -> top = S -> base; //当顶指针等于底指针,为空栈
    S -> StackSize = MaxSize;
    return OK;
}
/*入栈*/    /*将一个新元素放到栈顶*/
int Push_SqStack(SqStack *S, int e) {
    if(S -> top - S -> base == 0) { //检查栈是否已满
        printf("StackOverFlow\n");
        return Error;
    }
    *(S -> top)++ = e; //将e的值赋给top的地址上,然后top+1
    return OK;
} 

/*出栈*/    /*弹出(取出并删除)栈顶元素*/
int Pop_SqStack(SqStack *S, int *e) {
    if(S -> top == S -> base) {
        printf("Stack Empty Error\n");
        return Error;
    }
    *e = *(--(S -> top)); //top此时指向0, top-1才是栈顶元素,因此先减1再赋值
    return OK;
}
/*取栈顶元素*/
int GetTop_SqStack(SqStack S) {
    if(S.top == S.base) {
        printf("Stack Empty Error\n");
        return Error;
    }
    return *(S.top - 1); //返回栈顶元素但不改变其指针位置
}

int main() {


    return 0;
}