/*
【问题描述】编写一个程序用单链表存储多项式，并实现两个一元多项式A与B相加的函数。
A，B刚开始是无序的，A与B之和按降序排列。例如：
多项式A:  1.2X^0  2.5X^1  3.2X^3  -2.5X^5
多项式B:  -1.2X^0  2.5X^1  3.2X^3   2.5X^5   5.4X^10
多项式A与B之和：5.4X^10  6.4X^3  5X^1
【输入形式】任意两个多项式A和B
【输出形式】多项式中某一项的系数与指数，系数保留一位小数
【输入样例】
1.2 0 2.5 1 3.2 3 －2.5 5
－1.2 0 2.5 1 3.2 3 2.5 5 5.4 10
2
*/
#include<stdio.h>
#include<stdlib.h>
#define max 1000

typedef struct NODE* Node;
struct NODE {
	int x1;    //指数
	float x2;   //系数
	Node next;
};

Node init(int x1, float x2)
{
	Node n = (Node)malloc(sizeof(struct NODE));
	n->x1 = x1;
	n->x2 = x2;
	n->next = NULL;
	return n;
}

Node insert(Node H, Node r)
{
	Node p = H;
	int flag = 0;
	if (!H->next) {   //链表空状态
		H->next = r;
		return H;
	}
	while (p->next) {
		Node q = p->next;
		if (q->x1 > r->x1) {   //若新数据的指数较小，则往后放
			p = p->next;
			continue;
		}
		else if (q->x1 == r->x1) q->x2 = q->x2 + r->x2;   //两数据的指数相同时，其系数相加
		else if (q->x1 < r->x1) {   //新数据的指数大，则插入该节点前面
			r->next = p->next;
			p->next = r;
		}
		flag++;
		break;
	}
	if (!flag) p->next = r;   //遍历完链表，则将新数据插入到最后一个节点
	return H;
}

Node creat(Node H)
{
	int i;
	for (i = 0; i < max; i++) {
		float t1;
		int t2;
		scanf("%f %d", &t1, &t2);
		Node p = init(t2, t1);
		H = insert(H, p);
		char c = getchar();    //字符为空格时才会继续读取数据
		if (c != ' ') break;
	}
	return H;
}

void output(Node H, int index)
{
	int i = 0;
	Node p = H;
	while(1){
		i++;
		p = p->next;
		if (p->x2 == 0) i--;    //系数为0的项不计数
		if (i == index) {
			printf("%.1f %d", p->x2, p->x1);
			break;
		}
	}
}

int main()
{
	Node H = init(0, 0);
	H = creat(H);
	H = creat(H);
	int index;
	scanf("%d", &index);
	output(H, index);
	return 0;
}


/*思路
两个链表,头结点存储长度,选择较长的作为主链表
遍历主链表,遍历副链表, 找到能匹配的数值相加
遍历输出主链表*/
// #include <stdio.h>
// typedef struct LNode 
// {
//     double factor; //系数
//     int x;  //阶数
//     struct LNode *next;
// } LNode;
// typedef struct
// {
//     LNode *ls; //头指针
//     int length; //结点个数
// } LinkList;

// void initLS(LinkList *LS) {
//     LS->ls = (LNode *)malloc(sizeof(LNode)); //头结点
//     LS->length = 0;
// }

// void insertLS(LinkList *LS, int i, double factor, int x) {
//     LNode *p = LS->ls;
//     int j = 0;
//     if (!p) {
//         printf("malloc error");
//         return;
//     }
//     while (p && j < i - 1) {
//         p = p->next;
//         j++;
//     }
//     LNode *s = (LNode *)malloc(sizeof(LNode));
//     s->factor = factor;
//     s->x = x;
//     s->next = p->next;
//     p->next = s;
//     LS->length++;
// }

// /*根据位置i查找*/
// LNode* locateLS_pos(LinkList LS, int i) {
//     //边界检查
//     if (i < 1 || i > LS.length) {
//         printf("position Error\n");
//         return -1;
//     }
//     LNode *p = LS.ls->next; //首元结点
//     for (int j = 1; j < i; j++) {
//         p = p->next;
//     }
//     return p;
// }

// /*根据关键字查找*/
// LNode* locateLS_val(LinkList LS, int x) {
//     LNode *p = LS.ls->next;
//     while (p->x != x && p) {
//         p = p->next;
//     }
//     if (!p) {
//         printf("locate Error\n");
//         return NULL;
//     }
//     return p;
// }

// void sortLS(LinkList *LS) {
//     LNode *max = LS->ls->next;
//     LNode *p, *q;
//     //选择排序
//     for (int i = 1; i <= LS->length; i++) {
//         for (int j = i; j <= LS->length; j++) {
//             p = locateLS_pos(*LS, j);
//             if (max->x < p->x) {
//                 max = p;
//             }
//         }
        
//     }
// }


// int main() {
//     LinkList A, B;
//     initLS(&A);
//     initLS(&B);
//     double factor;
//     int x;
//     int i = 1;
//     while (1) {
//         scanf("%lf %d", &factor, &x);
//         insertLS(&A, i, factor, x);
//         i++;
//         if (getchar() == '\n') break;
//     }
//     i = 1;
//     while (1) {
//         scanf("%lf %d", &factor, &x);
//         insertLS(&B, i, factor, x);
//         i++;
//         if (getchar() == '\n') break;
//     }
//     sortLS(&A);
//     printf("%.1lf %d", A.ls->next->factor, A.ls->next->x);

//     return 0;
// }