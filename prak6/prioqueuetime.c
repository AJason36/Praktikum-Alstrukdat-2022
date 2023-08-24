// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 5 Oktober 2022
// Topik Praktikum: queue
// Deskripsi: realisasi queuetime


#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
	return (Head(Q)==Nil && Tail(Q)==Nil);
};
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueTime Q){
	return NBElmt(Q) == MaxEl(Q);
};
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueTime Q){
	if (IsEmpty(Q)){
		return 0 ;
	}
	else
	{
		if (Tail(Q)>=Head(Q)){
	        return Tail(Q) - Head(Q) + 1;
	    }else{
            return Tail(Q) - Head(Q) + MaxEl(Q) + 1;
	    }
	}
};
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max)
{
	(*Q).T = (infotype *) malloc (Max * sizeof(infotype));
	MaxEl(*Q) = Max;
	Head(*Q) = Nil;
	Tail(*Q) = Nil;
};
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q)
{
	free((*Q).T);
	MaxEl(*Q)=0; 
};
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
	if(!IsEmpty(*Q)){
		Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
		InfoTail(*Q) = X;
		int i = (Tail(*Q));
		infotype temp;

		while (i != Head(*Q))
		{
			int idxBefore = (i - 1 + MaxEl(*Q)) % MaxEl(*Q);
			if (Time(Elmt(*Q,i))<Time(Elmt(*Q,idxBefore))){
				temp = Elmt(*Q, i);
				Elmt(*Q, i) = Elmt(*Q, idxBefore);
				Elmt(*Q, idxBefore) = temp;
			}
			i = idxBefore;
		}
	}else{
		Head(*Q) =0;
		Tail(*Q) = 0;
		InfoTail(*Q) = X;
    }
};
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueTime * Q, infotype * X){
	*X = InfoHead(*Q);
	if (NBElmt(*Q)==1){
	        // jika hanya 1 elemen pada Queue, maka Queue menjadi kosong
	        Head(*Q) = Nil;
	        Tail(*Q) = Nil;
    	}else{
	        if (Head(*Q) == MaxEl(*Q)-1){
	            Head(*Q) = 1;
	        }else{
	            Head(*Q)++;
	        }
    	}
};
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
	if (IsEmpty(Q)){
 		printf("#\n");
	}else{
		int i,j;
		if (Tail(Q)-Head(Q) < 0){
	            //print head terlebih dahulu hingga idx maxel-1
	            for (i = Head(Q); i < MaxEl(Q);i++){
	                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
	            }
	            for (j = 0; j < Tail(Q) + 1;j++){
	                if (j!=Tail(Q)){
	                    printf("%d %c\n", Time(Elmt(Q,j)), Info(Elmt(Q,j)));
	                }else{
	                    //jika buffer merupakan elemen terakhir
	                    printf("%d %c\n", Time(Elmt(Q,j)), Info(Elmt(Q,j)));
	                }
	            }
	            printf("#\n");
	        }else{
	            for (i = Head(Q); i < Tail(Q) + 1;i++){
	                if (i!=Tail(Q)){
	                    printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
	                }else{
	                    //jika buffer merupakan elemen terakhir
	                    printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
	                }
	            }
	            printf("#\n");
	        }
	   }
};
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/