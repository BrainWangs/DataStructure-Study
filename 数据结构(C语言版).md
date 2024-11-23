## 前置知识点补充

---

### 1. malloc()内存分配

- 函数原型

```c
void *malloc(size_t size);	//返回值类型 void *
```

- ==使用方法==

1. **包含头文件**：在使用 `malloc` 之前，需要包含 `<stdlib.h>` 头文件。

   ```c
   #include <stdlib.h>
   ```

2. **分配内存**：调用 `malloc` 并传递所需内存的大小（以字节为单位）。

   ```c
   int *array = (int *)malloc(n * sizeof(int));
   ```

   这里 `n` 是你想要分配的整数数组的大小。

3. **检查返回值**：`malloc` 可能因为内存不足而失败，此时会返回 `NULL`。因此，在使用分配的内存之前，应该检查返回值。

   ```c
   if (array == NULL) {
       fprintf(stderr, "Memory allocation failed\n");
       exit(EXIT_FAILURE);
   }
   ```

4. **使用内存**：分配成功后，你可以像使用静态分配的数组一样使用这块内存。

   ```c
   for (int i = 0; i < n; i++) {
       array[i] = i;
   }
   ```

5. **释放内存**：使用完动态分配的内存后，应该使用 `free` 函数释放它，以避免内存泄漏。

   ```c
   free(array);	//free()形参为 指针类型
   ```

- ==分配内存机制详解==

```c
int *array = (int *)malloc(n * sizeof(int));
```

1. `n * sizeof(int)`：这是 `malloc` 函数的参数，它指定了要分配的内存的大小。`n` 是一个整数，表示你想要分配的整数的数量。`sizeof(int)` 是一个编译时运算符，它返回 `int` 类型在当前平台上所占的字节数。将这两个值相乘得到整个数组所需的总字节数。
2. `(int *)`：这是一个**类型转换操作**，它将 `malloc` 返回的 `void *` 类型指针转换为 `int *` 类型指针。在 C 语言中，`void *` 类型的指针可以指向任何类型的数据，但当你想要使用这块内存存储特定类型的数据时，你需要将其转换为相应的指针类型。在这里，我们想要一个指向 `int` 类型的指针，所以使用 `(int *)` 进行转换
3. `int *array`：这行代码的左侧声明了一个名为 `array` 的指针变量，它的类型是 `int *`，这意味着 `array` 可以存储指向 `int` 类型数据的地址。(用指针接收分配内存返回的指针, 二者须是同一类型)



### 2.结构体相关概念

```c
struct QNode {	//第一个QNode声明结构体变量,可以省略
    int data;
    struct QNode *next; //struct告诉程序使用结构体变量
}QNode, *QueuePtr; //第二个Qnode是Struct QNode的别名, 可以不加QNode就声明该类型变量
```

1. 第一个`QNode`定义了结构体的类型，它告诉编译器`QNode`是一个包含一个`int`类型数据成员`data`和一个指向相同结构体类型的指针成员`next`的结构体。

2. 第二个`QNode`（在`*QueuePtr`中）是`struct QNode`的别名，它允许你在声明指针时不必每次都写完整的`struct QNode`。这使得代码更加简洁易读。

至于为什么在定义指针时使用`struct`关键字，这是因为在C语言中，当你想要声明一个指向结构体的指针时，你需要告诉编译器这个指针指向的是哪个结构体类型。`struct`关键字在这里是用来指定结构体类型的。

举个例子：

```c
struct QNode {
    int data;
    struct QNode *next;
};
```

在这个例子中，`struct QNode`定义了一个结构体类型。然后，你可以使用`struct QNode`来声明指向这个结构体的指针：

```c
struct QNode *ptr;
```

这里的`ptr`是一个指向`struct QNode`类型结构体的指针。

但是，如果你已经定义了`QNode`作为`struct QNode`的别名，你就可以简化指针的声明：

```c
QNode *ptr;
```

这里的`ptr`和上面的声明是等价的，都是指向`struct QNode`类型结构体的指针。



### 3. fgets()函数输入用法

`fgets()` 是 C 语言中用于从输入流读取字符串的标准库函数。它的常见用法是读取用户的输入或从文件中读取数据。

当**读取 (n-1) 个字符**时，或者**读取到换行符**时，或者**到达文件末尾**时，它会停止，具体视情况而定

函数定义

```c
char *fgets(char *str, int n, FILE *stream);
```

参数解释

1. **`str`**: 用于存储读取数据的字符数组(字符串)
2. **`n`**: 指定最多读取的字符数，包括最后的空字符 `\0`。即最多读取 `n-1` 个字符，剩下的一个字符用于存放字符串结尾的 `\0`
3. **`stream`**: 指定输入流，通常可以是标准输入 `stdin` 或文件流

返回值

- 成功读取时返回指向 `str` 的指针
- 如果到达文件末尾（EOF）或出现错误，则返回 `NULL`

常见使用场景

1. **读取标准输入**：最常见的使用方式是从用户输入中读取一行字符串。
2. **读取文件内容**：从文件中逐行读取数据。
3. **处理随机长度的输入**

### 4. scanf()返回值探究

scanf返回与指定输入类型相匹配的个数, 当出现不匹配退出时, 返回0 (包括\n)

当接收到ctrl Z 或遇到文件结尾, 返回EOF (-1)

### 5. 使用scanf()跳过\n

```c
for (int i = 0; ; i++) {
    scanf("%d", &arr[i]); //执行部分
    n++;	
    if (getchar() == '\n') //注意跳出循环的程序应该放在最后
        break;
}
```

scanf() 接收`\n` 跳过并留在缓冲区内, 使用getcahr() 可以接收`\n`并作为退出条件

这里的`i `还可以作为数组最大下标传递给其他函数使用



## 顺序表

---

### 代码实现

