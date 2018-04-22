/*
  1 <= Num <= 100
  0 <= A <= 100
*/

#include <cstdio>

//ソートの結果を出力
void OutPut(int A[], int Num)
{
    for (int NumCnt = 0; NumCnt < Num; NumCnt++) {
        if (NumCnt > 0) printf(" ");
        printf("%d", A[NumCnt]);
    }
    printf("\n");
    
}

//選択ソート
void SelectionSort(int A[], int Num)
{
    int min = 0;    //iからN-1の要素の最小値
    int tmp = 0;
    
    //i : 未ソートの先頭
    for (int i = 0; i < Num - 1; i++) {
        min = i;
        //j : 最小値minを探索
        for (int j = i; j < Num; j++) {
            if (A[j] < A[min])
                min = j;
        }
        tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
    OutPut(A, Num);
}

//メイン
int main()
{
    int Num;
    int A[100];

    scanf("%d", &Num);
    for (int i = 0; i < Num; i++) scanf("%d", &A[i]);

    SelectionSort(A, Num);
    return 0;
}