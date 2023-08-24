#include "bintree.c"
#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>
void testInvertBtree(BinTree *p)
/* I.S. Pohon p terdefinisi */
/* F.S. Pohop p diflip secara vertikal*/
{
    /* KAMUS */
    BinTree temp;

    /* ALGORITMA */
    if (!isTreeEmpty(*p)) {
        temp = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = temp;
        
        testInvertBtree(&LEFT(*p));
        testInvertBtree(&RIGHT(*p));
    }
}
BinTree sumTree(int level) {
    /* KAMUS */
    BinTree p1, p2;
    ElType val;
    
    /* ALGORITMA */
    if (level == 0) {
        scanf("%d", &val);
        return newTreeNode(val);
    } else {
        p1 = sumTree(level - 1);
        p2 = sumTree(level - 1);
        return NewTree(ROOT(p1) + ROOT(p2), p1, p2);
    }
}

int main() {
    /* KAMUS */
    int N, level;
    BinTree p;

    /* ALGORITMA */
    scanf("%d", &N);

    level = 0;
    while (N % 2 == 0 && N > 1) {
        N = N / 2;
        level++;
        printf("%d\n", N);
    }

    if (N != 1) {
        printf("pohon tidak bisa dibentuk\n");
    } else {
        p = sumTree(level);
        printTree(p, 2);
    }
}