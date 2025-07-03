/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int K;
bool DFS(const std::vector<std::vector<int>>& graph, std::vector<int>& color, int cur, int c)
{
    bool ret = true;
    color[cur] = c;
    c *= -1;
    for(const auto& iter : graph[cur])
    {
        if(color[iter] == c) continue;
        else if(color[iter] == color[cur]) return false;
        ret &= DFS(graph, color, iter, c);
    }
    return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> K;
    for(int k = 0; k < K; k++)
    {
        int V, E;
        std::cin >> V >> E;
        std::vector<std::vector<int>> graph(V+1);
        std::vector<int> color(V+1, 0);
        for(int e = 0; e < E; e++)
        {
            int u, v;
            std::cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        bool ret = true;
        for(int i = 1; i <= V; i++)
        {
            if(color[i] != 0) continue;
            ret &= DFS(graph, color, i, 1);
        }
        if(ret) std::cout << "YES";
        else std::cout << "NO";
        std::cout << '\n';
    }
	return 0;
}

