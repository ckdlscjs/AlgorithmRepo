//https://school.programmers.co.kr/learn/courses/30/lessons/42892
#include <bits/stdc++.h>
using namespace std;
struct Tree
{
    int idx = 0;
    int val = 0;
    int left = 0;
    int right = 0;
};
Tree tree[10'005];
std::vector<std::pair<std::pair<int, int>, int>> nodes;
void InsertNode(int idx, const std::pair<std::pair<int, int>, int>& node)
{
    if(tree[idx].idx == 0)
    {
        tree[idx].idx = node.second;
        tree[idx].val = node.first.second;
        return;
    }
    if(node.first.second < tree[idx].val)
    {
        if(tree[idx].left == 0)
            tree[idx].left = node.second;
         InsertNode(tree[idx].left, node);
    }
    else
    {
        if(tree[idx].right == 0)
            tree[idx].right = node.second;
        InsertNode(tree[idx].right, node);
    }
}
void PreOrder(int idx, vector<int>& answer)
{
    answer.push_back(tree[idx].idx);
    if(tree[idx].left) PreOrder(tree[idx].left, answer);
    if(tree[idx].right) PreOrder(tree[idx].right, answer);
}
void PostOrder(int idx, vector<int>& answer)
{
    if(tree[idx].left) PostOrder(tree[idx].left, answer);
    if(tree[idx].right) PostOrder(tree[idx].right, answer);
    answer.push_back(tree[idx].idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    for(int i = 0; i < nodeinfo.size(); i++)
        nodes.push_back({{nodeinfo[i][1], nodeinfo[i][0]}, i+1});
    std::sort(nodes.begin(), nodes.end(), [](const std::pair<std::pair<int, int>, int>& a, const std::pair<std::pair<int, int>, int>& b)
              {
                 return a.first.first == b.first.first ? a.first.second < b.first.second : a.first.first > b.first.first; 
              });
    for(const auto& iter : nodes)
        InsertNode(nodes[0].second, iter);
    std::vector<int> pre, post;
    vector<vector<int>> answer;
    PreOrder(nodes[0].second, pre);
    answer.push_back(pre);
    PostOrder(nodes[0].second, post);
    answer.push_back(post);
    return answer;
}