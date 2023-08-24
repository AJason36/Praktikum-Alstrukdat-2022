#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m)
{
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
};
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
// #define ROW_EFF(M) (M).rowEff
// #define COL_EFF(M) (M).colEff
// #define ELMT(M, i, j) (M).mem[(i)][(j)]

/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
};
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    return (ROW_EFF(m) - 1);
};
/* Mengirimkan Index baris terbesar m */
IdxType getLastIdxCol(Matrix m)
{
    return (COL_EFF(m) - 1);
};
/* Mengirimkan Index kolom terbesar m */
boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    return (i >= 0 && i < ROW_EFF(m)) && (j >= 0 && j < COL_EFF(m));
};
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    return ELMT(m, i, i);
};
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    int i = 0;
    for (; i < ROW_EFF(mIn); i++)
    {
        int j = 0;
        for (; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
};
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    createMatrix(nRow, nCol, m);
    int i = 0;
    for (; i < nRow; i++)
    {
        int j = 0;
        for (i; j < nCol; j++)
        {
            int temp;
            scanf("%d", &temp);
            ELMT(*m, i, j) = temp;
        }
    }
};
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayMatrix(Matrix m)
{
    int i = 0;
    for (; i < ROW_EFF(m); i++)
    {
        int j = 0;
        for (; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != COL_EFF(m) - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
};
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    Matrix ret;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &ret);
    int i = 0;
    for (; i < ROW_EFF(ret); i++)
    {
        int j = 0;
        for (; j < COL_EFF(ret); j++)
        {
            ELMT(ret, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return ret;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    Matrix ret;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &ret);
    int i = 0;
    for (; i < ROW_EFF(ret); i++)
    {
        int j = 0;
        for (; j < COL_EFF(ret); j++)
        {
            ELMT(ret, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return ret;
};
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    Matrix ret;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &ret);
    int i = 0;
    for (; i < ROW_EFF(ret); i++)
    {
        int j = 0;
        for (; j < COL_EFF(ret); j++)
        {
            int res = 0;
            int k = 0;
            for (; k < COL_EFF(m1); k++)
            {
                res += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
            ELMT(ret, i, j) = res;
        }
    }
    return ret;
};
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
Matrix multiplyByConst(Matrix m, ElType x)
{
    Matrix ret;
    createMatrix(ROW_EFF(m), COL_EFF(m), &ret);
    int i = 0;
    for (; i < ROW_EFF(ret); i++)
    {
        int j = 0;
        for (; j < COL_EFF(ret); j++)
        {
            ELMT(ret, i, j) = ELMT(m, i, j) * x;
        }
    }
    return ret;
};
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyByConst(Matrix *m, ElType k)
{
    int i = 0;
    for (; i < ROW_EFF(*m); i++)
    {
        int j = 0;
        for (; j < COL_EFF(*m); j++)
        {
            ELMT(*m, i, j) *= k;
        }
    }
};
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    boolean flag = true;
    if (!isMatrixSizeEqual(m1, m2))
    {
        flag = false;
    }
    if (flag)
    {
        int i = 0;
        for (; i < ROW_EFF(m1) && flag; i++)
        {
            int j = 0;
            for (; j < COL_EFF(m2) && flag; j++)
            {
                if (ELMT(m1, i, j) != ELMT(m2, i, j))
                {
                    flag = false;
                }
            }
        }
    }
    return flag;
};
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return !isMatrixEqual(m1, m2);
};
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
};
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    return ROW_EFF(m) * COL_EFF(m);
};
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    return ROW_EFF(m) == COL_EFF(m);
};
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isSymmetric(Matrix m)
{
    if (!isSquare(m))
    {
        return false;
    }
    int i = 0;
    for (; i < ROW_EFF(m); i++)
    {
        int j = 0;
        for (; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
};
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isIdentity(Matrix m)
{
    if (!isSquare(m))
    {
        return false;
    }
    int i = 0;
    for (; i < ROW_EFF(m); i++)
    {
        int j = 0;
        if (ELMT(m, i, i) != 1)
        {
            return false;
        }
        for (; j < COL_EFF(m); j++)
        {
            if (i != j && ELMT(m, i, j) != 0)
            {
                return false;
            }
        }
    }
    return true;
};
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isSparse(Matrix m)
{
    double temp = 0.05 * (double)(countElmt(m));
    int i = 0;
    double notZero = 0;
    for (; i < ROW_EFF(m); i++)
    {
        int j = 0;
        for (; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                notZero += 1;
            }
        }
    }
    return notZero <= temp;
};
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
Matrix negation(Matrix m)
{
    return multiplyByConst(m, -1);
};
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegation(Matrix *m)
{
    return pMultiplyByConst(m, -1);
};
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinant(Matrix m)
{
    int a, b, index;
    float total = 1;
    float det = 1;
    int temp[ROW_EFF(m) + 1];
    int i = 0;
    int j = 0;
    for (; i < ROW_EFF(m); i++)
    {
        index = i;
        while (ELMT(m, index, i) == 0 && index < ROW_EFF(m))
        {
            index += 1;
        }
        if (index == ROW_EFF(m))
        {
            continue;
        }
        if (index != i)
        {
            j = 0;
            for (; j < COL_EFF(m); j++)
            {
                int tmp = ELMT(m, i, j);
                ELMT(m, i, j) = ELMT(m, index, j);
                ELMT(m, index, j) = tmp;
            }
            det *= (-1);
        }
        j = 0;
        for (; j < ROW_EFF(m); j++)
        {
            temp[j] = ELMT(m, i, j);
        }
        j = i + 1;
        for (; j < ROW_EFF(m); j++)
        {
            a = temp[i];
            b = ELMT(m, j, i);
            int k = 0;
            for (; k < ROW_EFF(m); k++)
            {
                ELMT(m, j, k) = a * ELMT(m, j, k) - b * temp[k];
            }
            total *= a;
        }
    }
    i = 0;
    for (; i < ROW_EFF(m); i++)
    {
        det *= getElmtDiagonal(m, i);
    }
    return det / total;
};
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
Matrix transpose(Matrix m)
{
    Matrix ret;
    createMatrix(COL_EFF(m), ROW_EFF(m), &ret);
    int i = 0;
    for (; i < ROW_EFF(ret); i++)
    {
        int j = 0;
        for (; j < COL_EFF(ret); j++)
        {
            ELMT(ret, j, i) = ELMT(m, i, j);
        }
    }
    return ret;
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTranspose(Matrix *m)
{
    copyMatrix(transpose(*m), m);
};
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

/* Operasi berbasis baris dan per kolom */

float AvgRow(Matrix M, IdxType i)
{
    float sum = 0;
    int j = 0;
    for (; j < COL_EFF(M); j++)
    {
        sum += ELMT(M, i, j);
    }
    float res = sum / ((float)COL_EFF(M));
    return res;
};

/* Menghasilkan rata-rata dari elemen pada baris ke-i */

/* Prekondisi: i adalah indeks baris efektif dari M */

float AvgCol(Matrix M, IdxType j)
{
    float sum = 0;
    int i = 0;
    for (; i < ROW_EFF(M); i++)
    {
        sum += ELMT(M, i, j);
    }
    float res = sum / ((float)ROW_EFF(M));
    return res;
};

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */

/* Prekondisi: j adalah indeks kolom efektif dari M */

void MinMaxRow(Matrix M, IdxType i, ElType *max, ElType *min)
{
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);
    int j = 0;
    for (; j < COL_EFF(M); j++)
    {
        if (ELMT(M, i, j) > *max)
        {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min)
        {
            *min = ELMT(M, i, j);
        }
    }
};

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada baris i dari M

min berisi elemen minimum pada baris i dari M */

void MinMaxCol(Matrix M, IdxType j, ElType *max, ElType *min)
{
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);
    int i = 0;
    for (; i < ROW_EFF(M); i++)
    {
        if (ELMT(M, i, j) > *max)
        {
            *max = ELMT(M, i, j);
        }
        if (ELMT(M, i, j) < *min)
        {
            *min = ELMT(M, i, j);
        }
    }
};

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada kolom j dari M

