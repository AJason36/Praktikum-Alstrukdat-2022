// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 5 Oktober 2022
// Topik Praktikum: queue
// Deskripsi: realisasi sjf


#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.h"

int main(){
	PrioQueueTime q;
	int n, jam=0,i=0;
	infotype val, pc;
	scanf("%d",&n);
	MakeEmpty(&q, n);

	while(i < n || !IsEmpty(q)){
		if (i<n){
			scanf("%d %c", &pc.time, &pc.info);
			Enqueue(&q, pc);}
		if (i == jam){
			Dequeue(&q, &val);
			jam += val.time;
			printf("%d %c\n", i, val.info);
			// printf jam dimulainya proses stlh dequeue
		}
		i++;
	}
	return 0;
}