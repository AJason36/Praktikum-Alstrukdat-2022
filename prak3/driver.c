#include "liststatik.c"
#include <stdio.h>

int main(){
    ListStatik l1;
    CreateListStatik(&l1);
    readList(&l1);

    // ListStatik l2;
    // CreateListStatik(&l2);
    // readList(&l2);
    // printList(l2);

    // printf("%d", listLength(l1));

    // printf("%d", getFirstIdx(l1));
    // printf("%d", getLastIdx(l1));

    // if (isIdxValid(l1, 101)){
    //     printf("Index valid");
    // } else {
    //     printf("Index tidak valid");
    // }

    // if(isIdxEff(l1, 10)){
    //     printf("Index efektif");
    // } else {
    //     printf("Index tidak efektif");
    // }

    // if (isEmpty(l1)){
    //     printf("List kosong");
    // } else {
    //     printf("List tidak kosong");
    // }

    // if (isListEqual(l1, l2)){
    //     printf("Lmao");
    // } else {
    //     printf("What");
    // }

    // printf("%d", indexOf(l1, 3));

    // int max, min;
    // extremeValues(l1, &max, &min);
    // printf("%d %d", max, min);

    // insertFirst(&l1, 999);
    // insertLast(&l1, 999);
    // insertAt(&l1, 999, 2);

    // int val;
    // // deleteFirst(&l1, &val);
    // // deleteLast(&l1, &val);
    // deleteAt(&l1, &val, 2);
    printList(l1);
    // printf("%d", val);

    return 0;
}