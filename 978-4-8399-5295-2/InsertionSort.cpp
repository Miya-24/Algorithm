/*
  安定的ソート(Stable Sort) : 要素の順が変わらない
  ID1  50      ID2  20
  ID2  20  ->  ID3  20
  ID3  20      ID1  50
  -------------------------------------------
  1 <= N <= 100
  0 <= A <= 1,000
*/

#include <cstdio>

//ソートの結果を出力
void OutPut(int A[], int Num)
{
    for (int NumCnt = 0; NumCnt < Num; NumCnt++) {
        if (NumCnt > 0) printf(" ");
        printf("%d", A[NumCnt]);
    }
}

//挿入ソート
void InsertSort(int A[], int Num)
{
    int i, j, val;
    for (i = 1; i < Num; i++) {
        val = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > val) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = val;
    }
    OutPut(A, Num);
}

//メイン
int main()
{
    int Num, NumCnt;
    int A[100];
    //テスト
    //int Num = 5, NumCnt;
    //int A[100] = {3, 1, 5, 10, 2};

    scanf("%d", &Num);
    for (NumCnt = 0; NumCnt < Num; NumCnt++) scanf("%d", &A[NumCnt]);

    InsertSort(A, Num);
}