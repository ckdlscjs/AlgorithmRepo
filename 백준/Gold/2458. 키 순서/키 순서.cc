#include <bits/stdc++.h>
using namespace std;
int N, M, u, v;
const int INF = 987654321;
int adj[505][505];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::fill_n(&adj[0][0], 505*505, INF);
  for(int i = 1; i <= N; i++)
    adj[i][i] = 0;
  for(int i = 0; i < M; i++)
  {
    std::cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = -1;
  }
  for(int m = 1; m <= N; m++)
  {
    for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        if(adj[i][m] != INF && adj[m][j] != INF)
        {
          if(adj[i][m] == 1 && adj[m][j] == 1)
          {
            adj[i][j] = 1;
            adj[j][i] = -1;
          }
          else if(adj[i][m] == -1 && adj[m][j] == -1)
          {
            adj[i][j] = -1;
            adj[j][i] = 1;
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= N; i++)
  {
    int cnt = 0;
    for(int j = 1; j <= N; j++)
      if(adj[i][j] != INF) cnt++;
    if(cnt == N) ans++;
  }
  std::cout << ans;
  return 0;
}