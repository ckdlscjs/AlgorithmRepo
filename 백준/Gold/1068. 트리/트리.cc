/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
int N, root, erase;
std::vector<int> graph[52];
int DFS(int cur)
{
    if(cur == erase) return 0;
    if(graph[cur].size() <= 0) return 1;
    int ret = 0;
    for(const auto& iter : graph[cur])
    {
        ret += DFS(iter);
        if(graph[cur].size() <= 1 && iter == erase) ret+=1;
    }
        
    return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        int parent;
        std::cin >> parent;
        if(parent == -1) root = i;
        else graph[parent].push_back(i);
    }
    std::cin >> erase;
    std::cout << DFS(root);
	return 0;
}

