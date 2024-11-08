//https://school.programmers.co.kr/learn/courses/30/lessons/72413
#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
std::vector<std::pair<int, int>> graph[205];
int costs[205][205];
void Dijkstra(int s)
{
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    costs[s][s] = 0;
    pq.push({0, s});
    while(pq.size())
    {
        int u = pq.top().second;
        pq.pop();
        for(const auto& iter : graph[u])
        {
            int v = iter.first;
            int w = iter.second;
            if(costs[s][u] == INF || w == INF || costs[s][v] <= costs[s][u] + w) continue;
            costs[s][v] = costs[s][u] + w;
            pq.push({costs[s][v], v});
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    for(const auto& iter : fares)
    {
        graph[iter[0]].push_back({iter[1], iter[2]});
        graph[iter[1]].push_back({iter[0], iter[2]});
    }
    std::fill_n(&costs[0][0], 205*205, INF);
    Dijkstra(s);
    Dijkstra(a);
    Dijkstra(b);
    int answer = INT_MAX;
    for(int i = 1; i <= n; i++)
        if(costs[s][i] != INF && costs[a][i] != INF && costs[b][i] != INF)
            answer = std::min(answer, costs[s][i] + costs[a][i] + costs[b][i]);
    return answer;
}