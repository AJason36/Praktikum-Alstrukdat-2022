// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 17 September 2022
// Topik Praktikum: ADT List
// Deskripsi: tampilan program intersect

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listdin.h"

int main () {
    ListDin l1, l2, l3, dupes;
    int i,j;
    boolean dupe;

    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);

    readList(&l1);
    readList(&l2);

    CreateListDin(&l3, 400);
    CreateListDin(&dupes, 400);

    for (i = 0; i < listLength(l1);i++){
        for (j = 0; j < listLength(l2);j++){
            if (ELMT(l1, i) == ELMT(l2, j)) {
                insertLast(&dupes, ELMT(l1, i));
            }
        }
    }

    for ( i = 0; i < listLength(l1); i++) {
        dupe = false;
        for (j = 0; j < listLength(dupes); j++) {
            if (ELMT(l1, i) == ELMT(dupes, j)) {
                dupe = true;
            }
        }
        if (!dupe) {
            insertLast(&l3, ELMT(l1, i));
        }
    }

    for ( i = 0; i < listLength(l2); i++) {
        dupe = false;
        for (j = 0; j < listLength(dupes); j++) {
            if (ELMT(l2, i) == ELMT(dupes, j)) {
                dupe = true;
            }
        }
        if (!dupe) {
            insertLast(&l3, ELMT(l2, i));
        }
    }

    for (i = 0; i < listLength(dupes);i++){
        insertLast(&l3, ELMT(dupes,i));
    }
    printf ("%d\n", listLength(l3));
    sort(&l3, true);
    printList (l3);
    printf("\n");

    return 0;
}