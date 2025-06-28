/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, K, C[105], DP[10'005];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 0; n < N; n++) std::cin >> C[n];
    DP[0] = 1;
    for(int n = 0; n < N; n++)
    {
        if(C[n] > K) continue;
        for(int k = C[n]; k <= K; k++) 
            DP[k] += DP[k-C[n]];
    }
    std::cout << DP[K];
	return 0;
}
