// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 17 September 2022
// Topik Praktikum: ADT List
// Deskripsi: tampilan program olist

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "liststatik.h"

int indexOf1(ListStatik l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
   if (!isEmpty(l)){
      int i = listLength(l);
      for (i; i >= IDX_MIN;i--){
         if (ELMT(l,i)==val){
            return i;
         }
      }
      return IDX_UNDEF;
   }
   return IDX_UNDEF;
}

int main () {
    ListStatik l;
    int n, i, count = 0, index, maxVal, minVal, medVal;
    CreateListStatik(&l);
    readList(&l);

    scanf("%d", &n);
    maxVal = ELMT (l, IDX_MIN);
    minVal = ELMT (l, IDX_MIN);
    printList(l);
    printf("\n");

    for (int i = 0; i < listLength(l); i++) {
        if (ELMT(l, i) == n) {
            count++;
        }
    }

    index= indexOf1(l, n);
    extremeValues(l, &maxVal, &minVal);
    sortList(&l, true);
    if (listLength(l) % 2 != 0) {
        medVal = ELMT (l, listLength(l)/2);
    } else {
        medVal = ELMT (l, (listLength(l)/2)-1);
    }

    if (count == 0) {
        printf("%d\n", count);
        printf("%d tidak ada\n", n);
    } else {
        printf("%d\n", count);
        printf("%d\n", index);
        if (n == maxVal) {
            printf("maksimum\n");
        }
        if (n == minVal) {
            printf("minimum\n");
        }
        if (n == medVal) {
            printf("median\n");
        }
    }

}