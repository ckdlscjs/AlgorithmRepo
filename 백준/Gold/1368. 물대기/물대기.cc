/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, adj[302][302], res;
std::vector<std::tuple<int, int, int>> edges;
std::vector<int> parents;
std::vector<int> ranks;
int Find(int node)
{
    if(parents[node] == node) return node;
    return parents[node] = Find(parents[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    if(ranks[root1] == ranks[root2]) ranks[root1]++;
    if(ranks[root1] > ranks[root2]) parents[root2] = root1;
    else parents[root1] = root2;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    parents.resize(N+1, 0);
    ranks.resize(N+1, 0);
    for(int n = 1; n <= N; n++)
    {
        std::cin >> adj[n][n];
        parents[n] = n;
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int val;
            std::cin >> val;
            if(i == j) continue;
            else adj[i][j] = val;
        }
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = i; j <= N; j++)
        {
            if(i == j) edges.push_back({adj[i][i], 0, i});
            else edges.push_back({adj[i][j], i, j});
        }
    }
        
    std::sort(edges.begin(), edges.end());
    
    for(const auto& iter : edges)
    {
        int cost = std::get<0>(iter);
        int u = std::get<1>(iter);
        int v = std::get<2>(iter);
        //std::cout << cost << ' ' << u << ' ' << v << '\n';
        if(Find(u) == Find(v)) continue;
        Union(u, v);
        res += cost;
    }
    std::cout << res;
	return 0;
}

