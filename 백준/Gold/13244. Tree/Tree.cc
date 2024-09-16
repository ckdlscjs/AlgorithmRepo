#include <bits/stdc++.h>
int t, n, e;
const int MaxN = 1005;
bool visited[MaxN];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> t;
  for(int te = 0; te < t; te++)
  {
    std::cin >> n >> e;
    std::vector<int> graph[MaxN];
    for(int i = 0; i < e; i++)
    {
      int a, b;
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    std::memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
      if(visited[i])
        continue;
      cnt++;
      visited[1] = true;
      std::queue<int> q;
      q.push(1);
      while(q.size())
      {
        int cur = q.front();
        q.pop();
        for(const auto& iter : graph[cur])
        {
          if(visited[iter])
            continue;
          visited[iter] = true;
          q.push(iter);
        }
      }
    }
    std::cout << ((cnt == 1 && e+1 == n) ? "tree" : "graph") << '\n';
  }
  return 0;
}