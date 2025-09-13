/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 252;
int V, E, costs[252][252], K;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(&costs[0][0], 252*252, INF);
    std::cin >> V >> E;
    for(int i = 1; i <= V; i++) costs[i][i] = 0;
    for(int e = 0; e < E; e++)
    {
        int u, v, b;
        std::cin >> u >> v >> b;
        if(b == 0)
        {
            costs[u][v] = 0;
            costs[v][u] = std::min(costs[v][u], 1);
        }
        else
        {
            costs[u][v] = costs[v][u] = 0;
        }
    }
    
    for(int k = 1; k <= V; k++)
    {
        for(int i = 1; i <= V; i++)
        {
            for(int j = 1; j <= V; j++)
            {
                if(costs[i][k] >= INF || costs[k][j] >= INF) continue;
                costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
            } 
        }
    }
    std::cin >> K;
    for(int k = 0; k < K; k++)
    {
        int s, e;
        std::cin >> s >> e;
        std::cout << costs[s][e] << '\n';
    }
    return 0;
}
