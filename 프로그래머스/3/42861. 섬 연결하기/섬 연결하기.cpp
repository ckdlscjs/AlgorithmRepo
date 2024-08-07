#include <bits/stdc++.h>
using namespace std;
struct DisjointSet
{
    std::vector<int> parent;
    std::vector<int> rank;
    DisjointSet(int _size) : parent(_size, -1), rank(_size, 0) {}
    int Find(int node)
    {
        if(parent[node] == -1)
            return node;
        return parent[node] = Find(parent[node]);
    }
    void Union(int node1, int node2)
    {
        int root1 = Find(node1);
        int root2 = Find(node2);
        if(root1 == root2)
            return;
        if(rank[root1] == rank[root2])
        {
            rank[root1]++;
            parent[root2] = root1;
        }
        if(rank[root1] > rank[root2])
            parent[root2] = root1;
        else
            parent[root1] = root2;
    }
};
int solution(int n, vector<vector<int>> costs) 
{
    DisjointSet ds(n);
    std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b)
              {
                return a[2] < b[2];       
              });
    int answer = 0;
    for(const auto& iter : costs)
    {
        if(ds.Find(iter[0]) != ds.Find(iter[1]))
        {
            ds.Union(iter[0], iter[1]);
            answer += iter[2];
        }
    }
    
    return answer;
}