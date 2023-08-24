
// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 29 September 2022
// Topik Praktikum: mesin Karakter
// Deskripsi: realisasi mesin karakter 

#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

int main()
{
	STARTWORD();
	int max = currentWord.Length;

	while (!EndWord){
		if (currentWord.Length>max){
			max = currentWord.Length;
		}
		ADVWORD();
	}
	printf("%d\n",max);
	/* code */
	return 0;
}
