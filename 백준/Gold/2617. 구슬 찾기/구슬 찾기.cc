/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, A, B, AB[100], BA[100], res;
std::unordered_set<int> graphAB[100], graphBA[100];
int dfs(const std::unordered_set<int>* graph, bool* visited, int cur)
{
    visited[cur] = true;
    int ret = 1;
    for(const auto& iter : graph[cur])
    {
        if(visited[iter]) continue;
        ret += dfs(graph, visited, iter);
    }
    return ret;
}
int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> A >> B;
        graphAB[A].insert(B);
        graphBA[B].insert(A);
    }
    for(int i = 1; i <= N; i++)
    {
        bool visited[100];
        std::memset(visited, false, sizeof(visited));
        AB[i] = dfs(graphAB, visited, i) - 1;
        
        std::memset(visited, false, sizeof(visited));
        BA[i] = dfs(graphBA, visited, i) - 1;
    }
 
    for(int i = 1; i <= N; i++)
    {
        //std::cout << AB[i] << ' ' << BA[i] << '\n';
        if(AB[i] > N/2 || BA[i] > N/2)
            res++;
    }
    std::cout << res;
    return 0;
}
