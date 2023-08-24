// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 3 November 2022
// Topik Praktikum: List berkait sirkular
// Deskripsi: realisasi list berkait sirkular

#include "list_circular.c"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
int length(List l){
    int count=0;
    if (isEmpty(l)){
        return 0;
    }
    Address p = FIRST(l);
    while (NEXT(p)!=FIRST(l)){
        count++;
        p = NEXT(p);
    }
    return count+1;
};
int indexOf(List l, ElType val){
    Address p = FIRST(l);
    int count = 0;
    while (NEXT(p)!=FIRST(l)){
        if(INFO(p)==val){
            return count;
        }
        count++;
        p = NEXT(p);
    }
    return count;
};
void deleteAt(List *l, int idx, ElType *val){
    if (idx == 0){
        deleteFirst(l, val);
    }else{
        int count = 0;
        Address loc = FIRST(*l);
        while (count<idx-1){
            count++;
            loc = NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        // free(p);
    }
};
int main(){
    List l;
	int i, n,k;
	CreateList(&l);
	scanf("%d", &n);
	scanf("%d", &k);
	i=1;
	while (i<n+1){
		insertLast(&l, i);
		i++;
	}
	deleteAt(&l, indexOf(l,5), &i);
    deleteAt(&l, indexOf(l,4), &i);
	displayList(l);
	// printf("%d\n", i);
	int count=0;

	Address p = FIRST(l);
	ElType val;

}