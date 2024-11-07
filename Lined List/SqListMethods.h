#ifndef SqListMethods
#define SqListMethods

typedef struct { //顺序表内的数据元素类型
	char name[20];
	char isbn[30];
	float price;
} Book;		

typedef struct { //顺序表
	Book* pt;	 //指针pt作为表的头地址,用来作为数组的索引
	int length;  //length作为标记用来指示顺序表的一种状态
} SqList;


/*函数原型声明*/

int initialize(SqList* ls, Book *book);
int putArray(SqList* ls, int size);
int getArray(SqList ls, int i, Book *e);
int LocatArray(SqList ls, float e);
int InsertArray(SqList *ls, int i, Book bk);
int DeleteArray(SqList *ls, int i);




#endif