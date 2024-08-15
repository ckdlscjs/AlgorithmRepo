#include <bits/stdc++.h>
using namespace std;
const int MaxN = 20005;
int solution(int n, vector<vector<int>> edge) 
{
    int dist[MaxN];
    std::vector<int> graph[MaxN];
    for(const auto& iter : edge)
    {
        graph[iter[0]].push_back(iter[1]);
        graph[iter[1]].push_back(iter[0]);
    }
        
    std::queue<int> q;
    q.push(1);
    dist[1] = 1;
    int dist_max = 0;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        dist_max = std::max(dist_max, dist[cur]);
        for(const auto& iter : graph[cur])
        {
            if(dist[iter])
                continue;
            dist[iter] = dist[cur]+1;
            q.push(iter);
        }
    }
    int answer = 0;
    for(int i = 1; i <= n; i++)
        if(dist_max == dist[i])
            answer++;
    
    return answer;
}