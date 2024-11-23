#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
} Node, *List;

// new element will be appended to tail
List create_list ()
{
    List list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    int v;
    Node* prev = list;

    // sample input: 1 2 3 
    while (scanf("%d", &v)> 0){
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = v;
        node->next = NULL;
        prev->next = node;
        prev = node;
    }

    return list;
}

/*求链表倒数第k个结点的值*/
void print_rev_kth (List list, int k)
{
    List p = list; //从头结点开始
    int n = 0;
    while (p->next) { //这里使用了p->next,实际统计了n-1个,如果有5个,则统计了4个(但是p指向第5个)
        p = p->next; //考虑到list含有头结点,实际统计的数是正确的
        n++;
    }
    p = list;
    int i = 0;
    while(p->next) {
        p = p->next;
        i++;
        if(i == n - k + 1) { 
            printf("%d", p->value);
        }
    }
    if(k > n)
        printf("-1");
    return;

}


int main (int argc, char** argv)
{
    int k;
    scanf("%d", &k);
    List list = create_list();
    print_rev_kth(list, k);
    return EXIT_SUCCESS;
}
