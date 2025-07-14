/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, M, outdegreeAB[100], outdegreeBA[100], res;
bool visited[100];
std::vector<int> graphAB[100], graphBA[100];
int DFS(const std::vector<int>* graph, int cur)
{
    visited[cur] = true;
    int ret = 0;
    for(const auto& iter : graph[cur])
    {
        if(visited[iter]) continue;
        ret += DFS(graph, iter) + 1;
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
        int A, B;
        std::cin >> A >> B;
        graphAB[A].push_back(B);
        graphBA[B].push_back(A);
    }
    for(int i = 1; i <= N; i++)
    {
        std::memset(visited, false, sizeof(visited));
        outdegreeAB[i] = DFS(graphAB, i);
        
        std::memset(visited, false, sizeof(visited));
        outdegreeBA[i] = DFS(graphBA, i);
    }
    for(int i = 1; i <= N; i++)
    {
        //std::cout << outdegreeAB[i] << ' ' << outdegreeBA[i] << '\n';
        if(outdegreeAB[i] > N/2 || outdegreeBA[i] > N/2) res++;
    }
    std::cout << res;
	return 0;
}

