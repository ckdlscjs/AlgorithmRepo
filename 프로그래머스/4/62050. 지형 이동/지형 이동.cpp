#include <bits/stdc++.h>
using namespace std;
struct DisjointSet
{
    std::map<std::pair<int, int>, std::pair<int, int>> parent;
    std::map<std::pair<int, int>, int> rank;
    DisjointSet(int _low, int _col)
    {
        for(int i = 0; i < _low; i++)
            for(int j = 0; j < _col; j++)
                parent[{i, j}] = {-1, -1};
        
        for(int i = 0; i < _low; i++)
            for(int j = 0; j < _col; j++)
                rank[{i, j}] = 0;
    }
    std::pair<int, int> Find(std::pair<int, int> node)
    {
        if(parent[node].first == -1 && parent[node].second == -1)
            return node;
        return parent[node] = Find(parent[node]);
    }
    void Union(std::pair<int, int> node1, std::pair<int, int> node2)
    {
        std::pair<int, int> root1 = Find(node1);
        std::pair<int, int> root2 = Find(node2);
        if(root1 == root2)
            return;
        if(rank[root1] == rank[root2])
        {
            rank[root1]++;
            parent[root2] = root1;
        }
        else if(rank[root1] > rank[root2])
            parent[root2] = root1;
        else
            parent[root1] = root2;
    }
};
struct Edge
{
    std::pair<int, int> a;
    std::pair<int, int> b;
    Edge(std::pair<int, int> _a, std::pair<int, int> _b) : a(_a), b(_b) {}
};
struct Compare
{
    bool operator()(const std::pair<int, Edge>& a, const std::pair<int, Edge>& b)
    {
        return a.first > b.first;    
    }
};
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int solution(vector<vector<int>> land, int height) 
{
    DisjointSet ds(land.size(), land[0].size());
    std::priority_queue<std::pair<int, Edge>, std::vector<std::pair<int, Edge>>, Compare> pq;
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[0].size(); j++)
        {
            for(int dir = 0; dir < 4; dir++)
            {
                int ny = i + dy[dir];
                int nx = j + dx[dir];
                if(ny < 0 || nx < 0 || ny >= land.size() || nx >= land[0].size())
                    continue;
                int dist = std::abs(land[i][j] - land[ny][nx]);
                int w =  dist <= height ? 0 : dist;
                pq.push({w, Edge({i, j}, {ny, nx})});
            }
        }
    }
    int answer = 0;
    while(pq.size())
    {
        
        int w = pq.top().first;
        std::pair<int, int> from = pq.top().second.a;
        std::pair<int, int> to = pq.top().second.b;
        pq.pop();
        if(ds.Find(from) == ds.Find(to))
            continue;
        answer += w;
        ds.Union(from, to);
    }
    
    return answer;
}