/*数据结构结课作业设计*/
/*
设计并实现一个学生管理系统，即定义一个包含学生信息（学号，姓名，成绩）的的顺序表，
可以不考虑重名的情况，系统至少包含以下功能：
(1) 根据指定学生个数，逐个输入学生信息；
(2) 逐个显示学生表中所有学生的相关信息；
(3) 给定一个学生信息，插入到表中指定的位置；
(4) 删除指定位置的学生记录；
(5) 统计表中学生个数；
(6) 利用直接插入排序或者折半插入排序按照姓名进行排序；
(7) 利用快速排序按照学号进行排序；
(8) 根据姓名进行折半查找，要求使用递归算法实现，成功返回此学生的学号和成绩；
(9) 根据学号进行折半查找，要求使用非递归算法实现，成功返回此学生的姓名和成绩。
基本要求
(1) 程序要添加适当的注释，程序的书写要采用缩进格式。
(2) 程序要具在一定的健壮性，即当输入数据非法时，程序也能适当地做出反应，如插入删除时指定的位置不对等等。
(3) 程序要做到界面友好，在程序运行时用户可以根据相应的提示信息进行操作。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
typedef struct student
{
    long long xh;
    char name[100];
    int grade;
} stu;

typedef struct SeqList
{
    stu *ptr;
    int length;
    int capacity;
} List;

/*异常打印函数*/
void exception(char str[]) {
    printf("Exception: %s\n", str);
}

/*顺序表初始化*/
int initList(List *L, int initCap) {
    if (!L) {
        exception("initError");
        return -1;
    }
    //分配初始内存
    L->ptr = (stu *)malloc(sizeof(stu) *initCap);
    if (!L) {
        exception("Memory Malloc Error");
        return -1;
    }
    L->length = 0;
    L->capacity = initCap;
    return 0;
}

/*如果length超过当前容量 重新分配内存*/
int reMalloc(List *L) {
    if (!L) {
        exception("reMalloc Error");
        return -1;
    }
    int newCap = L->capacity * 2;
    stu *newPtr = (stu *)realloc(L->ptr, sizeof(stu) * newCap);
    if (!newPtr) {
        exception("realloc Error");
        return -1;
    }
    //length不变,更新顺序表
    L->ptr = newPtr;
    L->capacity = newCap;
    return 0;
}

/*在位置i插入新元素*/
int insertList(List *L, int i, stu value) {
//============条件检查====================
    if (!L) {
        exception("insertList Error");
        return -1;
    }
    if (L->length >= L->capacity) { //必须是大于等于
        if (reMalloc(L) == -1) return -1;
    }
    if (i < 1 || i > L->capacity) {
        exception("Illegal insert");
        return -1;
    }
//============插入程序=====================
//注意,数组第n个下标是可以访问的,但是内容是未定义的
    for (int j = L->length - 1; j > i - 1; j--) {
        L->ptr[j + 1] = L->ptr[j];
    }
    L->ptr[i - 1] = value;
    L->length++;

    return 0;
}

/*根据个数n创建顺序表*/
int createList(List *L, int n) {
    if (!L) {
        exception("create Error");
        return -1;
    }
    if (n < 1) {
        exception("Illegal Number");
        return -1;
    }
    stu node;
    for (int i = 0; i < 100; i++) {
        node.name[i] = '\0';
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld %s %d", &node.xh, node.name, &node.grade);
        insertList(L, i + 1, node);
    }
    return 0;
}

/*在位置i删除元素*/
int removeList(List *L, int i) {
    if (!L) {
        exception("remove Error");
        return -1;
    }
    if (i < 1 || i > L->length) {
        exception("Illegal remove");
        return -1;
    }
    for (int j = i - 1; j < L->length; j++) {
        L->ptr[j] = L->ptr[j + 1];
    }
    L->length--;

    return 0;
}

/*按名字首字母排序*/
int sortByName(List *L) {
    if (!L) {
        exception("sort Error");
        return -1;
    }
    int j;  stu temp;
    for (int i = 1; i < L->length; i++) {
        temp = L->ptr[i];
        for (j = i - 1; tolower(temp.name[0]) < tolower(L->ptr[j].name[0]) && j >= 0; j--) {
            L->ptr[j + 1] = L->ptr[j];
        }
        L->ptr[j + 1] = temp;
    }
    return 0;
}

