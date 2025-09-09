/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int maxN = 1'000'000;
int N, K, DP[1'500'005];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> K;
    std::fill_n(DP, 1'500'005, 1'000'005);
    DP[0] = 0;
    for(int i = 0; i <= maxN; i++)
    {
        DP[i+1] = std::min(DP[i+1], DP[i] + 1);
        DP[i+i/2] = std::min(DP[i+i/2], DP[i] + 1);
    }
    if(DP[N] <= K) std::cout << "minigimbob";
    else std::cout << "water";
    return 0;
}
