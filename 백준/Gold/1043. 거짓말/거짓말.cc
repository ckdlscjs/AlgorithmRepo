#include <bits/stdc++.h>
using namespace std;
int N, M, T, val, res, adj[52][52];
std::vector<std::vector<int>> partys;
struct DisjointSet
{
    std::vector<int> ranks;
    std::vector<int> parents;
    DisjointSet(int _size) : parents(_size + 1, -1), ranks(_size+1, 0) {}
    int Find(int node)
    {
        if(parents[node] == -1)
            return node;
        return parents[node] = Find(parents[node]);
    }
    void Union(int node1, int node2)
    {
        int root1 = Find(node1);
        int root2 = Find(node2);
        if(root1 == root2) return;
        if(ranks[root1] == ranks[root2])
        {
            ranks[root1]++;
            parents[root2] = root1;
        }
        else if(ranks[root1] > ranks[root2])
        {
            parents[root2] = root1;
        }
        else
        {
            parents[root1] = root2;
        }
    }
};
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N >> M;
    DisjointSet ds(N);
    partys.resize(M);
    ds.ranks[0] = 55;
    std::cin >> T;
    for(int t = 0; t < T; t++)
    {
        std::cin >> val;
        ds.Union(0, val);
    }
    for(int m = 0; m < M; m++)
    {
        std::cin >> T;
        for(int t = 0; t < T; t++)
        {
            std::cin >> val;
            partys[m].push_back(val);
            if(t >= 1)
                ds.Union(partys[m][t-1], partys[m][t]);
        }
    }
    for(int m = 0; m < M; m++)
    {
        bool liar = false;
        for(const auto& iter : partys[m])
            liar |= ds.Find(0) == ds.Find(iter);
        if(!liar) res++;
    }

    std::cout << res;
    return 0;
}
