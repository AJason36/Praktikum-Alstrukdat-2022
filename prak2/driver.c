#include <stdio.h>
#include <stdlib.h>
#include "garis.h"

int main() {
    printf("WALALA\n");
    GARIS L1,L2;
    BacaGARIS(&L1);
    TulisGARIS(L1);
    printf("\nPanjang garis: %f", PanjangGARIS(L1));
    printf("\nGradien %f", Gradien(L1));
    GeserGARIS(&L1, 4.2, 5.5);
    TulisGARIS(L1);
    BacaGARIS(&L2);
    printf("%d", IsSejajar(L1,L2));
    return 0;
}
