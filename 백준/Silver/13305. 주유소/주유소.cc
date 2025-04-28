#include <bits/stdc++.h>
using namespace std;
int N, dist[100'005], fee, minFee = 1'000'000'005, res;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N-1; n++) std::cin >> dist[n];
    for(int n = 0; n < N; n++)
    {
        std::cin >> fee;
        minFee = std::min(minFee, fee);
        res += dist[n] * minFee;
    }
    std::cout << res;
    return 0;
}
