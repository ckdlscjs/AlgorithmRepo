/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int T;
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        long long N, arr[1'000'005], maxv = 0, res = 0;
        std::cin >> N;
        for(int n = 0; n < N; n++) std::cin >> arr[n];
        for(int n = N-1; n >= 0; n--)
        {
            if(arr[n] < maxv)
            {
                res += maxv-arr[n];
            }
            maxv = std::max(maxv, arr[n]);
        }
        std::cout << res << '\n';
    }
    return 0;
}
