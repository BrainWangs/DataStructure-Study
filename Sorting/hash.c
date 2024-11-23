/*哈希查找(散列表查找)*/
#include <stdio.h>
typedef struct HASHTable 
{
    int *arr;
    int length;
} HASHTable;

int InitHASH(HASHTable *H) {
    if (H == NULL) return -1;
    H->length = 10;
    for (int i = 0; i < H->length; i++) {
        H->arr[i] = (int)malloc(sizeof(int));  /////有问题
        
    }
    return ;
}

int Hash(int key) {
    return key % 10;
}

/*哈希查找*/
int SearchHASh(HASHTable *H, int key) {
    if (H == NULL) return -1;
    //第一次查找
    int H0 = Hash(key);
    if (H->arr[H0] == key) {
        return H0;
    }
    else if (H->arr[H0] == 0) {
        return -1;
    }
    //出现冲突,进入第二次查找
    else {
        int Hi;
        for (int i = 0; i < H->length; i++) {
            Hi = Hash(H0 + i);
            if (H->arr[Hi] == key) {
                return Hi;
            }
            else if (H->arr[Hi] == 0) {
                return -1; //此处为空,查找失败
            }
        }
    }
}
/*插入元素*/
int InsertHASH(HASHTable *H, int key) {
    if (H == NULL) return -1;
    
    int H0 = Hash(key);
    for (int i = 0; H->arr[H0] != 0 && i < H->length; i++) {
        H0 = Hash(key + i);
    }
    H->arr[H0] = key;

    return 0;
}

/*创建哈希表*/
int CreateHASH(HASHTable *H) {
    if (H == NULL) return -1;
    int val;
    do {
        scanf("%d", &val);
        InsertHASH(H, val);
    } while (val != 0);   
}

int main() {
    HASHTable H;
    InitHASH(&H);
    CreateHASH(&H);

    printf("search\n");
    int pos = SearchHASh(&H, 3);

    return 0;
}