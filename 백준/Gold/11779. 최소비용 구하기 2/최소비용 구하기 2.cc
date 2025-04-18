#include <bits/stdc++.h>
using namespace std;
#define pll std::pair<long long, long long>
const long long INF = (long long)100'000*100'000+5;
long long N, M, u, v, w, costs[1'005], s, e, prv[1'005];
std::vector<int> route;
std::vector<pll> graph[1'005];
std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    std::cin >> s >> e;
    std::fill_n(&costs[0], 1'005, INF);
    costs[s] = 0;
    pq.push({0, s});
    while(pq.size())
    {
        pll cur = pq.top();
        pq.pop();
        if(costs[cur.second] < cur.first) continue;
        for(const auto& iter : graph[cur.second])
        {
            v = iter.first;
            w = iter.second;
            if(costs[cur.second] + w < costs[v])
            {
                prv[v] = cur.second;
                costs[v] = costs[cur.second] + w;
                pq.push({costs[v], v});
            }
        }
    }
    std::cout << costs[e] << '\n';
    route.push_back(e);
    while(prv[e])
    {
        route.push_back(prv[e]);
        e = prv[e];
    }
    std::cout << route.size() << '\n';
    for(int i = route.size()-1; i >= 0; i--)
        std::cout << route[i] << ' ';
    return 0;
}
