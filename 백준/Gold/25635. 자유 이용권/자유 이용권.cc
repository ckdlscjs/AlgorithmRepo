#include <bits/stdc++.h>
using namespace std;
long long N, val, res, sum, maxN;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> val;
        sum += val;
        maxN = std::max(maxN, val);
    }
    sum -= maxN;
    if(sum > maxN) std::cout << sum + maxN;
    else if(sum < maxN) std::cout << sum*2 + 1;
    else cout << maxN * 2;
    return 0;
}