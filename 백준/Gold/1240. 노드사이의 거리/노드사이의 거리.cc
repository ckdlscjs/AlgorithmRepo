/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, cost[1'005][1'005], depth[1'005];
std::vector<int> graph[1'005];
void DFS(int d, int cur)
{
    depth[cur] = d;
    for(const auto& iter : graph[cur])
    {
        if(depth[iter]) continue;
        DFS(d+1, iter);
    }
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int n = 0; n < N-1; n++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1, 1);
    for(int m = 0; m < M; m++)
    {
        int u, v, dist = 0;
        std::cin >> u >> v;
        while(u != v)
        {
            if(depth[u] > depth[v])
            {
                for(const auto& iter : graph[u])
                {
                    if(depth[iter] > depth[u]) continue;
                    dist += cost[iter][u];
                    u = iter;
                    break;
                }
            }
            else
            {
                for(const auto& iter : graph[v])
                {
                    if(depth[iter] > depth[v]) continue;
                    dist += cost[iter][v];
                    v = iter;
                    break;
                }
            }
        }
        std::cout << dist << '\n';
    }
	return 0;
}

