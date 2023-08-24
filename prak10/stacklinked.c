// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 8 November 2022
// Topik Praktikum: List berkait stack queue 
// Deskripsi: realisasi list berkait queue

#include "stacklinked.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
/* Prototype manajemen memori */
Address newNode(ElType x){
    Address p = (Address)malloc (sizeof(Node));
    if (p!= NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
};
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s){
    return ADDR_TOP(s) == NIL;
};
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int length(Stack s){
    if (isEmpty(s)){
        return 0;
    }else{
        int count = 0;
        Address p = ADDR_TOP(s);
        while(p!=NULL){
            count++;
            p = NEXT(p);
        }
        return count;
    }
};
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStack(Stack *s){
    ADDR_TOP(*s) = NIL;
};
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void DisplayStack(Stack s){
    if(isEmpty(s)){
        printf("[]");
    }else{
        Address p = ADDR_TOP(s);
        printf("[");
        while (p!=NULL){
            printf("%d", INFO(p));
            p = NEXT(p);
            if (p!=NULL){
                printf(",");
            }
        }
        printf("]");
    }
};
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

void push(Stack *s, ElType x){
    Address p;
    p = newNode(x);
    if (p!= NULL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
};
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, ElType *x){
    Address p;
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NULL;
    free(p);
};
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */