//https://school.programmers.co.kr/learn/courses/30/lessons/68937
#include <bits/stdc++.h>
using namespace std;
std::vector<int> tree[250'005];
std::vector<std::pair<int, int>> bfs(int idx, int n)
{
    int maxdist = 0;
    int dist[250'005];
    std::memset(dist, 0, sizeof(dist));
    std::queue<int> q;
    dist[idx] = 1;
    q.push(idx);
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(const auto& iter : tree[cur])
        {
            if(dist[iter])
                continue;
            dist[iter] = dist[cur] + 1;
            maxdist = std::max(maxdist, dist[iter]);
            q.push(iter);
        }
    }
    std::vector<std::pair<int, int>> ret;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == maxdist)
            ret.push_back({dist[i] - 1, i});
    }
    return ret;
}
int solution(int n, vector<vector<int>> edges) 
{
    for(const auto& iter : edges)
    {
        tree[iter[0]].push_back(iter[1]);
        tree[iter[1]].push_back(iter[0]);
    }
    std::vector<std::pair<int, int>> ret1 = bfs(1, n);
    std::vector<std::pair<int, int>> ret2 = bfs(ret1[0].second, n);
    if(ret2.size() > 1)
        return ret2[0].first;
    std::vector<std::pair<int, int>> ret3 = bfs(ret2[0].second, n);
    return ret3.size() <= 1 ? ret3[0].first-1 : ret3[0].first;
}