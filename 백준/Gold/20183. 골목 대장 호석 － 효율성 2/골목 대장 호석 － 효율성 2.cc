/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define pll std::pair<long long, long long>
const long long INF = (long long)1e14 + 100LL;
int N, M, A, B;
long long costs[100'005], C, lo, hi = (long long)1e9 + 1LL;
std::vector<pll> graph[100'005];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M >> A >> B >> C;
    for(int m = 0; m < M; m++) 
    {
        long long u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    while(lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2;
        std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;
        std::fill_n(costs, 100'005, INF);
        costs[A] = 0;
        pq.push({0, A});
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            if(cur.second == B) break;
            if(cur.first > costs[cur.second]) continue;
            for(const auto& iter : graph[cur.second])
            {
                if(iter.second > mid) continue;
                if(costs[cur.second] + iter.second >= costs[iter.first] || costs[cur.second] + iter.second > C) continue;
                costs[iter.first] = costs[cur.second] + iter.second;
                pq.push({costs[iter.first], iter.first});
            }
        }
        if(costs[B] > C) lo = mid;
        else hi = mid;
    }
    if(hi >= (long long)1e9 + 1LL) std::cout << -1;
    else std::cout << hi;
	return 0;
}

