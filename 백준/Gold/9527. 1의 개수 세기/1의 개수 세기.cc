/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
long long A, B, dp[65];
long long Count(long long num)
{
    if(num <= 0) return 0;
    int i = 62;
    while(num < (1LL << i))
        i--;
    long long cnt = dp[i] + (num - (1LL << i) + 1LL);
    cnt += Count(num - (1LL << i));
    return cnt;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    dp[1] = 1;
    for(int i = 2; i <= 62; i++) dp[i] = dp[i-1]*2 + (1LL << (i-1));
    std::cin >> A >> B;
    std::cout << Count(B) - Count(A-1);
	return 0;
}

