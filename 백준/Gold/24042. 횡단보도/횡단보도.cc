/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define ll long long
#define pll std::pair<ll, ll>
ll N, M, costs[100'005];
const ll INF = 100'000LL * 700'000LL + 100LL;
std::vector<pll> graph[100'005];
std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(costs, 100'005, INF);
    std::cin >> N >> M;
    for(int m = 1; m <= M; m++)
    {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back({v, m});
        graph[v].push_back({u, m});
    }
    costs[1] = 0;
    pq.push({costs[1], 1});
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        ll u = cur.second;
        ll cc = cur.first;
        //std::cout << u << ' ' << cc << '\n';
        if(cc > costs[u]) continue;
        for(const auto& iter : graph[u])
        {
            ll v = iter.first;
            ll w = iter.second;
            if(cc > w)
                w = (cc / M) * M + w;
            if(cc > w)
                w += M;
            if(w > costs[v]) continue;
            costs[v] = w;
            pq.push({costs[v], v});
        }
    }
    std::cout << costs[N];
    return 0;
}
