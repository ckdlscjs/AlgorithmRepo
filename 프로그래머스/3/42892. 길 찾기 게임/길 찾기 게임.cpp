#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int left = -1;
    int right = -1; 
    int value = -1;
    int idx = -1;
};
Node node[10005];
void InsertNode(int parent, int idx, int value)
{
    if(node[parent].value == -1)
    {
        node[parent].idx = idx;
        node[parent].value = value;
    }
    else if(value < node[parent].value)
    {
        if(node[parent].left == -1)
        {
            node[parent].left = idx;
            node[idx].idx = idx;
            node[idx].value = value;
        }
        else
            InsertNode(node[parent].left, idx, value);
    }
    else
    {
       if(node[parent].right == -1)
        {
            node[parent].right = idx;
            node[idx].idx = idx;
            node[idx].value = value;
        }
        else
            InsertNode(node[parent].right, idx, value);
    }
}
void PreOrder(int idx, std::vector<int>& ans)
{
    ans.push_back(node[idx].idx);
    if(node[idx].left != -1)
        PreOrder(node[idx].left, ans);
    if(node[idx].right != -1)
        PreOrder(node[idx].right, ans);
}
void PostOrder(int idx, std::vector<int>& ans)
{
    if(node[idx].left != -1)
        PostOrder(node[idx].left, ans);
    if(node[idx].right != -1)
        PostOrder(node[idx].right, ans);
    ans.push_back(node[idx].idx);
}
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
std::less<std::pair<int, std::pair<int, int>>>> pq;
vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        pq.push({y,{i+1, x}});
    }
    int rootidx = pq.top().second.first;
    while(pq.size())
    {
        auto iter = pq.top();
        pq.pop();
        InsertNode(rootidx, iter.second.first, iter.second.second);
    }
    vector<vector<int>> answer;
    std::vector<int> ans;
    PreOrder(rootidx, ans);
    answer.push_back(ans);
    ans.clear();
    PostOrder(rootidx, ans);
    answer.push_back(ans);
    ans.clear();
    
    return answer;
}