/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define pii std::pair<int, int>
const int INF = 100'000 * 1'005; 
int N, M, costs[1'005], prv[1'005];
std::vector<pii> graph[1'005];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    std::fill_n(&costs[0], 1'005, INF);
    for(int m = 0; m < M; m++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    int u, v;
    std::cin >> u >> v;
    costs[u] = 0;
    pq.push({costs[u], u});
    while(pq.size())
    {
        auto cur = pq.top();
        pq.pop();
        if(cur.first > costs[cur.second]) continue;
        for(const auto& iter : graph[cur.second])
        {
            if(iter.second + costs[cur.second] >= costs[iter.first]) continue;
            costs[iter.first] = costs[cur.second] + iter.second;
            prv[iter.first] = cur.second;
            pq.push({costs[iter.first], iter.first});
        }
    }
    std::cout << costs[v] << '\n';
    std::stack<int> paths;
    paths.push(v);
    while(prv[v])
    {
        paths.push(prv[v]);
        v = prv[v];
    }
    std::cout << paths.size() << '\n';
    while(paths.size())
    {
        std::cout << paths.top() << ' ';
        paths.pop();
    }
	return 0;
}