min berisi elemen minimum pada kolom j dari M */

int CountNumRow(Matrix M, IdxType i, ElType X)
{
    int sum = 0;
    int j = 0;
    for (; j < COL_EFF(M); j++)
    {
        if (ELMT(M, i, j) == X)
        {
            sum++;
        }
    }
    return sum;
};

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */

int CountNumCol(Matrix M, IdxType j, ElType X)
{
    int sum = 0;
    int i = 0;
    for (; i < ROW_EFF(M); i++)
    {
        if (ELMT(M, i, j) == X)
        {
            sum++;
        }
    }





    
    return sum;
};

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */

void RotateMat(Matrix *m)
{
    Matrix ret;
    copyMatrix(*m, &ret);
    int startRow = 0;
    int size = ROW_EFF(*m);
    for (; size > 1; startRow++)
    {
        int startCol = startRow;
        int i = startRow;
        for (; i < startRow + size; i++)
        {
            int j = startCol;
            for (; j < startCol + size; j++)
            {
                if (j == startCol && i != startRow + size - 1)
                {
                    ELMT(ret, i, j) = ELMT(*m, i + 1, j);
                }
                else if (j == startCol + size - 1 && i != startRow)
                {
                    ELMT(ret, i, j) = ELMT(*m, i - 1, j);
                }
                else if (i == startRow && j != startCol)
                {
                    ELMT(ret, i, j) = ELMT(*m, i, j - 1);
                }
                else if (i == startRow + size - 1 && j != startCol + size - 1)
                {
                    ELMT(ret, i, j) = ELMT(*m, i, j + 1);
                }
            }
        }
        size -= 2;
    }
    copyMatrix(ret, m);
};

