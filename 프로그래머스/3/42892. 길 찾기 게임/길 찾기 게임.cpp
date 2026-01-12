#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val = 0;
    int x = 0;
    std::vector<Node> left;
    std::vector<Node> right;
};
void Insert(Node& cur, const std::vector<int>& node)
{
    if(cur.val == 0)
    {
        cur.val = node[2];
        cur.x = node[0];
        return;
    }
    if(node[0] < cur.x)
    {
        if(!cur.left.size()) cur.left.push_back(Node());
        Insert(cur.left[0], node);
    }
    else
    {
        if(!cur.right.size()) cur.right.push_back(Node());
        Insert(cur.right[0], node);
    }
}
void PrintInOrder(const Node& cur)
{
    if(cur.left.size()) PrintInOrder(cur.left[0]);
    std::cout << cur.val << ' ';
    if(cur.right.size()) PrintInOrder(cur.right[0]);
}
std::vector<int> PreOrder(const Node& cur)
{
    std::vector<int> ret;
    ret.push_back(cur.val);
    if(cur.left.size())
    {
        auto temp = PreOrder(cur.left[0]);
        ret.insert(ret.begin() + ret.size(), temp.begin(), temp.end());
    }
    if(cur.right.size())
    {
        auto temp = PreOrder(cur.right[0]);
        ret.insert(ret.begin() + ret.size(), temp.begin(), temp.end());
    }
    return ret;
}

std::vector<int> PostOrder(const Node& cur)
{
    std::vector<int> ret;
    if(cur.left.size())
    {
        auto temp = PostOrder(cur.left[0]);
        ret.insert(ret.begin() + ret.size(), temp.begin(), temp.end());
    }
    if(cur.right.size())
    {
        auto temp = PostOrder(cur.right[0]);
        ret.insert(ret.begin() + ret.size(), temp.begin(), temp.end());
    }
    ret.push_back(cur.val);
    return ret;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    for(int i = 0; i < nodeinfo.size(); i++) nodeinfo[i].push_back(i+1);
    std::sort(nodeinfo.begin(), nodeinfo.end(), [](const std::vector<int>& a, const std::vector<int>& b)
              {
                  return a[1] > b[1];
              });
    Node root;
    for(const auto& iter : nodeinfo) Insert(root, iter);
    //PrintInOrder(root);
    return {PreOrder(root), PostOrder(root)};
}