/*
  1 <= Num <= 100
  0 <= A <= 100
*/

#include <iostream>
#include <algorithm>

//ソートの結果を出力
void OutPut(int A[], int Num)
{
    for (int NumCnt = 0; NumCnt < Num; NumCnt++) {
        if (NumCnt > 0) printf(" ");
        printf("%d", A[NumCnt]);
    }
}

//バブルソート
void BubbleSort(int A[], int Num)
{
    //i : 未ソートの先頭
    //j : Numからiの要素を比較(jはNum-1 から i+1 まで)
    bool flag = 1;
    for (int i = 0; flag; i++) {
        flag = 0;
        for (int j = Num - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
                flag = 1;
            }
        }
    }
    OutPut(A, Num);
}

//メイン
int main()
{
    int A[100], Num;
    std::cin >> Num;
    for (int i = 0; i < Num; i++) std::cin >> A[i];

    BubbleSort(A, Num);
    return 0;
}