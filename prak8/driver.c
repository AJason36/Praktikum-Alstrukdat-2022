#include <stdio.h>
#include "listlinier.c"
#include "list_linked.c"

int main(){
    List l,l1;
    CreateList(&l);
    CreateList(&l1);
    insertFirst(&l, 1);

    insertFirst(&l, 2);
    insertFirst(&l, 3);
    inverseList(&l);
    displayList(l);
    insertFirst(&l1,4);
    insertFirst(&l1, 5);
    insertLast(&l1, 6);
    
    insertAt(&l1, 10, 2);
    displayList(l1);
    inverseList(&l);
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