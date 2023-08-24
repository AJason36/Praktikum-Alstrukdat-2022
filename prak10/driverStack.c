// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 10 November 2022
// Topik Praktikum: List berkait stack queue 
// Deskripsi: realisasi list berkait queue

#include "stacklinked.c"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

boolean isSame(Stack s1, Stack s2){
    if (length(s1)!= length(s2)){
        return false;
    }else{
        ElType var1, var2;
        while(!isEmpty(s2)){
            pop(&s1, &var1);
            pop(&s2, &var2);
            if(var1 != var2){
                return false;
            }
        }
    }
    return true;
}
int main(){
    Stack s1, s2;
    int n,m,var1, var2,i, temp1, temp2;

    CreateStack(&s1);
    CreateStack(&s2);
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++){
        scanf("%d", &var1);
        if(var1!=0){
            push(&s1, var1);
        }else{
            if(!isEmpty(s1)){
                pop(&s1, &temp1);
            }
        }
    }
    for (i = 0; i < m; i++){
        scanf("%d", &var2);
        if(var2!=0){
            push(&s2, var2);
        }else{
            if(!isEmpty(s2)){
                pop(&s2, &temp2);
            }
        }
    }
    if (isSame(s1,s2)){
        printf("Sama\n");
    }else{
        printf("Tidak sama\n");
    }
    return 0;
}