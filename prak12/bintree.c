// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 23 November 2022
// Topik Praktikum: List berkait tree 
// Deskripsi: realisasi list berkait tree
#include "bintree.h"
#include <stdlib.h>
#include "boolean.h"
#include <stdio.h>
BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree p = (Address)malloc(sizeof(TreeNode));
    if (p!=NULL){
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
}; 
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil 
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = (Address)malloc(sizeof(TreeNode));
    if (p!=NULL){
        ROOT(*p) = root;
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
};
/* I.S. Sembarang
   F.S. Menghasilkan sebuah pohon p
   Menghasilkan sebuah pohon biner p dari akar, l, dan r, jika alokasi 
   berhasil 
   Menghasilkan pohon p yang kosong (NULL) jika alokasi gagal */

Address newTreeNode(ElType val){
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p!=NULL){
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
};
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */

void deallocTreeNode (Address p){
    free(p);
};
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
};
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt (BinTree p){
    return (p!=NULL && RIGHT(p)==NULL && LEFT(p)==NULL);
};
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

boolean isUnerLeft (BinTree p){
    return (p!=NULL && RIGHT(p)==NULL && LEFT(p)!=NULL);
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerleft: 
   hanya mempunyai subpohon kiri */

boolean isUnerRight (BinTree p){
    return (p!=NULL && RIGHT(p)!=NULL && LEFT(p)==NULL);
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon unerright: 
   hanya mempunyai subpohon kanan */

boolean isBinary (BinTree p){
    return (p!=NULL && RIGHT(p)!=NULL && LEFT(p)!=NULL);
};
/* Mengirimkan true jika pohon biner tidak kosong, p adalah pohon biner: 
  mempunyai subpohon kiri dan subpohon kanan */

/* ****** Display Tree ***** */
void printPreorder(BinTree p){
    printf("(");
    if(p!=NULL){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */

void printInorder(BinTree p){
    printf("(");
    if(p!=NULL){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */

void printPostorder(BinTree p){
    printf("(");
    if(p!=NULL){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
};
/* I.S. p terdefinisi */
/* F.S. Semua simpul p sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void printTreeChild(BinTree p, int h, int childCount){
    if (p!=NULL){
        int i, space = h * childCount;
        for (i = 0; i < space; i++){
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        childCount++;
        printTreeChild(LEFT(p), h, childCount);
        printTreeChild(RIGHT(p), h, childCount);
    }
}
void printTree(BinTree p, int h){
    if(p!=NULL){
        printTreeChild(p, h, 0);
    }
};
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
int rob1(BinTree root){
    if(isTreeEmpty(root)){
        return 0;
    }else if(isOneElmt(root)){
        return ROOT(root);
    }else if(isBinary(root)){
        if(LEFT(LEFT(root))==NULL && RIGHT(RIGHT(root))==NULL && RIGHT(LEFT(root))== NULL && LEFT(RIGHT(root))==NULL){
            if (ROOT(LEFT(root))>ROOT(RIGHT(root))){
                return ROOT(root)+ROOT(LEFT(root));
            }else{
                return ROOT(root)+ROOT(RIGHT(root));
            }
        }else{
            int left = rob1(LEFT(root)), right = rob1(RIGHT(root)), max=left;
            if(right>max){
                max=right;
            }
            return ROOT(root)+max;
        }
    }
    // else if(isUnerLeft(root)){
    //     int temp = rob1(LEFT(root));
    //     return ROOT(root)+temp;
    // }else if(isUnerRight(root)){
    //     int temp = rob1(RIGHT(root));
    //     return ROOT(root)+temp;
    // }
    else{
        int left = rob1(LEFT(root)), right = rob1(RIGHT(root)), max=left;
        if(right>max){
            max=right;
        }
        return ROOT(root)+max;
    }
};
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.
// int maxTree(BinTree p){
//     if (isOneElmt(p)){
//         return ROOT(p);
//     }else if(isUnerLeft){
//         return
//     }
// }

int rob2(BinTree root){
    if(isTreeEmpty(root)){
        return 0;
    }else {
        int ganjil = ROOT(root), genap = 0;
        genap += rob2(LEFT(root)) + rob2(RIGHT(root));
        if(!isTreeEmpty(RIGHT(root))){
            ganjil += rob2(RIGHT(RIGHT(root))) + rob2(LEFT(RIGHT(root)));
        }
        if(!isTreeEmpty(LEFT(root))){
            ganjil += rob2(LEFT(LEFT(root))) + rob2(RIGHT(LEFT(root)));
        }
        if(ganjil>genap){
            return ganjil;
        }else{
            return genap;
        }
    }
};
// Menerima sebuah ruangan rumah yang akan dirampok.
// Mengembalikan hasil rampokan yang terbesar.