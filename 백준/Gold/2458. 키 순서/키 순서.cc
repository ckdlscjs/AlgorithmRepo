#include <bits/stdc++.h>
using namespace std;
int N, M, u, v, in[505], out[505];
bool visited[505][505];
std::vector<int> graph[505];
int DFS(int start, int cur)
{
  int ret = 1;
  visited[start][cur] = true;
  for(const auto& iter : graph[cur])
    if(!visited[start][iter])
      in[iter]++, ret += DFS(start, iter);
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v;
    graph[u].push_back(v);
  }
  for(int i = 1; i <= N; i++)
    out[i] += DFS(i, i);
  int ans = 0;
  for(int i = 1; i <= N; i++)
  {
    //std::cout << in[i] << ' ' <<out[i] << '\n';
    if(in[i] + out[i] == N) ans++;
  }
  std::cout << ans;
  return 0;
}