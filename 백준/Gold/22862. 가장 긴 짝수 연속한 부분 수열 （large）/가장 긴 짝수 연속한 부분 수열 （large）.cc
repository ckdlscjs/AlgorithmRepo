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
    int e = 0, oddcnt = 0;
    for(int s = 0; s < N; s++)
    {
        while(e < N)
        {
            if(S[e] % 2)
            {
                if(oddcnt >= K) break;
                oddcnt++;
            }
            e++;
        }
        res = std::max(res, e-s-oddcnt);
        //std::cout << l << ' ' << r << '\n';
        if(S[s] % 2)
            oddcnt--;
    }
    std::cout << res;
    return 0;
}
