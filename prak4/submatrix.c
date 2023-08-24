// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 22 September 2022
// Topik Praktikum: ADT matrix
// Deskripsi: realisasi adt matrix 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

int countNot0 (Matrix m, int M, IdxType iRow, IdxType jCol){
	// menghitung banyaknya 0
	int count=0,i,j;
	for (i=iRow; i< (IdxType)M+iRow ; i++){
		for (j=jCol;j<(IdxType)M+jCol;j++){
			if (ELMT(m,i,j)!=0){
				count++;
			}
		}
	}
	return count;
}

int main(){
	int N,M , i, j;
	scanf("%d",&N);
	scanf("%d",&M);
	Matrix m1;
	readMatrix(&m1,N,N);

	// inisiasi banyaknya 0 minimal
	int max = 0,daerah = 1;
	for (i=0; i< (N-M+1) ; i++){
		for (j=0;j<(N-M+1);j++){
			if (countNot0(m1,M,i,j)> max){
				daerah = (N-M+1)*i +j +1;
				max = countNot0(m1,M,i,j);
			}
		}
	}

	printf ("%d\n",daerah);
	return 0;
}