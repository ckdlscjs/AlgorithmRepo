#include <bits/stdc++.h>
using namespace std;
const int INF = 10'000 * 10'000 + 5;
std::vector<std::pair<int, int>> graph[52];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
int dist[52];
int solution(int N, vector<vector<int>> road, int K) 
{
    std::fill_n(&dist[0], 52, INF);
    for(const auto& iter : road)
    {
        graph[iter[0]].push_back({iter[1], iter[2]});
        graph[iter[1]].push_back({iter[0], iter[2]});
    }
    dist[1] = 0;
    pq.push({0, 1});
    while(pq.size())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(dist[cur] < cost) continue;
        for(const auto& iter : graph[cur])
        {
            if(dist[cur] + iter.second < dist[iter.first])
            {
                dist[iter.first] = dist[cur] + iter.second;
                pq.push({dist[iter.first], iter.first});
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= N; i++)
        if(dist[i] <= K)
            answer++;
    return answer;
}