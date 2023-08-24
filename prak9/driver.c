#include <stdio.h>
#include "list_circular.c"
int main(){
    List l,l1;
    CreateList(&l);
    CreateList(&l1);
    insertFirst(&l, 1);
    insertFirst(&l, 2);
    insertFirst(&l, 3);
    displayList(l);
    insertFirst(&l1,4);
    insertFirst(&l1, 5);
    insertLast(&l1, 6);
    
    displayList(l1);
    displayList(l);
    // List l3 = concat(l, l1);
    // displayList(l3);
    // printf("\n");
    // ElType val;
    // deleteAt(&l, 1, &val);
    // displayList(l);
    // printf("\n");
    // deleteLast(&l, &val);
    // displayList(l);
    // printf("\n");
    // printf("%d\n", length(l));
    // deleteFirst(&l, &val);
    // displayList(l);
    // printf("\n");
    // printf("%d\n", length(l));
    // deleteFirst(&l, &val);
    // displayList(l);
    // printf("\n");
}