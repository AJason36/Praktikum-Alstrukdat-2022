#include <stdio.h>
#include <stdlib.h>
#include "prioqueuetime.c"

int main(){
    PrioQueueTime PQ;
    infotype a;
    MakeEmpty(&PQ, 2);
    
    do{
        scanf("%d %c", &a.time, &a.info);
        Enqueue(&PQ, a);
        printf("nbelmt = %d\n", NBElmt(PQ));
        PrintPrioQueueTime(PQ);
    } while (!IsFull(PQ));
    printf("full = %d\n", IsFull(PQ));
    return 0;
}