/*
  カードのソート
  H:ハート D:ダイヤ C:クラブ S:スペード
  value:1～9
  → 1 <= Num <= 36
*/

#include <iostream>

struct Card {
    char Suit;
    int Value;
};

//ソートの結果を出力
void OutPut(Card A[], int Num)
{
    for (int NumCnt = 0; NumCnt < Num; NumCnt++) {
        if (NumCnt > 0) std::cout << " ";
        std::cout << A[NumCnt].Suit << A[NumCnt].Value;
    }
    std::cout << std::endl;
}

//バブルソート(Stable)
void Bubble(Card A[], int Num)
{
    for (int i = 0; i < Num; i++) {
        for (int j = Num - 1; j  >= i; j--) {
            if (A[j].Value < A[j-1].Value) {
                Card tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}

//選択ソート(Unstable)
void Selection(Card A[], int Num)
{
    for (int i = 0; i < Num; i++) {
        int min = i;
        for (int j = i; j < Num; j++) {
            if (A[j].Value < A[min].Value) min = j;
        }
        Card tmp = A[i];
        A[i] = A[min];
        A[min] = tmp;
    }
}

//バブルソートと選択ソートを比較
bool isStable(Card B[], Card S[], int Num)
{
    for (int i = 0; i < Num; i++) {
        if (B[i].Suit != S[i].Suit) return false;
    }
    return true;
}

//メイン
int main()
{
    Card C_B[36];   //バブルソート用
    Card C_S[36];   //選択ソート用
    int Num;
    std::cin >> Num;
    for (int i = 0; i < Num; i++) {
        std::cin >> C_B[i].Suit >> C_B[i].Value;
        C_S[i] = C_B[i];
    }

    Bubble(C_B, Num);
    Selection(C_S, Num);

    OutPut(C_B, Num);
    std::cout << "Bubble Sort is Stable" << std::endl;

    OutPut(C_S, Num);
    std::cout << "Selection Sort is ";
    if (isStable(C_B, C_S, Num)) {
        std::cout << "Stable" << std::endl;
    } else {
        std::cout << "Not Stable" << std::endl;
    }
    return 0;
}