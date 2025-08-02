/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
long long Mod = (long long)1e9;
long long DP[101][10][1<<10];
long long N, res;
long long Check(int n, int cur, int mask)
{
    if(n < 1) return mask == 1023;
    long long& ret = DP[n][cur][mask];
    if(ret != -1) return ret;
    ret = 0;
    if(cur > 0) ret = (ret + Check(n-1, cur-1, mask | 1<<(cur-1))) % Mod;
    if(cur < 9) ret = (ret + Check(n-1, cur+1, mask | 1<<(cur+1))) % Mod;
    return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::fill_n(&DP[0][0][0], 101*10*(1<<10), -1);
    std::cin >> N;
    for(int i = 1; i <= 9; i++)
        res = (res + Check(N-1, i, 1 << i)) % Mod;
    std::cout << res;
    
	return 0;
}

