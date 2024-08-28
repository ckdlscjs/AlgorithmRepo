#include <bits/stdc++.h>
using namespace std;
int N, M;
const int MaxN = 32005;
int enter_degree[MaxN];
std::vector<int> graph[MaxN];
bool TopologicalSort()
{
  std::queue<int> q;
  for(int i = 1; i <= N; i++)
    if(enter_degree[i] == 0)
      q.push(i);
  
  for(int i = 1; i <= N; i++)
  {
    if(q.empty())
      return false;
    int cur = q.front();
    q.pop();
    std::cout << cur << ' ';
    for(const auto& iter : graph[cur])
    {
      enter_degree[iter]--;
      if(enter_degree[iter] == 0)
        q.push(iter);
    }
  }
  return true;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b;
    std::cin >> a >> b;
    graph[a].push_back(b);
    enter_degree[b]++;
  }
  TopologicalSort();
  return 0;
}