/* I.S. m terdefinisi dan IsSquare(m) */

/* F.S. m "di-rotasi" searah jarum jam */
void RotateMat(Matrix *m1){
/* I.S. m terdefinisi dan IsSquare(m) */
 // F.S. m "di-rotasi" searah jarum jam
 //   untuk semua "lapisan" elemen mulai dari yang terluar
 //   Contoh matrix 3x3 sebelum dirotasi:
 //   1 2 3
 //   4 5 6
 //   7 8 9
 //   Contoh matrix 3x3 setelah dirotasi:
 //   4 1 2
 //   7 5 3
 //   8 9 6
 //   Contoh matrix 4x4 sebelum dirotasi:
 //   1 2 3 4
 //   5 6 7 8
 //   9 10 11 12
 //   13 14 15 16

 //   Contoh matrix 4x4 setelah dirotasi:
 //   5 1 2 3
 //   9 10 6 4
 //   13 11 7 8
 //   14 15 16 12
  int i,j;
  Matrix m;
  copyMatrix(*m1,&m);
  if (countElmt(m)==4){
    for (int i = 0; i < ROW_EFF(m);i++){
      for (int j = 0; j < COL_EFF(m);j++){
        if (i==0 && j!=COL_EFF(m)-1){
          ELMT(*m1, i, j+1) = ELMT(m, i, j);
        }else if (i==ROW_EFF(m)-1 && j!=0){
          ELMT(*m1, i, j-1) = ELMT(m, i, j);
        }else if (j==0 && i!=ROW_EFF(m)-1){
          ELMT(*m1, i+1, j) = ELMT(m, i, j);
        }
        else if (j==COL_EFF(m) && i!=0){
          ELMT(*m1, i-1, j) = ELMT(m, i, j);
        }
      }
    }
  }
}