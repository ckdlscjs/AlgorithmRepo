/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 10'005 * 400;
int V, E, costs[402][402];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::fill_n(&costs[0][0], 402*402, INF);
    std::cin >> V >> E;
    for(int i = 1; i <= V; i++) costs[i][i] = 0;
    for(int e = 0; e < E; e++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        costs[a][b] = c;
    }
    
    for(int i = 1; i <= V; i++)
    {
        for(int j = i + 1; j <= V; j++)
        {
            for(int k = i; k <= V; k++)
            {
                if(costs[i][k] == INF || costs[k][j] == INF) continue;
                costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }
    
    int result = INF;
    for(int i = 1; i <= V; i++)
    {
        for(int j = i + 1; j <= V; j++)
        {
            result = std::min(result, costs[i][j] + costs[j][i]);
        }
    }
    std::cout << (result >= INF ? -1 : result);
    return 0;
}
