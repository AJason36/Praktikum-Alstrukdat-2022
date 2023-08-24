// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 27 Oktober 2022
// Topik Praktikum: List berkait
// Deskripsi: realisasi no 2

#include "listlinier.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	List l;
	CreateList(&l);
	int N, Q, i, sumH=0, sumM=0;
	ElType op, val;

	scanf("%d", &N);
	scanf("%d", &Q);
	for (i=0;i<Q;i++){
		scanf("%d",&op);
		if(N==0){
			printf("miss ");
			displayList(l);
			printf("\n");
			sumM++;
		}
		else if (isEmpty(l)){
			printf("miss ");
			insertFirst(&l, op);
			displayList(l);
			printf("\n");
			sumM++;
		}else{
			int k=0;
			Address p = l;
			boolean found = false;
			while(p!=NULL && !found){
				if (getElmt(l,k)==op){
					found = true;
				}else{
					p = NEXT(p);
				}
				k++;
			}


			if (!found && (length(l)==N)){
				printf("miss ");
				deleteLast(&l, &val);
				insertFirst(&l, op);
				displayList(l);
				printf("\n");
				sumM++;
			}else if (!found){
				printf("miss ");
				insertFirst(&l, op);
				displayList(l);
				printf("\n");
				sumM++;
			}else{
				printf("hit ");
				deleteAt(&l,indexOf(l,op),&val);
				insertFirst(&l,op);
				displayList(l);
				printf("\n");
				sumH++;
			}
		}
	}
	float ratio;
	if (sumH==0 && sumM==0){
		ratio=0;
	}else{
		ratio = (float)sumH / ((float)(sumH+sumM));
	}
	printf("hit ratio: %0.2f\n", ratio);
	return 0;
}