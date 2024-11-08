//https://school.programmers.co.kr/learn/courses/30/lessons/72413
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int costs[205][205];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    std::fill_n(&costs[0][0], 205*205, INF);
    for(int i = 1; i <= n; i++) costs[i][i] = 0;
    for(const auto& iter : fares)
    {
        costs[iter[0]][iter[1]] = iter[2];
        costs[iter[1]][iter[0]] = iter[2];
    }
    for(int m = 1; m <= n; m++)
    {
        for(int u = 1; u <= n; u++)
        {
            for(int v = 1; v <= n; v++)
            {
                if(costs[u][m] == INF || costs[m][v] == INF) continue;
                costs[u][v] = std::min(costs[u][v], costs[u][m] + costs[m][v]);
            }
        }
    }
   
    int answer = INT_MAX;
    for(int i = 1; i <= n; i++)
        if(costs[s][i] != INF && costs[a][i] != INF && costs[b][i] != INF)
            answer = std::min(answer, costs[s][i] + costs[i][a] + costs[i][b]);
    return answer;
}