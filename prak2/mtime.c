// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 8 September 2022
// Topik Praktikum: ADT Sederhana
// Deskripsi: durasi telepon

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "boolean.h"

int main(){
    //Kamus lokal
    int n;
    long int durasi;
    TIME tmax, tmin,t1,t2;
    //inisiasi variabel waktu
    Hour(tmin) = 23;
    Minute(tmin) = 59;
    Second(tmin) = 59;
    Hour(tmax) = 0;
    Minute(tmax) = 0;
    Second(tmax) = 0;

    scanf("%d", &n); /* input jumlah record */
    for (int i = 1; i <= n;i++){
        printf("[%d]\n", i);
        BacaTIME(&t1);
        BacaTIME(&t2);
        if (TLT(t1,t2)){
            durasi=Durasi(t1, t2);
        }else{
            durasi = Durasi(t2, t1);
        }
        printf("%ld\n", durasi);
        if (TIMEToDetik(t1)<=TIMEToDetik(tmin)){
            tmin = t1;
        }
        if (TIMEToDetik(t2)<=TIMEToDetik(tmin)){
            tmin = t2;
        }
        if (TIMEToDetik(t1)>=TIMEToDetik(tmax)){
            tmax = t1;
        }
        if (TIMEToDetik(t2)>=TIMEToDetik(tmax)){
            tmax = t2;
        }
    }
    TulisTIME(tmin);
    printf("\n");
    TulisTIME(tmax);
    printf("\n");
    return 0;
}