```c
#include <stdio.h>
#define MAX 2
#define Error -1
#define OK 1

typedef struct { //顺序表内的数据元素类型
	char name[20];
	char isbn[30];
	float price;
} Book;		

typedef struct { //顺序表
	Book* pt;	 //指针pt作为表的头地址,用来作为数组的索引
	int length;  //length作为标记用来指示顺序表的一种状态
} SqList;

/*初始化函数*/		/*此函数负责构造顺序表*/
int initialize(SqList* ls, Book *book) { //传入要初始化的表地址和内部数据元素数组
	if(!ls) printf("ERROR pt\n"); //考虑空指针的情况,增加程序的健壮性,防止程序崩溃
	ls->pt = book;  
	ls->length = 0;
	return OK;
}
/*数据输入函数*/
int putArray(SqList* ls, int size) { //size表示数组的长度
	int i;
	for (i = 0; i < size; i++) {
		scanf("%19s", ls->pt[i].name);  
		scanf("%29s", ls->pt[i].isbn);  
		scanf("%f", &(ls->pt[i].price)); 
		++ls->length; //表长+1
		
	}
	return OK;
}
/*取值函数*/ 		/*根据位置i取出下标为i-1的数据,并赋值给e*/
int getArray(SqList ls, int i, Book *e) {
	if(i < 1 || i > ls.length) return Error;
	*e = ls.pt[i - 1]; //形参i视作位置i,数组调用要用下标i,要让e地址对应的值被修改
	return OK;
}

/*查找函数*/ 		/*根据数值e查找元素位置i*/
int LocatArray(SqList ls, float e) {
	for(int i = 0; i < ls.length; i++) {
		if(ls.pt[i].price == e) return i+1;
	}
	return 0; //遍历完仍未查找到,说明不存在e,程序结束
}

/*插值函数*/		/*插入元素bk到位置i*/
int InsertArray(SqList *ls, int i, Book bk) {
	if(i < 1 || i > ls->length+1) {	//这里的i是位置i
		printf("Illegal var i : 非法位置i");
		return Error;
	}
	if(i == ls->length) return Error;
	for(int j = ls->length-1; j >= i-1; j--) {	//注意这里的i和j都是下标 所以减1
		ls->pt[j + 1] = ls->pt[j];	//注意是[j+1] = [j],在末尾插入不会执行此循环
		ls->length++;
	}
	ls->pt[i - 1] = bk; //在位置i(下标i-1)插入数据
	++ls->length;
	return OK;
}


/*删除函数*/		/*删除第i个元素*/
int DeleteArray(SqList *ls, int i) {
	if(i < 1 || i > ls ->length) return Error;
	for(int j = i; j < ls->length-1; j++) {	//注意是从位置i+1开始(下标i)
		ls->pt[j] = ls->pt[j-1];
	}
	--ls->length;
	return OK;
}

Book book[MAX]; //定义全局数组book

void main() {
	SqList L;
	initialize(&L, &book[0]); //传入的第二个参数应该是book[0],即首元素的地址.不能是&book,会发出警告
	printf("Start\n");
	putArray(&L, MAX); //初始化输入函数
	printf("取出第i个数据");
	int i; 
	Book e; 
	scanf("%d",&i); 
	int a = getArray(L, i, &e);
	if(a == Error)
		printf("Error");
	else
		printf("%s, %s, %f\n", e.name, e.isbn, e.price);
}
```























### 思路汇总

1. **`指针p`和`位置 i ` `计数器 j`的关系总结**

在取值算法中, p = L->next , 因为取值至少是从首元结点开始取; 在插入 删除算法中, p = L , 因为这些算法需要用到前一个结点, 考虑到对第一个结点的操作, 因此从头结点开始

计数器 j 用于标记指针p当前指向的位置 , 因此它要和p保持一致 , 当p为头结点, 相当于位置0, 因此 j=0; p为首元结点, j=1

不管哪种算法, while循环都要遍历 i-1次(正常情况下) -> 在取值算法中遍历i-1次后p指向位置i, 在插入删除中指向位置i-1

因此 while判断条件 要随着p和 j进行改变, 才能满足i-1次的条件 , 即: 

- p = L ; j = 0 ;  ---> while( j < i - 1)
- p = L -> next ; j = 1;  ---> while( j < i)



2. 取值算法

```c
Status GetElem(LinkList L,int i,ElemType &e) {
p=L->next;j=1; // 初始化， p指向首元节点，计数器 j 初值赋为1
while(p&&j<i) { // 顺链域向后查找，直到 p 为空或 p 指向第i 个元素
p=p->next; //p 指向下一个节点
++j; // 计数器j相应加 1
}
if(!p||j>i)return ERROR; //i 值不合法i>n 或 i<=0
e=p->data; // 取第i个节点的数据域
return OK;
}
```

- **重点** : 循环退出条件在正常情况下(i合法)是 j = i 时退出, 此时指针p指向的位置是 i , *执行次数为 i - 1次*
- 进入循环体的变量 j 从 1 到 i - 1 , 退出循环体的变量 j 从2 到 i

4. 插入算法

<img src="https://pic.imgdb.cn/item/66e7dd9bd9c307b7e909658f.png" style="zoom: 67%;" >

```c
Status ListInsert(LinkList &L,int i,ElemType e) {
p=L;j=0;
while(p && (j<i −1))
{p=p->next;++j;} // 查找第i−1个节点， p 指向该节点
if(!p||j>i − 1) return ERROR; //i ＞ n+1 或者 i ＜ 1
s=new LNode; // 生成新节点*s
s->data=e; // 将节点 *s的数据域置为 e
s->next=p->next; // 将节点*s 的指针域指向节点ai
p->next=s; // 将节点*p 的指针域指向节点*s
return OK;
}
```

- **重点** : 当 j = i - 1时退出循环体, 此时p指向位置 i - 1 , 执行次数 0 到 i - 2 共 i - 1 次 
- **重点** : if 检测条件是 !p , 插入算法允许位置 i = length + 1 , 因此p最多等于 i , 刚好非空 ; 注意与delete的区别

