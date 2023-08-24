// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 20 Oktober 2022
// Topik Praktikum: stack
// Deskripsi: realisasi bigint

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"

boolean operator(char x){
	if ((x=='*') || (x=='+') || (x=='-') || (x=='/') || (x=='^')){
		return true;
	}
	return false;
}

int proses(int a1,int a2, char op){
	if (op=='*'){
		return a1*a2;
	}else if (op=='+'){
		return a1+a2;
	}else if (op=='/'){
		return a1/a2;
	}else if (op=='-'){
		return a1-a2;
	}else if (op=='^'){
		int tes = pow(a1,a2);
		return tes;
	}
}
int main(){
	Stack s;
	int a1, a2, final, pros, tes, i=0;
	CreateEmpty(&s);
	STARTWORD();
	if (endWord){
		printf("Ekspresi kosong\n");
	}else{
		while (!endWord){
			tes=0;
			i=0;
			if (!operator(currentWord.TabWord[0])){
				while(i<currentWord.Length){
					printf("%c", currentWord.TabWord[i]);
					tes =(int)(currentWord.TabWord[i]-48) + (tes*10);
					i++;
				}
				printf("\n");
				Push(&s,tes);
				tes=0;
				i=0;
				ADVWORD();
				// while(i<currentWord.Length){
				// 	printf("%c", currentWord.TabWord[i]);
				// 	tes =(int)(currentWord.TabWord[i]-48) + (tes*10);
				// 	i++;
				// }
				// Push(&s,tes);
				// printf("\n");
			}else{
				Pop(&s, &a1);
				Pop(&s, &a2);
				printf("%d %c %d\n",a2,currentWord.TabWord[0], a1);
				pros = proses(a2,a1,currentWord.TabWord[0]);
				printf("%d\n", pros);
				Push(&s, pros);
				ADVWORD();
			}
			
		}
		Pop(&s, &final);
		printf("Hasil=%d\n",final);
	}
}