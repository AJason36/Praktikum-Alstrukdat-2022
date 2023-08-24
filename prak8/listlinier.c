// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 25 Oktober 2022
// Topik Praktikum: List berkait
// Deskripsi: realisasi list berkait

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType val){
    Address new = (Address) malloc (sizeof(Node));

    INFO(new) = val;
    NEXT(new) = NULL;
    return new;
};

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
};
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
};
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int count = 0;
    Address p=l;
    while (count<idx){
        count++;
        p = NEXT(p);
    }
    return (INFO(p));
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int count = 0;
    Address p=*l;
    while (count<idx){
        count++;
        p = NEXT(p);
    }
    INFO(p) = val;
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p = l;
    int count = 0;
    while (p!=NULL){
        if(INFO(p)==val){
            return count;
        }
        count++;
        p = NEXT(p);
    }
    return IDX_UNDEF;
};
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p!= NULL){
        NEXT(p) = *l;
        *l = p;
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    if (isEmpty(*l)){
        insertFirst(l, val);
    }else{
        Address p = newNode(val);
        Address last = *l;
        while (NEXT(last)!=NULL){
            last = NEXT(last);
        }
        NEXT(last) = p;
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    if (idx ==0){
        insertFirst(l, val);
    }else{
        Address p = newNode(val);
        int count = 0;
        Address loc = *l;
        while (count<idx-1){
            count++;
            loc = NEXT(loc);
        }
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }
};
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
};
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p = *l;
    Address loc = NULL;
    while (NEXT(p)!=NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc==NULL){
        *l = NULL;
    }else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    if (idx ==0){
        deleteFirst(l, val);
    }else{
        int count = 0;
        Address loc = *l;
        while (count<idx-1){
            count++;
            loc = NEXT(loc);
        }
        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
};
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    if (isEmpty(l)){
        printf("[]");
    }else{
        Address p = l;
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
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int count=0;
    if (isEmpty(l)){
        return 0;
    }
    Address p = l;
    while (p!=NULL){
        count++;
        p = NEXT(p);
    }
    return count;
};
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l;
    CreateList(&l);
    Address(p) = l1;
    while (p!=NULL){
        insertLast(&l, INFO(p));
        p = NEXT(p);
    }
    Address p2 = l2;
    while(p2!=NULL){
        insertLast(&l, INFO(p2));
        p2 = NEXT(p2);
    }
    return l;
};
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
    Address temp = L;
    boolean found = false;
    while (temp!=NULL && !found){
        if (P == temp){
            found =true;
        }else{
            temp = NEXT(temp);
        }
    }
    return found;
};
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
Address searchPrec(List L, ElType X){
     Address p = L, loc=NULL;
    //  boolean found =false;
     while (p!=NULL){
        if (INFO(p)==X){
            return loc;
        }else{
            loc = p;
            p = NEXT(p);
        }
     }
     return NULL;
};
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min : List tidak kosong ***/

/* Mengirimkan nilai info(P) yang maksimum */
Address adrMax(List l){
    Address p, maxAdr;

    maxAdr = l;
    p = NEXT(l);
    while (p!=NULL){
        if (INFO(p)>INFO(maxAdr) ){
            maxAdr = p;
        }
        p=NEXT(p);
    }
    return maxAdr;
};
ElType max(List l){
    return INFO(adrMax(l));
};
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */

/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l){
    Address p, minAdr;
    
    minAdr = l;
    p = NEXT(l);
    while (p!=NULL){
        if (INFO(p)<INFO(minAdr) ){
            minAdr = p;
        }
        p=NEXT(p);
    }
    return minAdr;
};
ElType min(List l){
    return INFO(adrMin(l));
};
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */

/****************** PROSES TERHADAP LIST ******************/

/***************** FUNGSI dan PROSEDUR TAMBAHAN **************/
void deleteAll(List *l){
    ElType val;

    while (!isEmpty(*l)){
        deleteFirst(l, &val);
    }
};
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void copyList(List *l1, List *l2){
    CreateList(l2);
    *l2=*l1;
};
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

void inverseList(List *l){
    Address p;
    ElType temp;
    int i, n = length(*l);
    for(i=0; i<n/2;i++){
        temp = getElmt(*l,i);
        setElmt(l,i, getElmt(*l, n-i-1));
        setElmt(l,n-i-1, temp);
    }
};
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void splitList(List *l1, List *l2, List l){
    CreateList(l1);
    CreateList(l2);

    Address p, loc, pNew;
    int i=0;
    p=l;
    while (p!=NULL){
        pNew = newNode(INFO(p));
        if (i<length(l)/2){
            insertLast(l1, INFO(pNew));
        }else{
            insertLast(l2, INFO(pNew));
        }
        free(pNew);
        p=NEXT(p);
        i++;
    } 
};
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */