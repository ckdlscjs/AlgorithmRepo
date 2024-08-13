#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
const int INF = 987654321;
std::vector<std::pair<int, int>> graph[MaxN];
int solution(int N, vector<vector<int>> road, int K) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    for(const auto& iter : road)
    {
        graph[iter[0]].push_back({iter[1], iter[2]});
        graph[iter[1]].push_back({iter[0], iter[2]});
    }
    int costs[MaxN];
    std::fill(costs, costs+MaxN, INF);
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;
    costs[1] = 0;
    pq.push({0, 1});
    while(pq.size())
    {
        int sum_cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(sum_cost > costs[idx])
            continue;
        for(int i = 0; i < graph[idx].size(); i++)
        {
            int cost = graph[idx][i].second;
            int j = graph[idx][i].first;
            if(cost+sum_cost < costs[j])
            {
                costs[j] = cost + sum_cost;
                pq.push({costs[j], j});
            }
        }
    }
    int answer = 0;
    for(int i = 1; i <= N; i++)
        if(costs[i] <= K)
            answer++;
    return answer;
}