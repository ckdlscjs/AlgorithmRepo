/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 987654321;
int N, costs[16][16], dp[16][1<<16];
int Check(int cur, int mask)
{
    if(mask == (1 << N) - 1)
        return costs[cur][0] == 0 ? INF : costs[cur][0];
    int& ret = dp[cur][mask];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < N; i++)
    {
        if(cur == i) continue;
        if(!costs[cur][i]) continue;
        if(mask & 1 << i) continue;
        ret = std::min(ret, Check(i, mask | 1 << i) + costs[cur][i]);
    }
    return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    std::cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> costs[i][j];
    std::cout << Check(0, 1 << 0);
    
	return 0;
}

