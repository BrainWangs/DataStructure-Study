#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*考研题 太难了😭😭*/
typedef struct tnode {
    int data;
    struct tnode *lchild;
    struct tnode *rchild;
} tnode, *ptree;

typedef struct {
    ptree data[200];
    int front, rear;
    int flag[100]; // 输出时用来记录层数与当前要求输出的层数是否相同
} qnode, *que;

typedef struct {
    ptree stack[100];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, ptree node) {
    s->stack[++s->top] = node;
}

void pop(Stack *s) {
    if (!is_empty(s)) {
        s->top--;
    }
}

ptree top(Stack *s) {
    if (!is_empty(s)) {
        return s->stack[s->top];
    }
    return NULL;
}

void createtree(Stack *s, ptree r, char str[], int *i) {
    while (str[*i] != '\0') {
        if (str[*i] >= '0' && str[*i] <= '9') {
            int num = 0;
            while (str[*i] >= '0' && str[*i] <= '9') {
                num = num * 10 + (str[*i] - '0');
                (*i)++;
            }
            r->data = num;
            push(s, r);
        }
        if (str[*i] == '(') {
            (*i)++;
            r->lchild = (ptree)malloc(sizeof(tnode));
            r->lchild->lchild = NULL;
            r->lchild->rchild = NULL;
            r = r->lchild;
        }
        if (str[*i] == ')') {
            (*i)++;
            pop(s);
            r = top(s);
        }
        if (str[*i] == ',') {
            (*i)++;
            pop(s);
            r = top(s);
            r->rchild = (ptree)malloc(sizeof(tnode));
            r->rchild->lchild = NULL;
            r->rchild->rchild = NULL;
            r = r->rchild;
        }
    }
}

void show(ptree r, que q) {
    tnode *t = NULL;
    int now; // 当前层数
    q->flag[q->rear] = 0;
    q->data[q->rear++] = r;
    while (q->front != q->rear) {
        now = q->flag[q->front];
        t = q->data[q->front++];
        if (t->rchild) {
            q->flag[q->rear] = now + 1;
            q->data[q->rear++] = t->rchild;
        }
        if (t->lchild) {
            q->flag[q->rear] = now + 1;
            q->data[q->rear++] = t->lchild;
        }
    }
    now = q->flag[q->rear - 1];
    for (int i = q->rear - 1; i >= 0;) {
        if (q->flag[i] == now) {
            printf("%d ", q->data[i]->data);
            i--;
        } else {
            printf("\n");
            now--;
        }
    }
}

int main() {
    Stack s;
    init_stack(&s);
    char str[100];
    scanf("%s", str);
    que q = (que)malloc(sizeof(qnode));
    q->rear = 0;
    q->front = 0;
    ptree root = (ptree)malloc(sizeof(tnode));
    root->lchild = NULL;
    root->rchild = NULL;
    int i = 0;
    createtree(&s, root, str, &i);
    show(root, q);
    
    // 释放动态分配的内存
    free(root);
    free(q);
    
    return 0;
}
