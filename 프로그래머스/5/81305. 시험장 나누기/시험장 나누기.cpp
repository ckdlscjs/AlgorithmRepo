#include <bits/stdc++.h>
using namespace std;
std::vector<int> indegree;
int root;
int dfs(const vector<int>& num, const vector<vector<int>>& links, int cur)
{
    int ret = num[cur];
    if(links[cur][0] != -1) ret += dfs(num, links, links[cur][0]);
    if(links[cur][1] != -1) ret += dfs(num, links, links[cur][1]);
    return ret;
}
std::pair<int, int> Check(const vector<int>& num, const vector<vector<int>>& links, const int mid, int cur)
{
    int c = 0, m = num[cur], l = 0, r = 0;
    if(links[cur][0] != -1)
    {
        auto ll = Check(num, links, mid, links[cur][0]);
        c += ll.first;
        l = ll.second;
    }
    if(links[cur][1] != -1)
    {
        auto rr = Check(num, links, mid, links[cur][1]);
        c += rr.first;
        r = rr.second;
    }
    if(c >= 10'005 || m > mid) return std::make_pair(10'005, 0);
    if(m + l + r <= mid) return std::make_pair(c, m + l + r);
    if(m + l > mid && m + r > mid) return std::make_pair(c + 2, m);
    if(m + l > mid && m + r <= mid) return std::make_pair(c + 1, m + r);
    if(m + r > mid && m + l <= mid) return std::make_pair(c + 1, m + l);
    if(m + l < mid && m + r < mid) return std::make_pair(c + 1, std::min(m + l, m + r));
}

int solution(int k, vector<int> num, vector<vector<int>> links) 
{
    indegree.resize(num.size(), 0);
    for(int i = 0; i < num.size(); i++)
    {
        if(links[i][0] != -1) indegree[links[i][0]]++;
        if(links[i][1] != -1) indegree[links[i][1]]++;
    }
    for(int i = 0; i < num.size(); i++) 
        if(indegree[i] == 0) 
            root = i;
    int lo = 0, hi = dfs(num, links, root) + 1;
    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        auto ret = Check(num, links, mid, root);
        if(ret.first <= k-1) hi = mid;
        else lo = mid;
    }
    return hi;
}