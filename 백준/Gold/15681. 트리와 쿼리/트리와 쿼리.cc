#include <bits/stdc++.h>
using namespace std;
int N, R, Q, u, v, cnts[100'005];
std::vector<int> graph[100'005];
bool visited[100'005];
int dfs(int cur)
{
    cnts[cur] = 1;
    visited[cur] = true;
    for(const auto& iter : graph[cur])
    {
        if(visited[iter]) continue;
        cnts[cur] += dfs(iter);
    }
    return cnts[cur];
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> R >> Q;
    for(int n = 0; n < N-1; n++)
    {
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(R);
    for(int q = 0; q < Q; q++)
    {
        std::cin >> u;
        std::cout << cnts[u] << '\n';
    }
    return 0;
}
