#include <bits/stdc++.h>
const int MaxD = 20;
using namespace std;
int N, M, A, B, d[50'005], parents[MaxD][50'005];
std::vector<int> trees[50'005];
bool visited[50'005];
void DFS(int cur, int depth)
{
  visited[cur] = true;
  d[cur] = depth;
  for(const auto& iter : trees[cur])
  {
    if(visited[iter]) continue;
    parents[0][iter] = cur;
    DFS(iter, depth+1);
  }
}
int LCA(int a, int b)
{
  if(d[a] > d[b]) //d[b] > d[a] must
  {
    int temp = a;
    a = b;
    b = temp;
  }
  for(int p = MaxD-1; p >= 0; p--)
  {
    if(d[b] - d[a] >= (1 << p))
      b = parents[p][b];
  }
  if(a == b) return a;
  for(int p = MaxD-1; p >= 0; p--)
  {
    if(parents[p][a] != parents[p][b])
    {
      a = parents[p][a];
      b = parents[p][b];
    }
  }
  return parents[0][a];
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N-1; n++)
  {
    std::cin >> A >> B;
    trees[A].push_back(B);
    trees[B].push_back(A);
  }
  DFS(1, 0);
  for(int p = 1; p < MaxD; p++)
  {
    for(int node = 1; node <= N; node++)
    {
      parents[p][node] = parents[p-1][parents[p-1][node]];
    }
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> A >> B;
    std::cout << LCA(A, B) << '\n';
  }
  return 0;
}
