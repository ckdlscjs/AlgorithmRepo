#include <bits/stdc++.h>
bool notPrime[1'000'005];
int M, N;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    notPrime[0] = notPrime[1] = true;
    for(int i = 2; i <= std::sqrt(1'000'000); i++)
    {
        if(notPrime[i]) continue;
        for(int j = 2; i*j <= 1'000'000; j++) notPrime[i*j] = true;
    }
    std::cin >> M >> N;
    for(int i = M; i <= N; i++)
    {
        if(notPrime[i]) continue;
        std::cout << i << '\n';
    }
	return 0;
}