/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int V, E, res;
std::vector<std::tuple<int, int, int>> edges;
std::vector<int> parents;
int Find(int node)
{
    if(parents[node] == node) return node;
    if(parents[node] == -1) return parents[node] = node;
    return parents[node] = Find(parents[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    if(root1 > root2) parents[root1] = root2;
    else parents[root2] = root1;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> V >> E;
    parents.resize(V+1, -1);
    for(int e = 0; e < E; e++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    std::sort(edges.begin(), edges.end());
    for(const auto& iter : edges)
    {
        int w = std::get<0>(iter);
        int u = std::get<1>(iter);
        int v = std::get<2>(iter);
        if(Find(u) == Find(v)) continue;
        Union(u, v);
        res += w;
    }
    std::cout << res;
	return 0;
}

