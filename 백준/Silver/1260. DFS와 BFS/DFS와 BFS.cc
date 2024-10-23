#include <bits/stdc++.h>
int N, M, V, u, v;
std::vector<int> graph[1'005];
bool visited[1'005];
void DFS(int idx)
{
    visited[idx] = true;
    std::cout << idx << ' ';
    for(const auto& iter : graph[idx])
    {
        if(visited[iter])
            continue;
        DFS(iter);
    }
}
void BFS(int idx)
{
    std::queue<int> q;
    q.push(idx);
    while(q.size())
    {
        int cur = q.front();
        q.pop();
        if(visited[cur])
            continue;
        visited[cur] = true;
        std::cout << cur << ' ';
        for(const auto& iter : graph[cur])
           q.push(iter);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> N >> M >> V;
    for(int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
        std::sort(graph[i].begin(), graph[i].end(), std::less<>());
    DFS(V);
    std::memset(visited, false, sizeof(visited));
    std::cout << '\n';
    BFS(V);
    return 0;
}