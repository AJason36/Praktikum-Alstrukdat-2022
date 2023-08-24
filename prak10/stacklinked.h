/* File: stacklinked.h */

#ifndef STACKLINKED_H
#define STACKLINKED_H

#include "boolean.h"
#include <stdlib.h>

#define NIL NULL
/* Deklarasi infotype */
typedef int ElType;
/* Stack dengan representasi berkait dengan pointer */
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next; 
} Node; 

/* Type stack dengan ciri Top: */
typedef struct { 
    Address addrTop; /* alamat Top: elemen puncak */
} Stack;

/* Selektor */
#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define      TOP(s) (s).addrTop->info 

/* Prototype manajemen memori */
Address newNode(ElType x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s);
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int length(Stack s);
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStack(Stack *s);
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void DisplayStack(Stack s);
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

void push(Stack *s, ElType x);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, ElType *x);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

#endif