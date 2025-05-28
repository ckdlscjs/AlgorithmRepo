/*
1.접근방식:
문제에서 주어진 조건은 중간이 확실하게 아닌 갯수를 세는것, 즉 어떤 노드를 기반으로 탐색하였을때 해당노드의 자식의 갯수가 N/2이상이된다면
확연하게 중간보다 멀리 있을 수 있다
홀수개의N이 주어지므로 
3->1 초과시 ㅁ ㅁ ㅁ
5->2 초과시 ㅁ ㅁ ㅁ ㅁ ㅁ
7->3 초과시 ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ ㅁ..
고로 해당 N/2를 자식의 갯수가 초과한다면 무조건 중간보다는 멀리 있게되므로 개수를 센다, 이때 단방향 그래프로 들어오는 입력을
양방향의 두개의 그래프를 만들어 DFS하여 자식노드의 갯수를 세준다

2.시간복잡도:
O(100*5000*2 + 100)

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
