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
    if(maxN == 1)
    {
        std::cout << "Happy";
        return 0;
    }
    if(sum >= maxN) std::cout << "Happy";
    else cout << "Unhappy";
    return 0;
}