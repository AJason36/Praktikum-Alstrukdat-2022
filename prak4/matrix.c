// NIM: 13521100
// Nama: Alexander Jason
// Tanggal: 21 September 2022
// Topik Praktikum: ADT matrix
// Deskripsi: realisasi adt matrix 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m){
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m)=nRows;
    COL_EFF(*m) = nCols;
}

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j){
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
   return (i < ROW_CAP && j < COL_CAP && i>=0 && j>=0);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m){
/* Mengirimkan Index baris terbesar m */
   return (ROW_EFF(m) - 1);
}
IdxType getLastIdxCol(Matrix m){
/* Mengirimkan Index kolom terbesar m */
   return (COL_EFF(m) - 1);
}
boolean isIdxEff(Matrix m, IdxType i, IdxType j){
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
   return ((i >= 0) && (i < ROW_EFF(m)) && (j >= 0) && (j < COL_EFF(m)));
}
ElType getElmtDiagonal(Matrix m, IdxType i){
/* Mengirimkan elemen m(i,i) */
   return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut){
/* Melakukan assignment mOut <- mIn */

   createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
   int i, j;
   for ( i = 0; i < ROW_EFF(mIn); i++) {
        for ( j = 0; j < COL_EFF(mIn); j++) {
            ELMT(*mOut, i, j) = ELMT(mIn, i , j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
   int i, j;
   createMatrix(nRow,nCol,m);
   for (i = 0; i <=getLastIdxRow(*m);i++){
      for (j = 0; j <= getLastIdxCol(*m);j++){
         scanf("%d", &ELMT(*m, i, j));
      }
   }
}
void displayMatrix(Matrix m){
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi. Baris terakhir  diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
   int i, j;

   for ( i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m)-1; j++) {
            printf("%d ", ELMT(m, i, j));
        }
        printf("%d", ELMT(m, i, COL_EFF(m) - 1));
        printf("\n");
    }
}
/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
   Matrix m;
   createMatrix(ROW_EFF(m1), COL_EFF(m1),&m);
   int i, j;
   for (i = 0; i < ROW_EFF(m1);i++){
      for (j = 0; j < COL_EFF(m1);j++){
         ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
      }
   }
   return m;
}
Matrix subtractMatrix(Matrix m1, Matrix m2){
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
   Matrix m;
   createMatrix(ROW_EFF(m1), COL_EFF(m1),&m);
   int i, j;
   for (i = 0; i < ROW_EFF(m1);i++){
      for (j = 0; j < COL_EFF(m1);j++){
         ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
      }
   }
   return m;
}
Matrix multiplyMatrix(Matrix m1, Matrix m2){
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
   Matrix m;
    int i, j, k;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m);
    for (i = 0; i <= ROW_EFF(m1); i++)
    {
        for (j = 0; j <= COL_EFF(m2); j++)
        {
            ELMT(m, i, j) = 0;
            for (k = 0; k <= COL_EFF(m1); k++)
            {
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}
Matrix multiplyByConst(Matrix m, ElType x){
/* Mengirim hasil perkalian setiap elemen m dengan x */
   Matrix m1;
   int i, j;
   createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
   for (i = 0; i < ROW_EFF(m); i++)
   {
      for (j = 0; j < COL_EFF(m); j++)
      {
         ELMT(m1, i, j) = ELMT(m, i, j) * x;
      }
      }
      return m1;
}
void pMultiplyByConst(Matrix *m, ElType k){
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */
   int i, j;
   for (i = 0; i < ROW_EFF(*m);i++){
      for (j = 0; j < COL_EFF(*m);j++){
         ELMT(*m, i, j) = ELMT(*m, i, j) * k;
      }
   }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
   return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}
boolean isMatrixEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
   if (!isMatrixSizeEqual(m1,m2) || countElmt(m1)!=countElmt(m2)){
      return false;
   }
   int i, j;   
   for (i = 0; i < ROW_EFF(m1);i++){
      for (j = 0; j < COL_EFF(m1);j++){
         if (ELMT(m1, i, j) != ELMT(m2, i, j)){
            return false;
         }
      }
   }
   return true;
}
boolean isMatrixNotEqual(Matrix m1, Matrix m2){
/* Mengirimkan true jika m1 tidak sama dengan m2 */
   return (!isMatrixEqual(m1, m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m){
/* Mengirimkan banyaknya elemen m */
   return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
   return (ROW_EFF(m) == COL_EFF(m));
}
boolean isSymmetric(Matrix m){
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
   if (!isSquare(m)){
      return false;
   }
   int i, j;   
   for (i = 0; i < ROW_EFF(m);i++){
      for (j = 0; j < COL_EFF(m);j++){
         if (ELMT(m, i, j) != ELMT(m, j, i)){
            return false;
         }
      }
   }
   return true;
}
boolean isIdentity(Matrix m){
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
   if (!isSquare(m)){
      return false;
   }
   int i, j;   
   for (i = 0; i < ROW_EFF(m);i++){
      for (j = 0; j < COL_EFF(m);j++){
         if (i==j){
            if (ELMT(m,i,j)!=1){
               return false;
            }
         }else{
            if (ELMT(m,i,j)!=0){
               return false;
            }
         }
      }
   }
   return true;
}
boolean isSparse(Matrix m){
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
   int i, j, count = 0;
   for (i = 0; i < ROW_EFF(m); i++)
   {
      for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count++;
            }
        }
    }
    return (count <= (0.05 * countElmt(m)));   
   
}
Matrix negation(Matrix m){
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
   return multiplyByConst(m, (-1));
}
void pNegation(Matrix *m){
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
   pMultiplyByConst(m, -1);
}
float determinant(Matrix m){
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
   int i, j, k,p, var=1;
   Matrix mFac;
   float det;
   if (countElmt(m)==1){
      det= (float)ELMT(m,0,0);
   }else if (countElmt(m)==4){
      det = (ELMT(m, 0, 0) * ELMT(m, 1, 1)) - (ELMT(m, 1, 0) * ELMT(m, 0, 1));
      det = (float)(det);
   }else{
      // buat matrix lebih kecil untuk kofaktor
      createMatrix(ROW_EFF(m) - 1, COL_EFF(m) - 1, &mFac);
      det = 0;
      for (i = 0; i < ROW_EFF(m);i++){
         for (j = 1; j < ROW_EFF(m);j++){
            for (k = 0; k < COL_EFF(m);k++){
               // jika kolom =  baris yg digunakan sbg var det, maka diabaikan
               if (k==i){
                  continue;
               }else if(k<i){
                  p = k;
               }else{
                  // jika k lebih besar dari nilai baris det, maka posisi k di matrix cofactor berkurang1
                  p = k - 1;
               }
               ELMT(mFac, j - 1, p) = ELMT(m, j, k);
            }
         }
         det += var * ELMT(m, 0, i) * determinant(mFac);
         var *= -1; //untuk penanda minus atau plus
      }
   }
   return det;
}
Matrix transpose(Matrix m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   Matrix m1;
   int i, j;
   createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
   // copyMatrix(m, &m1);
   for (i = 0; i < ROW_EFF(m);i++){
      for (j = 0; j < COL_EFF(m);j++){
         ELMT(m1, i, j) = ELMT(m, j, i);
      }
   }
   return m1;
}
void pTranspose(Matrix *m){
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
   Matrix m1;
   m1 = transpose(*m);
   copyMatrix(m1, m);
}

/* Operasi berbasis baris dan per kolom */
float AvgRow(Matrix M, IdxType i){
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
   int j;
   float sum=0;
   for (j=0;j<COL_EFF(M);j++){
      sum+=ELMT(M,i,j);
   }
   return sum/COL_EFF(M);
}

float AvgCol(Matrix M, IdxType j){
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
   int i;
   float sum=0;
   for (i=0;i<ROW_EFF(M);i++){
      sum+=ELMT(M,i,j);
   }
   return sum/ROW_EFF(M);
}

void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min){
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
min berisi elemen minimum pada baris i dari M */
   *max = ELMT(M,i,0);
   *min =ELMT(M,i,0);

   int j;   

   for (j = 0; j < COL_EFF(M);j++){
      if (ELMT(M, i, j) >= *max){
         *max = ELMT(M,i,j);
      }
      if (ELMT(M, i, j) <= *min){
         *min = ELMT(M,i,j);
      }
   }
   
}
void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min){
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
min berisi elemen minimum pada kolom j dari M */
   *max = ELMT(M,0,j);
   *min =ELMT(M,0,j);

   int i;   

   for (i = 0; i < ROW_EFF(M);i++){
      if (ELMT(M, i, j) >= *max){
         *max = ELMT(M,i,j);
      }
      if (ELMT(M, i, j) <= *min){
         *min = ELMT(M,i,j);
      }
   }
}
int CountNumRow(Matrix M, IdxType i, ElType X){
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
   int j,count=0;
   for (j=0;j<COL_EFF(M);j++){
      if (ELMT(M,i,j)==X){
         count++;
      }
   }
   return count;
}

