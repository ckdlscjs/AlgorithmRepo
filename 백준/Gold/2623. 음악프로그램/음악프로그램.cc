#include <bits/stdc++.h>
int N, M, C, A, B, cnts[1005];
std::vector<int> graph[1005];
std::vector<int> results;
bool TopologicalSort()
{
  std::queue<int> q;
  for(int i = 1; i <= N; i++)
    if(cnts[i] == 0) q.push(i);
  for(int i = 1; i <= N; i++)
  {
    if(q.empty())
      return false;
    int cur = q.front();
    q.pop();
    results.push_back(cur);
    for(const auto& iter : graph[cur])
    {
      cnts[iter]--;
      if(cnts[iter] <= 0)
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
  for(int m = 0; m < M; m++)
  {
    std::cin >> C;
    std::cin >> A;
    for(int c = 1; c < C; c++)
    {
      std::cin >> B;
      cnts[B]++;
      graph[A].push_back(B);
      A = B;
    }
  }
  if(TopologicalSort())
  {
    for(const auto& iter : results) std::cout << iter << '\n';
  }
  else
  {
    std::cout << 0;
  }
  return 0;
}