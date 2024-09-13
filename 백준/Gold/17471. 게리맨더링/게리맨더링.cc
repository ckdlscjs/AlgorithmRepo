#include <bits/stdc++.h>
using namespace std;
int n;
const int MaxN = 15;
const int INF = 987654321;
int res = INF;
int costs[MaxN];
std::unordered_set<int> graph[MaxN];
int dfs(int idx, bool* visited, int color)
{
  int ret = 1;
  visited[idx] = true;
  bool cur = color&(1 << (idx-1));
  for(const auto& iter : graph[idx])
  {
    if(visited[iter])
      continue;
    bool next = color&(1<<(iter-1));
    if(cur != next)
      continue;
    ret += dfs(iter, visited, color);
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 1; i <= n; i++)
    std::cin >> costs[i];
  for(int a = 1; a <= n; a++)
  {
    int m;
    std::cin >> m;
    for(int j = 0; j < m; j++)
    {
      int b;
      std::cin >> b;
      graph[a].insert(b);
      graph[b].insert(a);
    }
  }
  for(int i = 1; i < (1 << n) - 1; i++)
  {
    bool visited[15];
    std::memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int j = 0; j < n; j++)
    {
      if(i & 1 << j)
      {
        cnt += dfs(j+1, visited, i);
        break;
      }
    }
    for(int j = 0; j < n; j++)
    {
      if(!(i & 1 << j))
      {
        cnt += dfs(j+1, visited, i);
        break;
      }
    }
      
    if(cnt != n)
      continue;
    
    int sum_a = 0, sum_b = 0;
    for(int j = 0; j < n; j++)
    {
      if(i & (1 << j))
        sum_a += costs[j+1];
      else
        sum_b += costs[j+1];
    }
    res = std::min(res, std::abs(sum_a - sum_b));
  }
  std::cout << (res == INF ? -1 : res);
  return 0;
}