int CountNumCol(Matrix M, IdxType j, ElType X){
/* Menghasilkan banyaknya kemunculan X pada klom j dari M */
   int i,count=0;
   for (i=0;i<ROW_EFF(M);i++){
      if (ELMT(M,i,j)==X){
         count++;
      }
   }
   return count;
}

void RotateMat(Matrix *m){
   Matrix mTemp;
   copyMatrix(*m, &mTemp);
   int i,j, len = getLastIdxRow(*m)+1, sRow=0;
   while (len > 1)
   {
     int sCol = sRow;
     for ( i = sRow; i < sRow + len ; i++)
     {
        for ( j = sCol; j < sCol+len; j++)
        {
           if (i == sRow && j != sCol-1 +len) // baris atas geser ke kanan
           {
              ELMT(*m, i, j + 1) = ELMT(mTemp, i, j);
           }
           else if (i == sRow-1 +len && j != sCol) //baris bawah geser ke kiri
           {
              ELMT(*m, i, j - 1) = ELMT(mTemp, i, j);
           }
           else if (j == sCol && i != sRow) // baris kiri geser ke atas
           {
              ELMT(*m, i-1, j) = ELMT(mTemp, i, j);
           }
           else if (j == sCol-1 +len  && i != sRow-1 +len) // baris kanan geser ke bawah
           {
              ELMT(*m, i+1 , j) = ELMT(mTemp, i, j);
           }
        }
     }
     sRow++;
     len -= 2; //mengurangi ukuran matrix 
   }
};

