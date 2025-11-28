#include <bits/stdc++.h>
using namespace std;
const int INF = 100'000 + 5;
std::vector<std::vector<int>> graph;
std::vector<int> cost;
std::queue<std::pair<int, int>> q;
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) 
{
    cost.resize(n+1, INF);
    graph.resize(n+1, std::vector<int>());
    for(const auto& iter : roads)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
    cost[dest] = 0;
    q.push({cost[dest], dest});
    while(q.size())
    {
        int c = q.front().first;
        int u = q.front().second;
        q.pop();
        if(c > cost[u]) continue;
        for(const auto& iter : graph[u])
        {
            if(cost[u] + 1 >= cost[iter]) continue;
            cost[iter] = cost[u] + 1;
            q.push({cost[iter], iter});
        }
    }
    std::vector<int> answer;
    for(const auto& iter : sources)
        answer.push_back(cost[iter] >= INF ? -1 : cost[iter]);
    return answer;
}