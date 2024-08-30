#include <bits/stdc++.h>
using namespace std;
int parent[55];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  int root = 0;
  for(int i = 0; i < n; i++)
  {
    std::cin >> parent[i];
    if(parent[i] == -1)
      root = i;
  }
  int del;
  std::cin >> del;
  parent[del] = -2;
  std::vector<int> tree[55];
  for(int i = 0; i < n; i++)
  {
    if(parent[i] == -1 || parent[i] == -2)
      continue;
    tree[parent[i]].push_back(i);
  }
  int result = 0;
  if(parent[root] != -2)
  {
    std::queue<int> q;
    q.push(root);
    while(q.size())
    {
      int cur = q.front();
      q.pop();
      if(tree[cur].empty())
        result++;
      for(const auto& iter : tree[cur])
      {
        q.push(iter);
      }
    }
  }
  std::cout << result;
  return 0;
}