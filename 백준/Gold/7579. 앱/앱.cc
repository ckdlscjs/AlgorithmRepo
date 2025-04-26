#include <bits/stdc++.h>
using namespace std;
int N, M, costs[10'005], m[10'005], c[10'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N; n++) std::cin >> m[n];
    for(int n = 0; n < N; n++) std::cin >> c[n];
    for(int n = 0; n < N; n++)
    {
        for(int cost = 10'000; cost >= 0; cost--)
        {
            if(cost - c[n] < 0) continue;
            costs[cost] = std::max(costs[cost], costs[cost-c[n]] + m[n]);
        }
    }
    for(int cost = 0; cost <= 10'000; cost++)
        if(costs[cost] >= M)
        {
            std::cout << cost;
            return 0;
        }
    return 0;
}