5. 删除算法

<img src="https://pic.imgdb.cn/item/66e7df42d9c307b7e90c2f10.png" style="zoom:67%;" >

```c
Status ListDelete(LinkList &L,int i) {// 在带头节点的单链表 L中，删除第i个元素
p=L;j=0;
while((p->next) && (j<i-1)) // 查找第i −1个节点， p 指向该节点
{p=p->next; ++j;}
if(!(p->next)||(j>i-1)) return ERROR; // 当i>n 或 i<1时，删除位置不合理
q=p->next; // 临时保存被删节点的地址以备释放
p->next=q->next; // 改变删除节点前驱节点的指针域
delete q; // 释放删除节点的空间
return OK;
}
```

- **重点** : 删除最多允许 i = length , 指针p最多指向 i - 1的位置 , 因此if的检测条件是 !(p->next) 当 i > length时生效



### 链式表的合并输出

两个非降序链表的并集，例如将链表1->2->3 和 2->3->5 并为 1->2->3->5，只能输出结果，不能修改两个链表的数据。

【输入形式】
 第一行为第一个链表的各结点值，以空格分隔。
 第二行为第二个链表的各结点值，以空格分隔。

【输出形式】合并好的链表，以非降序排列，值与值之间以空格分隔。

【样例输入】

  4 7 10 34

 1 4 6 29 34 34 52

【样例输出】1 4 6 7 10 29 34 52

> 思路:	采用**双指针法** , 分别对两个链表的结点进行比较, 每次输出较小的结点(复制到新链表中), 并且在新链表中检查是否存在相同元素, 如果相同则跳过











## 串和广义表

---









## 树和二叉树

---

### 二叉树遍历

- 先序遍历 

根、左、右

- 中序遍历

左、根、右

- 后序遍历

左、右、根





### 二叉树的应用

#### 根据遍历序列确定二叉树

1. 由中序和后序遍历确定二叉树

由后序遍历确定根节点, 接着在先序中序遍历中划分左右子树, 在后序遍历中确定左右子树的根节点 , 不断递归这一操作, 即完成二叉树的构建

<img src="https://pic.imgdb.cn/item/673b3b42d29ded1a8cb60abd.png" style="zoom:80%;" >



2. 由先序和中序遍历确定二叉树

原理大致相同



#### 二叉树线索化

二叉线索树是在传统二叉树结构的基础上，加上判断结点左右孩子是否为空的标志–LTag,RTag

**二叉树的线索化:**	是指根据某一个遍历序列, 把二叉树结点中空闲的指针域分别填上其前驱、后继的过程

因此，线索二叉树分为`先序线索化、中序线索化、后序线索化`三种。要想线索化二叉树，需要先遍历二叉树获得对应遍历顺序的线性序列

<img src="https://pic3.zhimg.com/v2-3323632a025312529a6394f2db1287c6_1440w.jpg" style="zoom: 33%;" >

```c
typedef struct BiTNode
{	
    char data;//数据域
    int LTag = 0;//左标签
    int RTag = 0;//右标签
    struct BiTNode* lchild = nullptr;//指针必须初始化，c11标准
    struct BiTNode* rchild = nullptr;//左右孩子
}BiTNode, * BiTree;
```

例题:

<img src="https://pic4.zhimg.com/v2-890ef1e99682f6ce51523ea9463a481d_1440w.jpg" style="zoom:33%;" >

红色的虚线即是线索化指针



#### 树和森林和二叉树的相互转换







#### 哈夫曼表和哈夫曼树的构建









### 算法应用

#### 判断遍历序列是否是二叉树遍历

【问题描述】输入一个整数数组，判断该数组是不是某二元查找树的后序遍历的结果。如果是返回true，否则返回false。
【输入形式】输入任意长度的数组，数字之间空格分开
【输出形式】true 或者 false
【样例输入】输入5 7 6 9 11 10 8
【样例输出】true

```c
/*使用递归定义
划分左右子树,左子树所有元素比根节点小,右子树所有元素比根节点大
满足这一条件则是后序遍历,否则不是*/
int BiTreeJudge(int *arr, int start, int end) {
    //考虑空数组和单子树 
    if (start >= end) {
        return 1;
    } 
    //标记根节点
    int root = arr[end];
    //寻找第一个大于根节点的数
    int i;
    for (i = start; arr[i] < root; i++);
    int point = i;
    //检查右子树是否都大于根节点
    for (int i = point; i < end; i++) {
        if (arr[i] < root) 
            return 0;
    }
    //递归划分左右子树
    BiTreeJudge(arr, start, point - 1);
    BiTreeJudge(arr, point - 1, end - 1);
}
```













## 图

---

### 存储结构

- 邻接矩阵

  ```c
  typedef struct 
  {
      char vexs[MAXNUM]; //顶点表 用于存放顶点信息(字母编号)
      int matrix[MAXNUM][MAXNUM]; //邻接矩阵
      int vexnum, arcnum; //当前存储的顶点数,边数
  }AMGraph;
  ```

<img src="https://pic.imgdb.cn/item/673c89eed29ded1a8cec28b7.png" style="zoom: 80%;" >

对于无权图,使用`0,1`表示即可; 对于带权图(网), 使用`(权值, 无穷)`表示

对于无向图, 邻接矩阵有对称轴(副对角线)

- 邻接表

  ```c
  #define MVNum 100 //最大顶点数
  typedef struct ArcNode //边节点
  {
      int adjvex; //该边所指向的顶点的位置
      struct ArcNode * nextarc; //指向下一条边的指针
      OtherInfo info; //和边相关的信息
  }ArcNode;
  typedef struct VNode //顶点信息
  {
      VerTexType data;
      ArcNode *firstarc; //指向第一条依附该顶点的边的指针
  }VNode,AdjList[MVNum]; //AdjList表示邻接表类型
  typedef struct //邻接表
  {
      AdjList vertices;
      int vexnum,arcnum; //图的当前顶点数和边数
  }ALGraph;
  ```

  <img src="https://pic.imgdb.cn/item/673c896ed29ded1a8cebc117.png" style="zoom:67%;" >

