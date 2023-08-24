/* NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 8 November 2022
// Topik Praktikum: List berkait rekursif 
// Deskripsi: realisasi list berkait rekursif*/
#include "listrec.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


/* Manajemen Memori */
Address newNode(ElType x){
    Address p = (Address)malloc (sizeof(Node));
    if (p!= NULL){
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
};
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l){
    return l == NULL;
};
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isOneElmt(List l){
    return (!isEmpty(l) && NEXT(l)==NULL);
};
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */

/* Primitif-Primitif Pemrosesan List */
ElType head(List l){
    return INFO(l);
};
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
List tail(List l){
    return NEXT(l);
};
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
List konso(List l, ElType e){
    Address p;
    p = newNode(e);
    if (p!=NULL){
        NEXT(p) = l;
        return p;
    }else{
        return l;
    }
};
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
List konsb(List l, ElType e){
    
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
};
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */ 
List copy(List l){
    if(isEmpty(l)){
        return NULL;
    }
    else{
        return konso(copy(tail(l)), head(l));
    }
};
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
List concat(List l1, List l2){
    if ((isEmpty(l1)))
    {
        return copy(l2);
    }else{
        return konso(concat(tail(l1), l2), head(l1));
    }
    
};
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NULL */

/* Fungsi dan Prosedur Lain */
int length(List l){
    if (isEmpty(l)){
        return 0;
    }else{
        return 1 + (length(tail(l)));
    }
};
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
boolean isMember(List l, ElType x){
    if(isEmpty(l)){
        return false;
    }else if(head(l)==x){
        return true;
    }else{
        return isMember(tail(l), x);
    }
};
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
void displayList(List l){
    if (!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, NULLai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen berNULLai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */

/*** Pencarian NULLai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l){
    if (isOneElmt(l)){
        return head(l);
    }else{
        if(head(l)>maxList(tail(l))){
            return head(l);
        }else{
            return maxList(tail(l));
        }
    }
};
/* Mengirimkan NULLai INFO(p) yang maksimum */

ElType minList (List l){
    if (isOneElmt(l)){
        return head(l);
    }else{
        if(head(l)<maxList(tail(l))){
            return head(l);
        }else{
            return minList(tail(l));
        }
    }
};
/* Mengirimkan NULLai INFO(p) yang minimum */

ElType sumList (List l){
    if (isEmpty(l)){
        return 0;
    }else{
        return head(l) + sumList(tail(l));
    }
};
/* Mengirimkan total jumlah elemen List l */

float averageList (List l){
    return (float) ((float)sumList(l) / (float)(length(l)));
};
/* Mengirimkan NULLai rata-rata elemen list l */

/*** Operasi-Operasi Lain ***/
List inverseList (List l){
    if(isEmpty(l)){
        return NULL;
    }else{
        return konsb(inverseList(tail(l)), head(l));
    }
};
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */

void splitPosNeg (List l, List *l1, List *l2){
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) >= 0) {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
};
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */

void splitOnX (List l, ElType x, List *l1, List *l2){
    if (isEmpty(l)) {
        *l1 = NULL;
        *l2 = NULL;
    } else {
        if (head(l) >= x) {
            splitOnX(tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        } else {
            splitOnX(tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
};
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */

int compareList (List l1, List l2){
    if (isEmpty(l1) && isEmpty(l2)) {
        return 0;
    } else if (!isEmpty(l1) && isEmpty(l2)) {
        return 1;
    } else if (isEmpty(l1) && !isEmpty(l2)) {
        return -1;
    } else if (head(l1) > head(l2)) {
        return 1;
    } else if (head(l1) < head(l2)) {
        return -1;
    } else {
        return compareList(tail(l1), tail(l2));
    }
};
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */

boolean isElement(ElType x, List l){
    if(isEmpty(l)){
        return false;
    }else if(head(l)==x){
        return true;
    }else{
        return isElement(x, tail(l));
    }
};
/*return true kalo ada element x dalam list l, dan sebaliknya jika tidak ada*/
boolean isAllExist (List l1, List l2){
    if (isEmpty(l1)){
        return false;
    }else if(isElement(head(l1),l2)){
        return true;
    }else{
        return isAllExist(tail(l1), l2);
    }
};
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */