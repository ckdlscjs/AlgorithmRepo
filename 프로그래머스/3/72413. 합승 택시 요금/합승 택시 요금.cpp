#include <bits/stdc++.h>

using namespace std;
const int INF = 1e5*1e5+5;
int costs[202][202];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    std::fill_n(&costs[0][0], 202*202, INF);
    for(int i = 1; i <= n; i++) costs[i][i] = 0;
    for(const auto& iter : fares)
    {
        costs[iter[0]][iter[1]] = iter[2];
        costs[iter[1]][iter[0]] = iter[2];
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(costs[i][k] != INF && costs[k][j] != INF)
                    costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }
    std::cout << costs[s][a] << ' ' << costs[s][b] <<'\n';
    int answer = INF;
    for(int i = 1; i <= n; i++)
        answer = std::min(answer, costs[s][i] + costs[i][a] + costs[i][b]);
    
    return answer;
}