构造邻接表只看顶点的入度









### 图的遍历

- 深度优先遍历 (树的先序遍历)

```c
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
```

深度优先生成树

将图的顶点按照深度优先遍历的顺序进行标记 ,初始放左子树, 每次回溯放右子树.  得到的一个树的存储结构(不一定是二叉树), 此树按照先序遍历可以得到和DFS一样的遍历结果

<img src="https://pic.imgdb.cn/item/673c8b49d29ded1a8ced6e02.png" style="zoom: 67%;" >  <img src="https://pic.imgdb.cn/item/673c8b49d29ded1a8ced6dd3.png" style="zoom: 80%;" >    





- 广度优先遍历 (树的层次遍历)

```c
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
}
```

广度优先生成树

和深度优先同理. 

<img src="https://pic.imgdb.cn/item/673c8c59d29ded1a8ceeafd7.png" style="zoom:67%;" >	<img src="https://pic.imgdb.cn/item/673c8c5ad29ded1a8ceeb062.png" style="zoom:67%;" >





### 图的应用

---

#### 图的相关量计算

- 连通分量

#### 最小生成树

- 普里姆算法(prime)

从某一顶点出发，**寻找该顶点连通的顶点中权值最小的边且不构成连通图**，标记为最短路径，并将对应顶点加入最短路径网；重复这一过程，直到所有顶点都加入最短路径网

<img src="https://pic.imgdb.cn/item/673c874cd29ded1a8cea0228.png" style="zoom: 80%;" >

- 克鲁斯卡尔算法(kruskal)

对图中所有的边筛选求出权值最小的边，对起始顶点和后序连接顶点无要求，但是要构成的最短路径网在任意时刻不能是连通图

<img src="https://pic.imgdb.cn/item/673c874cd29ded1a8cea0228.png" style="zoom: 80%;" >

#### 最短路径问题

#### 拓扑排序

#### 关键路径





## 查找

---

### 二分查找(折半查找)

折半查找要求线性表必须采用顺序存储结构, 而且表中元素按关键字有序排列

