/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
const int INF = 203*203*1000;
int N, M, costs[202][202], prv[202][202];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> M;
    std::fill_n(&costs[0][0], 202*202, INF);
    for(int i = 1; i <= N; i++) costs[i][i] = 0;
    for(int m = 0; m < M; m++)
    {
        int u, v, c;
        std::cin >> u >> v >> c;
        if(c < costs[u][v])
        {
            costs[u][v] = c;
            prv[u][v] = v;
        }
        if(c < costs[v][u])
        {
            costs[v][u] = c;
            prv[v][u] = u;
        }
    }
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
           for(int j = 1; j <= N; j++)
            {
                if(costs[i][k] + costs[k][j] < costs[i][j])
                {
                    costs[i][j] = costs[i][k] + costs[k][j];
                    prv[i][j] = prv[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(i == j) std::cout << '-' << ' ';
            else std::cout << prv[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
