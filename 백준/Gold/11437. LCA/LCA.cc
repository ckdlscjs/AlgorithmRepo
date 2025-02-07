#include <bits/stdc++.h>
using namespace std;
const int MAXD = 20;
int N, M, A, B, d[50'005], parents[50'005][MAXD];
bool visited[50'005];
std::vector<int> trees[50'005];
void DFS(int cur, int depth)
{
  visited[cur] = true;
  d[cur] = depth;
  for(const auto& iter : trees[cur])
  {
    if(visited[iter]) continue;
    parents[iter][0] = cur;
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
  for(int p = MAXD-1; p >= 0; p--)
  {
    if(d[b] - d[a] >= (1 << p))
      b = parents[b][p];
  }
  if(a == b) return a;
  for(int p = MAXD-1; p >= 0; p--)
  {
    if(parents[a][p] != parents[b][p])
    {
      a = parents[a][p];
      b = parents[b][p];
    }
  }
  return parents[a][0];
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
  for(int p = 1; p < MAXD; p++)
  {
    for(int node = 1; node <= N; node++)
    {
      parents[node][p] = parents[parents[node][p-1]][p-1];
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
