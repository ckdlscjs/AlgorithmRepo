/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
std::vector<int> sets;
std::vector<int> ranks;
int Find(int node)
{
    if(sets[node] == node) return node;
    if(sets[node] == -1) return sets[node] = node;
    return sets[node] = Find(sets[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    if(ranks[root1] == ranks[root2]) 
        ranks[root1]++;
    if(ranks[root1] > ranks[root2])
    {
        sets[root2] = root1;
    }
    else
    {
        sets[root1] = root2;
    }
}
int N, M, T, res;
std::vector<std::vector<int>> partys;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> N >> M;
    sets.resize(N+1, -1);
    ranks.resize(N+1, 0);
    std::cin >> T;
    for(T; T > 0; T--)
    {
        int t;
        std::cin >> t;
        Union(0, t);
    }
    for(int m = 0; m < M; m++)
    {
        std::cin >> T;
        std::vector<int> ts(T);
        for(int t = 0; t < T; t++)
        {
            std::cin >> ts[t];
            if(t >= 1) 
                Union(ts[t], ts[t-1]);
        }
        partys.push_back(ts);
    }
    for(int m = 0; m < M; m++)
    {
        bool chk = true;
        for(const auto& iter : partys[m])
            if(Find(0) == Find(iter)) 
                chk = false;
        if(chk) res++;
    }
    std::cout << res;
	return 0;
}

