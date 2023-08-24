#include <stdio.h>
#include <stdlib.h>
#include "list_circular.c"

void deleteRR (List *l, ElType tQ){
    if (isEmpty(*l)){
        printf("List kosong\n");
    }else{
        Address last = FIRST(*l);
        ElType x;
        while (FIRST(*l)!= NEXT(last)){
            last = NEXT(last);
        }
        if (INFO(last)>tQ){
            INFO(last) -= tQ;
            FIRST(*l) = last;
            printf("%d\n", tQ);
        }else{
            deleteLast(l, &x);
            printf("%d\n", x);
        }
    }
}
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika INFO(last) > tQ, maka last "diantrikan" kembali sebagai first elemen dengan INFO(last) = INFO(last) - tQ
- jika INFO(last) <= tQ, maka deleteLast(l, x) dan menampilkan x ke layar */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
l terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai dengan aturan round-robin
l mungkin menjadi kosong. */
float average (List l){
    Address p = FIRST(l);
    float sum = 0;
    int count = 0;
    do{
        count++;
        sum += INFO(p);
        p = NEXT(p);
    } while (p != FIRST(l));
    return sum / count;
}

int main(){
    List l;
    ElType tq, ta;
    char command;

    CreateList(&l);
    do{
        scanf("%d", &tq);
    } while (tq <= 0);

    do{
        scanf(" %c", &command);
        if (command=='A'){
            scanf("%d", &ta);
            if (ta>0){
                insertFirst(&l, ta);
            }
        }else if (command=='D'){
            deleteRR(&l, tq);
        }else if(command =='F'){
            if (!isEmpty(l)){
                printf("%.2f\n", average(l));
            }else{
                printf("Proses selesai\n");
            }
        }else{
            printf("Kode salah\n");
        }
    } while (command != 'F');
    return 0;
}