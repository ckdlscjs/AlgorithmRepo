#include <bits/stdc++.h>
using namespace std;
const int MaxN = 250005;
std::vector<int> tree[MaxN];
std::vector<std::pair<int,int>> bfs(int idx, int n)
{
    int dist[MaxN];
    std::memset(dist, 0, sizeof(dist));
    std::queue<int> q;
    q.push(idx);
    dist[idx] = 1;
    int maxDist = 1;
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < tree[cur].size(); i++)
        {
            if(dist[tree[cur][i]])
                continue;
            dist[tree[cur][i]] = dist[cur] + 1;
            maxDist = std::max(dist[tree[cur][i]], maxDist);
            q.push(tree[cur][i]);
        }
    }
    std::vector<std::pair<int, int>> answer;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == maxDist)
            answer.push_back({i, maxDist-1});
    }
    return answer;
}
int solution(int n, vector<vector<int>> edges) 
{
    int answer = 0;
    for(const auto& iter : edges)
    {
        tree[iter[0]].push_back(iter[1]);
        tree[iter[1]].push_back(iter[0]);
    }
    std::vector<std::pair<int,int>> ret1 = bfs(1, n); //getLeaf
    std::vector<std::pair<int,int>> ret2 = bfs(ret1[0].first, n); //leaf to leaf
    if(ret2.size() > 1)
        return ret2[0].second;
    std::vector<std::pair<int,int>> ret3 = bfs(ret2[0].first, n);
    return ret3.size() > 1 ? ret3[0].second : ret3[0].second-1;
}