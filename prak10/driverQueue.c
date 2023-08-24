// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 10 November 2022
// Topik Praktikum: List berkait stack queue 
// Deskripsi: realisasi list berkait queue

#include "queuelinked.c"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Queue q;
    CreateQueue(&q);
    int n, i, time, temp;
    scanf("%d", &n);
    for (i = 0; i < n;i++){
        scanf("%d", &time);
        enqueue(&q, time);
        while (INFO(ADDR_TAIL(q))-HEAD(q)>300 && length(q)>1){
            dequeue(&q, &temp);
        }
        printf("%d\n", length(q));
    }
    return 0;
}