#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MaxN = 10005;
std::vector<int> tree[MaxN];
int cnt[MaxN];
int result = 0;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < m; i++)
  {
    int a, b;
    std::cin >> a >> b;
    tree[a].push_back(b);
  }
  for(int i = 1; i <= n; i++)
  {
    bool visited[MaxN];
    std::memset(visited, false, sizeof(visited));
    visited[i] = true;
    std::queue<int> q;
    q.push(i);
    while(q.size())
    {
      int cur = q.front();
      q.pop();
      cnt[cur]++;
      result = std::max(result, cnt[cur]);
      for(const auto& iter : tree[cur])
      {
        if(visited[iter])
          continue;
        visited[iter] = true;
        q.push(iter);
      }
    }
  }
    
  for(int i = 1; i <= n; i++)
    if(result == cnt[i])
      std::cout << i << ' ';
 
  return 0;
}