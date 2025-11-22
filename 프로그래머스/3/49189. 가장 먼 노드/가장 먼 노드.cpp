#include <bits/stdc++.h>
using namespace std;
std::vector<int> dist;
std::vector<std::vector<int>> graph;
std::queue<int> q;
int solution(int n, vector<vector<int>> edge) 
{
    dist.resize(n+1, 0);
    graph.resize(n+1, std::vector<int>());
    for(const auto& iter : edge)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
    dist[1] = 1;
    q.push(1);
    int maxdist = 0;
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        maxdist = std::max(maxdist, dist[cur]);
        for(const auto& iter : graph[cur])
        {
            if(dist[iter]) continue;
            q.push(iter);
            dist[iter] = dist[cur] + 1;
        }
    }
    int answer = 0;
    for(const auto& iter : dist)
        if(iter == maxdist)
            answer++;
    
    return answer;
}