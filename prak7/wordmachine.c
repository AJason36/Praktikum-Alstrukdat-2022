// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 21 September 2022
// Topik Praktikum: mesin Karakter
// Deskripsi: realisasi mesin karakter 

#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

/* State Mesin Word */
boolean endWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK){
        ADV();
    }
};
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void CopyWord(){
    int i=0;
    while ((currentChar!=MARK)&&(currentChar!=BLANK)&&(i<=NMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        if (i<NMax){
            i++;
        }
    }
    currentWord.Length = i;
};
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */


void STARTWORD(){
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }else{
        endWord = false;
        CopyWord();
        IgnoreBlanks();
    }
};
/* I.S. : currentChar sembarang
   F.S. : endWord = true, dan currentChar = MARK;
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar== MARK){
        endWord = true;
    }else{
        CopyWord();
        IgnoreBlanks();
    }
};
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void LowerCase(){
  int i;
  for (i = 0; i < currentWord.Length;i++){
    if ((int)currentWord.TabWord[i]<=90 && (int)currentWord.TabWord[i]>=65){
            currentWord.TabWord[i]+=32;
    }
  }
};

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
/* F.S. currentword menjadi lowercase di setiap karakternya */
// currentWord.TabWord[i]!=MARK && 