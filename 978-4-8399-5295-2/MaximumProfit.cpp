/*
  時刻tにおける価格Rt(t=1,2,3,…,n-1,n)
  価格差Rj - Ri(ただしj > i)の最大値を求める。
  2 <= n <= 200,000
  1 <= Rn <= 1,000,000,000
*/

#include <iostream>
#include <algorithm>

const int MAX = 200000;

int main()
{
    int n, R[MAX];
    std::cin >> n;
    for (int t = 0; t < n; t++) std::cin >> R[t];

    int MaxProfit = -999999999;
    int MinVal = R[0];

    for (int t = 1; t < n; t++) {
        MaxProfit = std::max(MaxProfit, R[t] - MinVal);
        MinVal = std::min(MinVal, R[t]);
    }
    std::cout << MaxProfit << std::endl;

    return 0;
}