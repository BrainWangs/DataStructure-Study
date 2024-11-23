#include <iostream>
#include <cstdio>
#include <cstdlib> // 替代 <malloc.h>，以符合现代 C++ 标准
using namespace std;

// 定义单链表数据类型
typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkList;

// 单链表的初始化
void InitList(LinkList *&L) {
    L = (LinkList *)malloc(sizeof(LinkList));
    if (L == NULL) {
        cerr << "Memory allocation failed" << endl;
        exit(EXIT_FAILURE);
    }
    L->next = NULL;
}

// 向单链表中插入数据元素
bool ListInsert(LinkList *&L, int x, ElemType e) {
    int j = 0;
    LinkList *p = L, *s;
    while (p != NULL && j < x - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false; // 插入位置无效
    }
    s = (LinkList *)malloc(sizeof(LinkList));
    if (s == NULL) {
        cerr << "Memory allocation failed" << endl;
        exit(EXIT_FAILURE);
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 输出单链表
void DispList(LinkList *L) {
    LinkList *p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 求单链表的长度
int ListLength(LinkList *L) {
    LinkList *p = L->next;
    int i = 0;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// 查看单链表是否为空
bool ListEmpty(LinkList *L) {
    return L->next == NULL;
}

// 求单链表中某个数据元素值
bool GetElem(LinkList *L, int i, ElemType &e) {
    LinkList *p = L->next;
    int j = 1; // 节点索引从 1 开始
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    e = p->data;
    return true;
}

// 在单链表中查找元素
int LocateElem(LinkList *L, ElemType e) {
    LinkList *p = L->next;
    int i = 1;
    while (p != NULL) {
        if (p->data == e) {
            return i;
        }
        p = p->next;
        i++;
    }
    return 0; // 未找到
}

// 删除单链表中第 i 个元素
bool ListDelete(LinkList *&L, int i, ElemType &e) {
    int j = 0;
    LinkList *p = L, *q;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL) {
        return false; // 删除位置无效
    }
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 删除单链表
void DestroyList(LinkList *&L) {
    LinkList *p;
    while (L != NULL) {
        p = L;
        L = L->next;
        free(p);
    }
}

// 尾插法创建单链表
void CreateListR(LinkList *&L, ElemType e[], int n) {
    InitList(L);
    LinkList *tail = L;
    for (int i = 0; i < n; ++i) {
        if (!LocateElem(L, e[i])) { // 去重
            LinkList *s = (LinkList *)malloc(sizeof(LinkList));
            if (s == NULL) {
                cerr << "Memory allocation failed" << endl;
                exit(EXIT_FAILURE);
            }
            s->data = e[i];
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
    }
}

// 求交集
void InsterSect(LinkList *a, LinkList *b, LinkList *&c) {
    DestroyList(c);
    InitList(c);
    LinkList *p = a->next;
    LinkList *tail = c;
    while (p != NULL) {
        if (LocateElem(b, p->data)) {
            LinkList *s = (LinkList *)malloc(sizeof(LinkList));
            if (s == NULL) {
                cerr << "Memory allocation failed" << endl;
                exit(EXIT_FAILURE);
            }
            s->data = p->data;
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
        p = p->next;
    }
}

// 求差集
void Subs(LinkList *a, LinkList *b, LinkList *&c) {
    DestroyList(c);
    InitList(c);
    LinkList *p = a->next;
    LinkList *tail = c;
    while (p != NULL) {
        if (!LocateElem(b, p->data)) {
            LinkList *s = (LinkList *)malloc(sizeof(LinkList));
            if (s == NULL) {
                cerr << "Memory allocation failed" << endl;
                exit(EXIT_FAILURE);
            }
            s->data = p->data;
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
        p = p->next;
    }
}

// 求并集
void Union(LinkList *a, LinkList *b, LinkList *&c) {
    DestroyList(c);
    InitList(c);
    LinkList *p = a->next, *q = b->next;
    LinkList *tail = c;
    while (p != NULL) {
        LinkList *s = (LinkList *)malloc(sizeof(LinkList));
        s->data = p->data;
        s->next = NULL;
        tail->next = s;
        tail = s;
        p = p->next;
    }
    while (q != NULL) {
        if (!LocateElem(c, q->data)) {
            LinkList *s = (LinkList *)malloc(sizeof(LinkList));
            s->data = q->data;
            s->next = NULL;
            tail->next = s;
            tail = s;
        }
        q = q->next;
    }
}

// 排序
void sort(LinkList *&L) {
    LinkList *sorted = NULL;
    InitList(sorted);
    LinkList *p = L->next;
    while (p != NULL) {
        LinkList *current = p;
        p = p->next;

        LinkList *prev = sorted, *s = sorted->next;
        while (s != NULL && s->data < current->data) {
            prev = s;
            s = s->next;
        }
        current->next = s;
        prev->next = current;
    }
    L = sorted;
}

int main() {
    LinkList *ha, *hb, *hc;
    ElemType a[] = {'c', 'a', 'e', 'h'};
    ElemType b[] = {'f', 'h', 'b', 'g', 'd', 'a'};
    cout << "集合的运算如下" << endl;
    CreateListR(ha, a, 4);
    CreateListR(hb, b, 6);
    cout << "原 集 合 A: ";
    DispList(ha);
    cout << "原 集 合 B: ";
    DispList(hb);
    sort(ha);
    sort(hb);
    cout << "有序集合A：";
    DispList(ha);
    cout << "有序集合B：";
    DispList(hb);
    Union(ha, hb, hc);
    cout << "集合的并C：";
    DispList(hc);
    InsterSect(ha, hb, hc);
    cout << "集合的交C：";
    DispList(hc);
    Subs(ha, hb, hc);
    cout << "集合的差C：";
    DispList(hc);
    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    return 0;
}
