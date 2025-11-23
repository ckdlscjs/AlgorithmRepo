#include <bits/stdc++.h>

using namespace std;
std::vector<int> parents;
std::vector<int> ranks;
int Find(int node)
{
    if(parents[node] == node || parents[node] == -1) return parents[node] = node;
    return parents[node] = Find(parents[node]);
}
void Union(int node1, int node2)
{
    int root1 = Find(node1);
    int root2 = Find(node2);
    if(root1 == root2) return;
    if(ranks[root1] == ranks[root2]) ranks[root1]++;
    if(ranks[root1] > ranks[root2]) parents[root2] = root1; 
    else parents[root1] = root2;
}
int solution(int n, vector<vector<int>> costs) 
{
    parents.resize(n+1, -1);
    ranks.resize(n+1, 0);
    std::sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b){
        return a[2] < b[2];
    });
    int answer = 0;
    for(const auto& iter : costs)
    {
        if(Find(iter[0]) == Find(iter[1])) continue;
        Union(iter[0], iter[1]);
        answer += iter[2];
    }
    return answer;
}