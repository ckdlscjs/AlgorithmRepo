#include <bits/stdc++.h>

using namespace std;
const int MaxN = 205;
const int INF = 100000000;
std::vector<std::pair<int, int>> graph[MaxN];
void dijkstra(int* costs, int start)
{
    std::fill(costs, costs+MaxN, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::less<std::pair<int, int>>> pq;
    costs[start] = 0;
    pq.push({0, start});
    while(pq.size())
    {
        int sum_cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();
        if(costs[from] < sum_cost)
            continue;
        for(const auto& iter : graph[from])
        {
            int weight = iter.second;
            int to = iter.first;
            if(sum_cost + weight < costs[to])
            {
                costs[to] = sum_cost + weight;
                pq.push({costs[to], to});
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    for(const auto& iter : fares)
    {
        graph[iter[0]].push_back({iter[1],iter[2]});
        graph[iter[1]].push_back({iter[0],iter[2]});
    }
    int cost_s[MaxN];
    dijkstra(cost_s, s);
    int cost_a[MaxN];
    dijkstra(cost_a, a);
    int cost_b[MaxN];
    dijkstra(cost_b, b);
    long long int sum = 987654321;
    for(int i = 1; i <= n; i++)
        sum = std::min((long long int)(cost_s[i] + cost_a[i] + cost_b[i]), sum);
    return sum;
}