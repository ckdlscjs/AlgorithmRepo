#include <bits/stdc++.h>
using namespace std;
const int MaxN = 250005;
std::vector<int> tree[MaxN];
int solution(int n, vector<vector<int>> edges) 
{
    int answer = 0;
    for(const auto& iter : edges)
    {
        tree[iter[0]].push_back(iter[1]);
        tree[iter[1]].push_back(iter[0]);
    }
    return answer;
}