#ifndef LinkListMethods
#define LinkLIstMethods

/*定义结点*/
typedef struct LNode
{
    int data;             //数据域
    struct LNode *next;   //指针域
}LNode, *LinkList;  //LinkList为定义的Lnode指针类型

/*初始化*/
int initialize(LinkList *L);
/*取值*/        /*取出位置i的结点数据并赋值给e*/  
int GetElem(LinkList L, int i, int *e);
/*查找*/        /*根据给定值e比较并返回指针*/
LNode *LocateElem(LinkList L, int e);
/*根据位置i查找并返回指针*/
LNode *LocateList(LinkList L, int i);
/*插入*/        /*在位置i插入数据e*/
int ListInsert(LinkList *L, int i, int e);
/*删除*/        /*删除位置i的结点*/
int ListDelete(LinkList *L, int i);
/*前插法*/
int CreatList_H(LinkList *L, int length);
/*后插法*/
int CreatList_R(LinkList *L, int length);
/*求表长*/
int ListLength(LinkList L);
/*两表合并*/
int MergeList(LinkList *L1, LinkList *L2);



#endif