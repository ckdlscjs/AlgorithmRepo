#include <bits/stdc++.h>
using namespace std;
int N, M, u, v, w, res, cnt = 1;
std::vector<std::tuple<int, int, int>> edges;
struct DisjointSet
{
    std::vector<int> parents;
    std::vector<int> ranks;
    DisjointSet(int _size) : parents(_size+1, -1), ranks(_size+1, 0) {}
    int Find(int cur)
    {
        if(parents[cur] == -1)
            return cur;
        return parents[cur] = Find(parents[cur]);
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
    for(int m = 0; m < M; m++)
    {
        std::cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    std::sort(edges.begin(), edges.end());
    for(int m = 0; m < M && cnt < N; m++)
    {
        w = std::get<0>(edges[m]);
        u = std::get<1>(edges[m]);
        v = std::get<2>(edges[m]);
        if(ds.Find(u) != ds.Find(v))
        {
            ds.Union(u, v);
            res += w;
            cnt++;
        }
    }
    std::cout << res - w;
    return 0;
}
