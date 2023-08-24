#include "matrix.h"
#include <stdio.h>
#include "boolean.h"
#include <math.h>

int main(){
    Matrix M1,M2;
    int i = 3;
    int j = 3;
    readMatrix(&M1, i, j);
    displayMatrix(M1);
    printf("%d\n", isMatrixEqual(M1,M2));
    RotateMat(&M1);
    displayMatrix((M1));
    return 0;
}