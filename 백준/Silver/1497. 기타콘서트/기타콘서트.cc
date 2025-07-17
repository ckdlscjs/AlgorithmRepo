/*
1.접근방식:

2.시간복잡도:

*/

#include <bits/stdc++.h>
int N, M, mincnt = 11;
long long arr[12], maxmask;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++)
    {
        std::string str;
        std::cin >> str >> str;
        for(int i = 0; i < str.size(); i++)
            arr[n] |= (str[i] == 'Y' ? (1LL << i) : 0);
        maxmask |= arr[n];
    }
    for(int mask = 1; mask < (1LL<<N); mask++)
    {
        int curcnt = 0;
        long long curmask = 0;
        for(int idx = 0; idx < N; idx++)
        {
            if(mask & (1LL << idx))
            {
                curcnt++;
                curmask |= arr[idx];
            }
        }
        if(maxmask != 0 && curmask == maxmask)
            mincnt = std::min(curcnt, mincnt);
    }
    std::cout << (mincnt > 10 ? -1 : mincnt);
	return 0;
}

