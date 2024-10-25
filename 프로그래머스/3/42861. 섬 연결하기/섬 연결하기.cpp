//https://school.programmers.co.kr/learn/courses/30/lessons/42861
#include <bits/stdc++.h>
using namespace std;
struct DisjointSet
{
    std::vector<int> parents;
    std::vector<int> ranks;
    DisjointSet(int _size) : parents(_size, -1), ranks(_size, 0) {}
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
        if(root1 == root2)
            return;
        if(ranks[root1] == ranks[root2])
        {
            ranks[root1] ++;
            parents[root2] = root1;
        }
        if(ranks[root1] > ranks[root2])
            parents[root2] = root1;
        else
            parents[root1] = root2;
    }
};
int solution(int n, vector<vector<int>> costs) 
{
    DisjointSet ds(n);
    int answer = 0;
    std::sort(costs.begin(), costs.end(), [](const std::vector<int>& a, const std::vector<int>& b){
        return a[2] < b[2];
    });
    for(const auto& iter : costs)
    {
        if(ds.Find(iter[0]) == ds.Find(iter[1]))
            continue;
        ds.Union(iter[0], iter[1]);
        answer += iter[2];
    }
    return answer;
}