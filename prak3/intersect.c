// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 17 September 2022
// Topik Praktikum: ADT List
// Deskripsi: tampilan program intersect

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "liststatik.h"

int main () {
    ListStatik l1, l2, l;
    int i, j;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    readList(&l1);
    readList(&l2);
    sortList(&l1, true);
    sortList(&l2, true);
    CreateListStatik(&l);

    for (i = 0; i < listLength(l1);i++){
        for (j = 0; j < listLength(l2);j++){
            if (ELMT(l1, i) == ELMT(l2, j)) {
                insertLast(&l, ELMT(l1, i));
            }
        }
    }
    sortList(&l, true);
    printf("%d\n", listLength(l));
    printList(l);
    printf("\n");

    return 0;
}