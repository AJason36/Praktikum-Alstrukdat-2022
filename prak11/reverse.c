 // NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 17 November 2022
// Topik Praktikum: List berkait rekursif 
// Deskripsi: realisasi list berkait rekursif
#include "listrec.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>


List inverseList2 (List l){
    if(isEmpty(l)){
        return NULL;
    }else{
        return konsb(inverseList2(tail(l)), head(l));
    }
};
void displayList2(List l){
    if(isOneElmt(l)){
        printf("%d", head(l));
    }
    else if (!isEmpty(l)){
        printf("%d ", head(l));
        displayList2(tail(l));
    }
}
List split(List l, int curr, int start, int finish){
    if (isEmpty(l) || start>finish){
        return NULL;
    }else if(curr>=start){
        return konso(split(tail(l), curr + 1, start+1, finish), head(l));
    }else{
        return split(tail(l), curr + 1, start, finish);
    }
}
int main(){
    List l;
    l = NULL;
    int i=0, n,k, x;
    scanf("%d %d", &n, &k);
    // int arr[n];

    for(i=0;i<n;i++){
        scanf("%d",&x);
        l=konsb(l, x);
    }
    i = 0;

    boolean done = false;
    List inversL=NULL;
    while (!done)
    {
        if (i>= n){
            done = true;
        }else{
            inversL =inverseList2(split(l, 0, i, i + k - 1));
            displayList2(inversL);
            i += k;
            if(i<n){
                printf(" ");
            }
        }
    }
    printf("\n");

}