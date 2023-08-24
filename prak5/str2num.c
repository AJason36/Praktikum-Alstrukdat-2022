// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 29 September 2022
// Topik Praktikum: mesin Karakter
// Deskripsi: realisasi mesin Str2num 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordmachine.h"
#include "charmachine.h"

boolean endWord;
Word currentWord;
int lenw(char *kata)
{
	int i = 0;
	int res = 0;
	while (kata[i] != '\0')
	{
		res++;
		i++;
	}
	return res;
}
boolean same(char *word, Word currentWord){
	if(lenw(word) == currentWord.Length){
		int i;
		for (i = 0; i < currentWord.Length;i++){
			if (currentWord.TabWord[i]!= word[i]){
				return false;
			}
		}
	}else{
		return false;
	}
	return true;
}

int main()
{
	STARTWORD();
	int val = 0, angka = 0;
	boolean adAngk = false, adRatus = false;
	// char zero[] = "nol";
	// char one[] = "satu";
	// char two[] = "dua";
	while (!endWord)
	{
		if (same("satu",currentWord)){
			angka += 1;
			adAngk = true;
		}else if (same("dua",currentWord)){
			angka += 2;
			adAngk = true;
		} else if (same("tiga",currentWord)){
			angka += 3;
			adAngk = true;
		} else if (same("empat",currentWord)){
			angka += 4;
			adAngk = true;
		} else if (same("lima",currentWord)){
			angka += 5;
			adAngk = true;
		} else if (same("enam",currentWord)){
			angka += 6;
			adAngk = true;
		} else if (same("tujuh",currentWord)){
			angka += 7;
			adAngk = true;
		} else if (same("delapan",currentWord)){
			angka += 8;
			adAngk = true;
		} else if (same("sembilan",currentWord)){
			angka += 9;
			adAngk = true;
		} else if (same("sepuluh",currentWord)){
			angka +=10;
			adAngk = true;
		}  else if (same("puluh",currentWord)){
			angka = (angka%10)*10 +(angka/10)*10;
			adAngk = true;
		} else if (same("sebelas",currentWord)){
			angka += 11;
			adAngk = true;
		} else if (same("seratus",currentWord)){
			angka += 100;
			adAngk = true;
		} else if (same("nol",currentWord)){
			angka += 0;
			adAngk = true;
		}
		else if (same("belas",currentWord)){
			angka +=10;
			adAngk = true;
		}
		else if (same("ratus",currentWord)){
			angka *=100;
			adAngk = true;
		}else{
			if(adAngk){
				printf("%d ", angka);
				angka = 0;
				adAngk = false;
			}
			int i;
			for (i = 0; i < currentWord.Length;i++){
				printf("%c", currentWord.TabWord[i]);
			}
		}
		ADVWORD();
		if(!endWord && !adAngk){
			printf(" ");
		}
	}
	if (adAngk){
		printf("%d", angka);
	}
	printf("\n");
	/* code */
	return 0;
}