#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
} Node, *List;


void print_list (List list)
{
    Node* p = list->next;
    while (p) {
        printf("%d ", p->value);
        p = p->next;
    }
}


void free_list (List list)
{

}
/*删除链表中的重复元素*/
void remove_duplicates (List list)
{
    if (! list || ! list->next) { //必须考虑链表为空的情况
        return;
    }
    List p = list->next;
    while (p->next) { 
    if (p->value == p->next->value) {
        List q = p->next;
        p->next = q->next;
        free(q);
        q = NULL;
    }
    else 
        p = p->next;
    }
 

}


// new element will be appended to tail
List create_list ()
{
    List list = (Node*)malloc(sizeof(Node));
    list->next = NULL;
    int v;
    Node* prev = list;

    // sample input: 1 2 3 #
    while (scanf("%d", &v) > 0){
        Node* node = (Node*)malloc(sizeof(Node));
        node->value = v;
        node->next = NULL;
        prev->next = node;
        prev = node;
    }

    return list;
}


int main (int argc, char** argv)
{
    List list = create_list();
    remove_duplicates(list);
    print_list(list);
    free_list(list);
    return EXIT_SUCCESS;
}

