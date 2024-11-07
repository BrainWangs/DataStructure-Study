#include <stdio.h>
#include "SqListMethods.h"
#define MAX 2
#define Error -1
#define OK 1

// typedef struct { //顺序表内的数据元素类型
// 	char name[20];
// 	char isbn[30];
// 	float price;
// } Book;		

// typedef struct { //顺序表
// 	Book* pt;	 //指针pt作为表的头地址,用来作为数组的索引
// 	int length;  //length作为标记用来指示顺序表的一种状态
// } SqList;

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
	return Error; //遍历完仍未查找到,说明不存在e,程序结束
}

/*插值函数*/		/*插入元素bk到位置i*/
int InsertArray(SqList *ls, int i, Book bk) {
	if(i < 1 || i > ls->length+1) {	//这里的i是位置i
		printf("Illegal var i : 非法位置i");
		return Error;
	}
	// if(i == ls->length) {
	// 	printf("error\n");
	// 	return Error;
	// }
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

// int main() {
// 	SqList L;
// 	initialize(&L, &book[0]); //传入的第二个参数应该是book[0],即首元素的地址.不能是&book,会发出警告
// 	printf("Start\n");
// 	putArray(&L, MAX); //初始化输入函数
// 	printf("取出第i个数据");
// 	int i; 
// 	Book e; 
// 	scanf("%d",&i); 
// 	int a = getArray(L, i, &e);
// 	if(a == Error)
// 		printf("Error");
// 	else
// 		printf("%s, %s, %f\n", e.name, e.isbn, e.price);
// 	return 0;
// }