/*按照学号排序*/
int sort(List *L, int low, int high) {
    stu pivotValue = L->ptr[low];
    while (low < high) {
       while (low < high && L->ptr[high].xh >= pivotValue.xh) high--;
       L->ptr[low] = L->ptr[high];
       while (low < high && L->ptr[low].xh <= pivotValue.xh) low++;
       L->ptr[high] = L->ptr[low];
    }
    L->ptr[low] = pivotValue; //low和high相等位置作为pivot的新位置
    return low; //返回pivot的位置下标
}
void quickSort(List *L, int low, int high) {
//low和high分别是数组的左右边界
    if (low < high) { //递归边界检查
        int pivot = sort(L, low, high);
        //从左往右划分边界依次递归
        quickSort(L, low, pivot - 1);
        quickSort(L, pivot + 1, high);
    }
}
int sortByxh(List *L) {
    if (!L) {
        exception("sort Error");
        return -1;
    }
    quickSort(L, 0, L->length - 1);
    return 0;
}

/*按姓名查找并返回下标*/ //target为查询字符串
int SearchByName_Recursive(List *L, int low, int high, char *target) {
    if (!L) {
        exception("search Error");
        return -1;
    }
    if (low > high) {
        printf("No such student\n");
        return -1; //未找到
    }
    int mid = (low + high) / 2;
    int cmp = strcmp(L->ptr[mid].name, target);
    if (cmp == 0) {
        printf("search successfully\n");
        printf("%-15lld%-15s%-15d\n", L->ptr[mid].xh, L->ptr[mid].name, L->ptr[mid].grade);
        return mid;
    } 
    else if (cmp > 0) {
        return SearchByName_Recursive(L, low, mid - 1, target);
    } 
    else {
        return SearchByName_Recursive(L, mid + 1, high, target);
    }
}

//非递归折半查找学号
long long SearchByXH(List *L, long long target) {
    int low = 0, high = L->length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (L->ptr[mid].xh == target) {
            printf("search successfully\n");
            printf("%-15lld%-15s%-15d\n", L->ptr[mid].xh, L->ptr[mid].name, L->ptr[mid].grade);
            return target; // 找到
        } else if (L->ptr[mid].xh > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("None\n");
    return 0; // 未找到
}

/*遍历打印顺序表*/
void printList(List L) {
    printf("=========================output=================================\n");
    for (int i = 0; i < L.length; i++) {
        printf("%-15lld%-15s%-15d\n", L.ptr[i].xh, L.ptr[i].name, L.ptr[i].grade);
    }
    printf("\n\n\n");
}


void printManual() {
    printf("1. 在位置i插入新元素 - 在顺序表的指定位置插入新元素\n");
    printf("2. 根据个数n创建顺序表 - 根据输入的个数n创建顺序表\n");
    printf("3. 在位置i删除元素 - 删除顺序表指定位置的元素\n");
    printf("4. 按名字首字母排序 - 按照学生名字的首字母顺序对顺序表进行排序\n");
    printf("5. 按照学号排序 - 按照学生学号对顺序表进行排序\n");
    printf("6. 按姓名查找并返回下标 - 根据学生名字查找并返回下标\n");
    printf("7. 非递归折半查找学号 - 根据学生学号进行非递归折半查找\n");
    printf("8. 遍历打印顺序表 - 遍历顺序表并打印每个元素\n");
    printf("===========================================================\n");
    printf("请输入序号执行对应操作(0 to quit): ");
}

int main() {
    List L;
    initList(&L, 10); // 初始化顺序表

    char choice;
    do {
        printManual();
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                // 在位置i插入新元素
                printf("Inserting new student at position: ");
                int i;
                scanf("%d", &i);
                stu node;
                scanf("%lld %s %d", &node.xh, node.name, &node.grade);
                insertList(&L, i, node);
                break;
            case '2':
                // 根据个数n创建顺序表
                printf("Enter number of students to create: ");
                int n;
                scanf("%d", &n);
                createList(&L, n);
                break;
            case '3':
                // 在位置i删除元素
                printf("Removing student at position (1-indexed): ");
                int remove_i;
                scanf("%d", &remove_i);
                removeList(&L, remove_i);
                break;
            case '4':
                // 按名字首字母排序
                sortByName(&L);
                printList(L);
                break;
            case '5':
                // 按照学号排序
                sortByxh(&L);
                printList(L);
                break;
            case '6':
                // 按姓名查找并返回下标
                printf("Enter student name to search: ");
                char target[100];
                scanf("%s", target);
                SearchByName_Recursive(&L, 0, L.length - 1, target);
                break;
            case '7':
                // 非递归折半查找学号
                printf("Enter student ID to search: ");
                long long xh;
                scanf("%lld", &xh);
                SearchByXH(&L, xh);
                break;
            case '8':
                printList(L);
                break; 
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        Sleep(1000);
    } while (choice != '0');

    // 释放顺序表内存
    free(L.ptr);
    return 0;
}