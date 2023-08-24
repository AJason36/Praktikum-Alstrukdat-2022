// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 10 November 2022
// Topik Praktikum: List berkait stack queue 
// Deskripsi: realisasi list berkait queue

#include "queuelinked.h"
#include "charmachine.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
boolean isElHomogen(Queue q){
	if (isEmpty(q) || length(q)==1){
        return true;
    }else{
        Address p = ADDR_HEAD(q);
        ElType temp = HEAD(q);
        while(p!=ADDR_TAIL(q)){
        	if (INFO(p)!=temp){
        		return false;
        	}
            p = NEXT(p);
        }
        if(INFO(p)==temp){
        	return true;
        }else{
        	return false;
        }
    }
}

int main(){
	boolean move = false;
	START();
	Queue qSand, qM, qNomor;
	CreateQueue(&qSand);
	CreateQueue(&qM);
	CreateQueue(&qNomor);
	int val1,val2;
	int i = 1;
	while(currentChar!=','){
		if(currentChar=='B'){
			enqueue(&qM,0);
		}else{
			enqueue(&qM,1);		
		}
		enqueue(&qNomor, i);
		i++;
		ADV();
	}
	ADV();
	while (!EOP)
	{
		if(currentChar=='B'){
			enqueue(&qSand,0);
		}else if (currentChar == 'K'){
			enqueue(&qSand,1);
		}
		
		ADV();
	}
	boolean done=false;
	int nomor, sandwich, mau;
	
	while(!isEmpty(qM) && !done){
		if(isElHomogen(qM)){
			if (HEAD(qM)!= HEAD(qSand)){
				done = true;
			}else{
				done = false;
			}
		}
		if(!done){
			if (HEAD(qM)==HEAD(qSand)){
				dequeue(&qM,&mau);
				dequeue(&qSand, &sandwich);
				dequeue(&qNomor, &nomor);
				if(sandwich==1){
					printf("%d -> ", nomor);
					printf("kotak\n");
				}else{
					printf("%d -> ", nomor);
					printf("bulat\n");
				}
			}
			else{
				dequeue(&qM,&mau);
				enqueue(&qM, mau);
				dequeue(&qNomor, &nomor);
				enqueue(&qNomor, nomor);
			}
		}
		
	}
	printf("%d\n", length(qM));
	return 0;
}