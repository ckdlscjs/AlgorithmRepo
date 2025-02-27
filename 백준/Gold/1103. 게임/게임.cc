#include <bits/stdc++.h>
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int INF = INT_MAX;
int N, M, dp[55][55], res;
char arr[55][55];
bool visited[55][55];
void Check(int cy, int cx)
{
  if(res == INF) return;
  visited[cy][cx] = true;
  int cnt = arr[cy][cx]-'0';
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = cy + dy[dir] * cnt;
    int nx = cx + dx[dir] * cnt;
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 'H') continue;
    if(visited[ny][nx])
    {
      dp[ny][nx] = INF;
      res = INF;
      return;
    }
    if(dp[ny][nx] < dp[cy][cx] + 1)
    {
      dp[ny][nx] = dp[cy][cx] + 1;
      res = std::max(res, dp[ny][nx]);
      if(res == INF) return;
      Check(ny, nx);
    }
  }
  visited[cy][cx] = false;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int n = 0; n < N; n++)
  {
    std::string str;
    std::cin >> str;
    for(int m = 0; m < M; m++) arr[n][m] = str[m];
  }
  dp[0][0] = 1;
  res = std::max(res, dp[0][0]);
  Check(0, 0);
  std::cout << (res == INF ? -1 : res);
  return 0;
}