/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
#define tiii std::tuple<long long, long long, long long>
const long long INF = 100 * 1'000 * 20'000 + 500LL;
long long N, M, costs[102], prv[102];
std::vector<tiii> edges;
std::vector<bool> visited;
std::vector<int> graph[102];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(&costs[0], 102, INF);
    std::cin >> N >> M;
    visited.resize(N+1, false);
    for(int m = 0; m < M; m++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, -w});
        graph[v].push_back(u);
    }
    std::queue<int> q;
    visited[N] = true;
    q.push(N);
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
            if(visited[iter]) continue;
            q.push(iter);
            visited[iter] = true;
        }
    }
    
    bool cycle = false;
    costs[1] = 0;
    for(int i = 0; i < N; i++)
    {
        for(const auto& iter : edges)
        {
            long long u = std::get<0>(iter);
            long long v = std::get<1>(iter);
            long long w = std::get<2>(iter);
            if(costs[u] != INF && costs[u] + w < costs[v])
            {
                if(i >= N-1 && visited[v])
                {
                    cycle = true;
                    continue;
                }
                costs[v] = costs[u] + w;
                prv[v] = u;
            }
        }
    }
    if(cycle)
    {
        std::cout << -1;
        return 0;
    }
    std::stack<int> st;
    int cur = N;
    while(cur)
    {
        st.push(cur);
        cur = prv[cur];
    }
    while(st.size())
    {
        std::cout << st.top() << ' ';
        st.pop();
    }
    
    return 0;
}