**参考视频** : [二分查找为什么总是写错？](https://www.bilibili.com/video/BV1d54y1q7k7/)

把一个升序排列的数组分为*两个区域* (根据题目的条件) , 目的是找到区域边界处; 通过判断`mid`所属的区域 , 不断逼近和缩小判定区域范围, 一直到 `(low + 1) == high` , 即到达边界, 其中`low`是边界左值, `high` 是边界右值

```c
low = -1 , high = N		//在数组两边设置起始指针low和high
while (low + 1) != N {
    mid = (low + high) / 2
	if codition(mid)	//condition()是一个判断mid所属区域的函数/语句
        low = mid		//如果m属于左区域
	else high = mid		//如果m属于右区域
}
return low or high		//根据题意需要返回边界的左值或右值
```

<img src="https://pic.imgdb.cn/item/6734958ad29ded1a8c93d4d3.png" style="zoom: 40%;" >

[细节]

1. 初始的两个指针, 分别是 -1 和 N (数组长度)
2. 中间值mid 的取值范围是 `[0 , N)`
3. 更新指针的操作是 `low = mid` 和 `high = mid` , 在其他二分算法中多写作 low = mid + 1和 high = mid - 1



> 实际应用 : 求具有n个元素的数组arr中, 不大于target的**最大下标i**, 即 arr[i] < target

思路 : 

- 据题意可知 , 把target作为要求的**目标边界**, 分为两个区域(A, B), 注意 *target不一定是数组中的元素*; 

- 计算当前判定区域(low 和 high围起来的区域)的中间值mid; 

- 判断mid所属的区域 (即算法思想中的`condition()` ), 若mid属于A区, 则边界在mid的右边; 同理, 若mid属于B区, 则边界在mid的左边, 
- 循环结束, 我们要求的是边界左边第一个值, 因此返回 low

```c
int Select_Binary(int *arr, int target, int n) {
    int low = -1;
    int high = n;
    while (low + 1 != high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}
```



### 二叉排序树

#### 定义

二叉排序树或者是一棵空树，或者是具有下列性质的二叉树:

- 若它的左子树不空，则左子树上所有节点的值均小于它的根节点的值；

- 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；

- 它的左、右子树也分别为二叉排序树（递归定义）

简言之, 一个二叉排序树的结点符合 左、根、右 从小到大排列顺序；因此，对一颗二叉排序树进行中序遍历，可以按照从小到大顺序输出

<img src="https://pic.imgdb.cn/item/67349865d29ded1a8c967d2e.png" style="zoom: 75%;" >

存储类型

```c
typedef struct BSNode {
    int elem;
    struct BSNode *lchild, *rchild;
} BSNode, *BSTree;
```

#### 插入

```c
/*二叉排序树插入*/
void BST_insert(BSTree T, int elem) {
    //当前根节点为空时(空树或叶子结点)
    if (!T) {
        T = (BSNode *)malloc(sizeof(BSNode));
        T->elem = elem;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else {
        //比较插入元素和当前根节点下的元素大小,决定插入左子树还是右子树
        if (elem < T->elem)  
            BST_insert(T->lchild, elem);
        else if (elem > T->elem)
            BST_insert(T->rchild, elem);
    }
}
```



#### 创建

```c
/*二叉排序树创建--反复调用插入函数*/
#define FLAG -1
void BST_create(BSTree T) {
    T = NULL;
    int elem;
    scanf("%d", &elem);
    while (elem != FLAG) { //使用FLAG作为结束标志
        BST_insert(T, elem);
        scanf("%d", &elem);
    } 
}
```



#### 查找

```c
/*二叉排序树查找*/
BSNode* BST_select(BSTree T, int key) {
    //当树为空时,或查找到指定元素
    if (!T || T->elem == key) {
        return T;
    }
    //否则, 根据关键字和根节点的大小关系决定递归子树
    else if (key < T->elem) return BST_select(T->lchild, key);
    else if (key > T->elem) return BST_select(T->rchild, key);
}
```



#### 删除 (最重要)

1. 被删除节点的左子树存在

用它的直接左子树代替被删除节点

2.  被删除节点的右子树存在

用它的直接右子树代替被删除节点

3. 被删除节点的左子树和右子树都存在

找它的直接前驱(**左子树中最大的叶子结点**)或直接后继(**右子树中最小的叶子结点**)

<img src="https://pic.imgdb.cn/item/6734a9ddd29ded1a8ca53163.png" style="zoom: 80%;" >





### 哈希查找(散列表查找)

#### 哈希函数构造

哈希函数(散列函数) : 在记录的存储位置 p 和其关键字 key 之间建立一个确定的对应关系H，使 ` p = H(key)`，称这个对应关系H为散列函数， p为散列地址。  最常用的哈希函数构造是 **除留余数法** : 假设散列表表长为m，选择一个不大于m的数p，用p去除关键字，除后所得余数为散列地址，即：`H(key) = key % p`

哈希表(散列表)：一个有限连续的地址空间，用以存储按散列函数计算得到相应散列地址的数据记录。  

冲突 / 同义词：对不同的关键字可能得到同一散列地址，即 **key1≠ key2，而 H(key1) =H(key2)**，这种现象称为冲突 

查找成功 和 查找失败的定义: 查找成功即在哈希表中找到对应的关键字; 查找失败是 H(key) 的地址值为空或根据冲突运算得到的``H(key) + di` 的地址值为空, 此时才能确认查找失败

#### 解决冲突的方法

1. **开放地址法**

把记录都存储在散列表数组中，当某一记录关键字key的初始散列地址H0 = H(key)发生冲突时，以H0为基础，采取合适方法计算得到另一个地址H1，如果H1仍然发生冲突，以H1为基础再求下一个地址H2，若H2仍然冲突，再求得H3。依次类推。寻找下一个位置的过程叫做探测。
$$
Hi = (\ H(\ key\ ) +\ d_i\ ) \ \% \ m \\
i = 1, 2, …, k (k≤m − 1)
$$

注意是对 $H(key) + d_i$ 再进行哈希运算


- 线性探测法

$$
d_i = 1, 2, 3, …, m − 1
$$

- 二次探测法

$$
d_i = 1^2, −1^2, 2^2, − 2^2, 3^2,…, k^2, −k^2 \ (k≤m/2)
$$

使用二次探测，查找失败时也要按照$d_i$的增量进行计算, 其查找失败的条件是 `查找完所有数组空间/查找为空` 



例题:	关键字 (19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79)，设散列函数为`H(key)= key %13`，用线性探测法处理冲突。设表长为16，试构造这组关键字的散列表，并计算查找成功和查找失败时的平均查找长度。  

![image-20241117180624740](C:\Users\12275\AppData\Roaming\Typora\typora-user-images\image-20241117180624740.png)

==平均查找长度ASL==
$$
查找成功: \ ASL_{succ} = \frac{1}{12} \times (1\times6 + 2 + 3\times3 + 4 + 9) = \frac{30}{12} = 2.5
$$
每个元素查找成功的概率等于 $\frac{1}{元素个数}$ 括号内数字与表格中比较次数相匹配
$$
查找失败: \ ASL_{unsucc} = \frac{1}{13} \times (1+13+12+11+9+8+7+6+5+4+3+2) = \frac{91}{13} = 7 
$$
查找失败的入口有13个(**与散列函数的除数相等**) 。若计算散列函数H(key) = 0， HT[0].key为空，比较1次即确定查找失败。若H(key) = 1， HT[1].key非空，则依次向后比较，直到HT[13].key为空，总共比较13次才能确定查找失败。类似地，对H(key) = 2, 3,…, 12进行分析。





2. **链地址法**

把具有相同散列地址的记录放在同一个单链表中，称之为同义词链表。有m个散列地址就有m个单链表，同时用数组 HT[0…m-1] 存放各个链表的头指针，***凡是散列地址为 i 的记录都以节点方式插入以HT[i]为头节点的单链表***

例题： 已知一组关键字为(19, 14, 23, 1, 68, 20, 84, 27, 55, 11, 10, 79)，设散列函数`H(key) = key %13`，用链地址法处理冲突，试构造这组关键字的散列表。

<img src="C:\Users\12275\AppData\Roaming\Typora\typora-user-images\image-20241117180606200.png" alt="image-20241117180606200"  />

==平均查找长度ASL==\
$$
查找成功: \ ASL_{succ} = \frac{1}{12} \times (1\times6 + 2\times4 + 3 + 4) = \frac{21}{12} = 1.75
$$
从数组头出发, 查找链表第一个元素需要比较1次, 第二个元素比较2次, 可以竖着数单链表的格子数
$$
查找失败: \ ASL_{unsucc} = \frac{1}{13} \times (1\times7 + 5 + 3 + 3 + 2 + 3 + 2) = \frac{25}{13} = 1.92
$$
所有为空的数组元素比较1次即确认查找失败, 所有数组不为空的元素(如1号位),  从链表第一个结点出发, 到最后一个结点, 再比较一次确认下一个位置为空为止, 共需要查找 4 + 1次 , 下面的元素以此类推











## 排序

---

### 插入排序

**易错点**

1. 数组边界问题 : `arr[j + 1] = arr[j];`对有序数组进行从后向前的移动, 由于j的取值从i-1到0, 需要注意不要写成`arr[j] = arr[j - 1]`否则会导致数组越界
2. 移动完有序数组后, 此时的变量 j 指向空位置的上一个位置(最后一次j--), 因此需要使用`arr[j + 1] = temp;`而不是 j 进行赋值
2. 注意判断条件`temp < arr[j] && j >= 0;`

```c
/*插入排序*/
void insertSort(int *arr, int n) {
    int j;
    int temp;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; temp < arr[j] && j >= 0; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
```

### 折半插入排序

折半插入排序即在查找已排序的有序数组时使用折半查找, 找到要插入的下标, 然后遍历依次移动下标位之后的元素,然后插入目标元素



### 希尔排序

希尔排序是选定一个`增量dist`, 从第一个元素开始, 每隔dist选中一个元素(长度不够则不选)组成一组, 对这一组元素进行*直接插入排序*, 然后从第一个选中的元素下标+1, 再每隔dist选择元素组成一组, 重复操作直到所有元素都被排序一遍, **此为第一趟排序**

接着, 再选择一个dist(小于第一次), 重复上述步骤

> 希尔排序不要求掌握代码实现

<img src="https://pic.imgdb.cn/item/6739d88bd29ded1a8ca712bb.png" style="zoom:50%;" >

### 冒泡排序

- 代码

```c
void bubbleSort(int *arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) { //把>改成<即可实现由大到小排序
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

第一个for循环的条件是`arr.length - 1` , 因为每次循环确定一个元素的排序位置, 对于n个元素, 只需确定n-1个元素的位置, 则最后一个元素的位置也可以确定了;

第二个for循环条件是`arr.length - 1 - i`, 其中`arr.length - 1`是因为循环中用到了`arr[j + 1]` , 是为了防止 `j = arr.length` 导致数组越界, 而 减i 是因为每次外层遍历可以使一个最大值浮动到数组末尾, 由于其排序位置已确定, 依次在下一次遍历时不需要再比较。

- 优化算法： 使用标志位提前结束已排好序的数组

```c
//定义一个标志位，用于判定元素之间是否进行了交换
boolean flag = false;
for (int i = 0; i < arr.length - 1; i++) {
    for (int j = 0; j < arr.length - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
            //进入这个if分支里边，则说明有元素进行了交换
            //所以将flag=true
            flag = true;
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
    //在进行完一轮的排序之后，判断本轮是否发生了元素之间的交换
    //如果没有发生交换，说明数组已经是有序的了，则直接结束排序
    if (!flag) {
        break;
    } else {
        //如果发生了交换，那么在下一轮排序之前将flag再次置为false
        //以便记录下一轮排序的时候是否会发生交换
        flag = false;
    }
}
```





### 选择排序

1. 从原始数组中选择一个最小值
2. 把最小值和原始数组的第一个元素交换, 第一个元素被划为已排序数组
3. 重复这一过程 (双层for循环)

[细节] : 注意最小值变量min在每次循环开始初始化为原始数组的第一个元素

```c
int chooseSort(int *arr, int n) {
    int min;
    int temp;
    for (int i = 0; i < n; i++) {
        min = i; //i是未排序数组的第一个
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return 0;
}
```



### 快速排序

1. 设置两个下标指针low和high, 分别指向边界的首尾; 选择一个元素作为枢纽(pivotValue), 通常选择第一个即low
2. 从右边界向左边界遍历数组元素, 当`arr[high] < pivot`时, 与此时的arr[low]交换位置(当pivot为low时可以直接覆盖), 否则high--
3. 从左边界向右边界遍历, 当 `arr[low] > pivot`时, 与此时的arr[high]交换位置, 否则low++
4. 当`low == high`说明遍历结束, 将pivot的值放到该位置上
5. 递归以上程序, 边界条件为`low, pivot-1`和`pivot+1, high`



[细节] : 注意这里的循环条件`while (low < high && arr[high] >= pivotValue) high--;` 

```c
int quickSort(int *arr, int low, int high) {
//low和high分别是数组的左右边界
    if (low < high) { //递归边界检查
        int pivot = sort(arr, low, high); 
        //从左往右划分边界依次递归
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    return 0;
}

int sort(int *arr, int low, int high) {
    int pivotValue = arr[low]; 
    while (low < high) {
       while (low < high && arr[high] >= pivotValue) high--;
       arr[low] = arr[high];
       while (low < high && arr[low] <= pivotValue) low++;
       arr[high] = arr[low];
    }
    arr[low] = pivotValue; //low和high相等位置作为pivot的新位置
    return low; //返回pivot的位置下标
}
```



### 归并排序

第一趟: 把n个元素分为n个数组, 每个数组大小为1。从第一个数组开始，两两合并（每次选取两个数组的最小值放入临时数组，当所有元素选取完后，用临时数组覆盖掉原数组）。如果出现奇数个数组，则最后一个数组不用合并。第一趟结束

第二趟，由第一趟得到每个元素分为长度为2的新数组，重复两两合并，得到长度为4的新数组

重复上述过程，直到新数组长度等于原数组长度（新数组只剩下1个）

<img src="https://pic.imgdb.cn/item/6739dcdfd29ded1a8cab2073.png" style="zoom:67%;" >















# 错误汇总

---

## 顺序表错误

1.

```c
/*顺序表初始化*/ 
void initialize(SqList* ls) { //传入指针
	Book book[MAX];	//====================发生错误===================================
	ls->pt = book;	//数组首地址赋给顺序表指针
	ls->length = 0;
}
/*传入顺序表地址和表的大小*/
void putArray(SqList* ls, int size) {
	for (int i = 0; i < size; i++) {
		scanf("%s", ls->pt[i].name); //================空指针错误================
		scanf("%s", ls->pt[i].isbn);
		scanf("%f", &(ls->pt[i].price)); //注意这个传递的写法
	}
}
void main() {
	SqList L;
	initialize(&L); //===============================================
	printf("开始");
	putArray(&L, MAX);
	Book b = getArray(&L, 1);
	printf("%s , %s , %f\n", b.name, b.isbn, b.price);
}
```

> 19行 初始化函数内创建顺序表内存空间`Book book[MAX];`, 当这个函数结束, 内存空间会被销毁
>
> 导致27行 scanf函数输入 **出现空指针调用** ,错误返回值**3221225477**
>
> **更正 **: 实际错误原因是, 传入的参数&L是它的地址拷贝, 在initialize函数中, `ls->pt = book; 和 ls->length = 0;`两个操作只是对拷贝地址的指针ls进行了更改, 这不会影响原来的L, 函数结束后L仍然是刚创建时`SqList L;`状态, 因此后面`putArray(&L, MAX);`中的`scanf("%s", ls->pt[i].name);`操作, 实际上不存在ls -> pt[i], pt未初始化, 因此出现空指针错误

2.

```c
/*插值函数*/		/*插入元素bk到位置i*/
int InsertArray(SqList *ls, int i, Book bk) {
	if(i < 1 || i > ls->length+1) {	//这里的i是位置i
		printf("Illegal var i : 非法位置i");
		return Error;
	}
	if(i == ls->length) return Error;
	for(int j = ls->length-1; j >= i-1; j--) {	//注意这里的i和j都是下标 所以减1
		ls->pt[j] = ls->pt[j - 1];
		ls->length++;
	}
	ls->pt[i - 1] = bk; //在位置i(下标i-1)插入数据
}
```

> for循环中`	ls->pt[j] = ls->pt[j - 1];`错误
>
> 第一次遍历时, j指向表末尾第一个非空数据,若是`	ls->pt[j] = ls->pt[j - 1];`则**导致当前位置数据被前一个覆盖**,而不是把数据覆盖到空位置上

3.

```c
/*取值函数*/ 		/*根据位置i取出下标为i-1的数据,并赋值给e*/
int getArray(SqList ls, int i, Book *e) {
	if(i < 1 || i > ls.length) return Error;
	e = &(ls.pt[i - 1]); //错误
	return OK;
}
```

> `e = &(ls.pt[i - 1]); //错误`错误原因 :
>
> 函数形参`*e`传入的实际上是`Book e`地址的**拷贝**, 此句的作用是让实参指针e指向数组值的地址, 这相当于把e的地址的拷贝指向了该地址
>
> 这相当于, 创建了两个指针指向e, 函数内部那个指针重新指向数组值的地址, 当函数结束, 拷贝指针被销毁, 而原指针指向的地址还是初始化的e

" **在 C 语言中，当你传递一个指针到函数中，你实际上是传递了这个指针的副本。这意味着函数内部得到的是指针值的一个拷贝，而不是指针本身。如果你在函数内部修改这个指针的副本，那么这个修改只影响副本，不会影响原始指针** "

正确改法 :

```c
int getArray(SqList ls, int i, Book *e) {
	if(i < 1 || i > ls.length) return Error;
	*e = ls.pt[i - 1]; //形参i视作位置i,数组调用要用下标i,要让e地址对应的值被修改
	return OK;
}
```





## 链式表错误

1.

```c
int initialize(LinkList L) { //创建空链表初始化
    LNode node;
    L = &node;
    L -> data = 0;
    L -> next = NULL;
}
```

> **错误1** 创建的结点 node 会在函数结束后被销毁, L -> next 为空
>
> **错误2** 传入形参是L的赋值体, `L=&node`操作实际上是对复制体的指针地址进行了更改, 而main函数的L不受影响, 会出现空指针错误

**更正 : ** 使用malloc()申请内存 , 改为对指针的指针的传递

```c
int initialize(LinkList *L) {
    L  = (LNode *)malloc(sizeof(LNode)); //使用malloc申请内存,malloc返回指针,赋给头指针L
    (*L) -> data = 0;
    (*L) -> next = NULL;
    return OK;
}
```

传递指针复制体和传递指针的指针的区别 

<img src="https://pic.imgdb.cn/item/66e1a426d9c307b7e9490846.png" style="zoom: 50%; float: left;" > 







<img src="https://pic.imgdb.cn/item/66e1a432d9c307b7e9491809.png" style="zoom: 50%; float: left;" >

传递指针的指针, 其操作是在原指针的基础上进行更改, 避免了出现将地址传递给复制体的情况

2. 

```c
/*求表长*/
int ListLength(LinkList L) {
    LinkList p = L;
    int length = 0;
    while(p != NULL) {
        p = p -> next;
        length++; 
    }
    return length;
}
```

> **错误 :** 循环内最后一步` length++; `执行完会多加一次, 返回的时候要减1
>
> 即`return --length;`

另一种改法 :

```c
int ListLength(LinkList L) {
    LinkList p = L;
    int length = 0;
    while(p -> next != NULL) { //====这里进行了修改======
        p = p -> next;
        length++; 
    }
    return length;
}
```







# 课后练习&习题

**将两个递增的有序链表合并为一个递增的有序链表。 要求结果链表仍使用原来两个
链表的存储空间 , 不另外占用其它的存储空间。表中不允许有重复的数据。**

[ 题目分析 ]
合并后的新表使用头指针 Lc 指向， pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为
相应链表的第一个结点，从第一个结点开始进行比较，当两个链表 La 和 Lb 均为到达表尾结
点时，依次摘取其中较小者重新链接在 Lc 表的最后。如果两个表中的元素相等，只摘取 La
表中的元素，删除 Lb 表中的元素，这样确保合并后表中无重复的元素。当一个表 到达表尾结
点，为空时，将非空表的剩余元素直接链接在 Lc 表的最后。

> 1. 创建一个头结点c作为合并后链表的头结点
> 2. 创建La和Lb的工作指针pa和pb
> 3. 比较pa和pb对应结点的大小, 小的连接到pc, 大的留下继续下一次比较
> 4. 链接到pc后, pc要向后移, pa或pb也要向后移一位
> 5. 考虑元素相等时, 删除pb结点, 链接pa (不允许重复数据)
> 6. 考虑当La或Lb不等长时, 把多出来的一部分直接链接到pc
> 7. 最后删除多余的头结点

[ 算法描述 ]

```c
void MergeList(LinkList &La,LinkList &Lb,LinkList &Lc) 
{// 合并链表 La 和 Lb，合并后的新表使用头指针 Lc 指向
    pa=La->next; 
    pb=Lb->next; 
	//pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为相应链表的第一个结点
	Lc=pc=La; // 用 La 的头结点作为 Lc 的头结点
	while(pa && pb) {
        if(pa->data<pb->data) {
            pc->next=pa;
            pc=pa; //pc指针后移
            pa=pa->next; //pa指针后移
        } 
	// 取较小者 La 中的元素，将 pa 链接在 pc 的后面， pa 指针后移
	 	else if(pa->data>pb->data) {
             pc->next=pb; 
             pc=pb; 
             pb=pb->next;
        } 
	 // 取较小者 Lb 中的元素，将 pb 链接在 pc 的后面， pb 指针后移
	 	else // 相等时取 La 中的元素，删除 Lb 中的元素
        {
            pc->next=pa;
            pc=pa;pa=pa->next; 
            q=pb->next;
            delete pb ;
            pb =q; 
        } 
	} 
    /*当La或Lb其中一个为空时退出*/
	pc->next=pa?pa:pb; // 插入剩余段pa或pb
	delete Lb; // 释放 Lb 的头结点
} 
```



**将两个非递减的有序链表合并为一个非递增的有序链表。 要求结果链表仍使用原来
两个链表的存储空间 , 不另外占用其它的存储空间。表中允许有重复的数据**

[ 题目分析 ]
合并后的新表使用头指针 Lc 指向， pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为
相应链表的第一个结点，从第一个结点开始进行比较，当两个链表 La 和 Lb 均为到达表尾结
点时，依次摘取其中较小者重新链接在 Lc 表的表头结点之后，如果两个表中的元素相等，只
摘取 La 表中的元素，保留 Lb 表中的元素。当一个表到达表尾结点，为空时，将非空表的剩
余元素依次摘取，链接在 Lc 表的表头结点之后。
[ 算法描述 ]

```c
void MergeList(LinkList& La, LinkList& Lb, LinkList& Lc, ) 
{// 合并链表 La 和 Lb，合并后的新表使用头指针 Lc 指向
	 pa=La->next; pb=Lb->next; 
	//pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为相应链表的第一个结点
	 Lc=pc=La; // 用 La 的头结点作为 Lc 的头结点
	 Lc->next=NULL; 
	 while(pa||pb ) 
	{// 只要存在一个非空表，用 q 指向待摘取的元素
	 	if(!pa) 
	 		{q=pb; pb=pb->next;} 
	//La 表为空，用 q 指向 pb ， pb 指针后移
	 	else if(!pb) 
	 		{q=pa; pa=pa->next;} 
	//Lb 表为空，用 q 指向 pa ， pa 指针后移
	 	else if(pa->data<=pb->data) 
	 		{q=pa; pa=pa->next;} 
	// 取较小者（包括相等） La 中的元素，用 q 指向 pa， pa 指针后移
		else 
			{q=pb; pb=pb->next;} 
	// 取较小者 Lb 中的元素，用 q 指向 pb， pb 指针后移
	 q->next = Lc->next; Lc->next = q; 
	// 将 q 指向的结点插在 Lc 表的表头结点之后
	} 
	delete Lb; // 释放 Lb 的头结点
} 
```





**已知两个链表 A 和 B 分别表示两个集合，其元素递增排列。请设计算法求出 A 与 B
的交集，并存放于 A 链表中**
[ 题目分析 ]
只有同时出现在两集合中的元素才出现在结果表中 , 合并后的新表使用头指针 Lc 指向。
pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为相应链表的第一个结点， 从第一个结点开
始进行比较，当两个链表 La 和 Lb 均为到达表尾结点时，如果两个表中相等的元素时，摘取
La 表中的元素，删除 Lb 表中的元素；如果其中一个表中的元素较小时，删除此表中较小的
元素，此表的工作指针后移。当链表 La 和 Lb 有一个到达表尾结点，为空时，依次删除另一
个非空表中的所有元素。

> 1. 当pa和pb指针结点相等时, 链接pa结点到pc, 删除pb结点, pc pa pb均后移
> 2. 当不相等时, 较小的那个结点删除且指针后移
> 3. 当链表不等长时, 多余部分全部删除(循环删除)
> 4. 释放头结点

[ 算法描述 ]

```c
void Mix(LinkList& La, LinkList& Lb, LinkList& Lc) 
{pa=La->next;pb=Lb->next; 
	pa 和 pb 分别是链表 La 和 Lb 的工作指针 , 初始化为相应链表的第一个结点
	Lc=pc=La; // 用 La 的头结点作为 Lc 的头结点
	while(pa&&pb) 
	{ 
		if(pa->data==pb- >data) //交集并入结果表中
	 		{ pc->next=pa;pc=pa;pa=pa->next; 
	u=pb;pb=pb->next; delete u;} 
		else if(pa->data<pb->data) //不相等时,小的删除并后移
			{u=pa;pa=pa->next; delete u;} 
		else 
			{u=pb; pb=pb->next; delete u;} 
	} 
 	/*多余结点循环删除*/
	while(pa){u=pa; pa=pa->next; delete u;} ∥ 释放结点空间
	while(pb) {u=pb; pb=pb->next; delete u ;} ∥释放结点空间
	pc- >next=null; ∥置链表尾标记。
	delete Lb; // 释放 Lb 的头结点
 }
```

