// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 6 Oktober 2022
// Topik Praktikum: queue
// Deskripsi: realisasi antrian six

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	int inp;
	Queue q;
	ElType val,total=0,count=0, max=0,min=999999;
	CreateQueue(&q);
	do{
		scanf("%d",&inp);
		if (inp==1){
			scanf("%d", &val);
			if(isFull(q)){
				printf("Queue penuh\n");
			}else{
				enqueue(&q, val);

			}
		}else if (inp ==2){
			if(isEmpty(q)){
				printf("Queue kosong\n");
			}else{
				dequeue(&q,&val);
				total+=val;
				count++;
				if(max<=val){
					max=val;
				}
				if(min>=val){
					min=val;
				}
			}
		}

	}while (inp!=0);

	if (count ==0){
		printf("%d\n",count);
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
		printf("Tidak bisa dihitung\n");
	}else{
		printf("%d\n",count);
		printf("%d\n",min);
		printf("%d\n",max);
		printf("%.2f\n",(float)total / (float)count);
	}
	return 0;
}