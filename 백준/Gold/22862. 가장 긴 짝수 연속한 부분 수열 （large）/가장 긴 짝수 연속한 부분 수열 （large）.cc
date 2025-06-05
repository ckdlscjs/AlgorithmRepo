/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, K, S[1'000'005], res;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 0; n < N; n++) std::cin >> S[n];
    int l = 0, r = 0, oddCnt = 0;
    while(l <= r && l < N)
    {
        while(r < N)
        {
            if(S[r] % 2)
            {
                if(oddCnt >= K) break;
                oddCnt++;
            }
            r++;
        }
        res = std::max(res, r-l-oddCnt);
        //std::cout << l << ' ' << r << '\n';
        if(S[l++] % 2) oddCnt--;
    }
    std::cout << res;
    return 0;
}
