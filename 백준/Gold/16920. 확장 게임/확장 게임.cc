#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, P, S[11], res[11];
std::string arr[1'005];
std::queue<std::pair<int, int>> q[11];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> P;
  for(int i = 1; i <= P; i++) std::cin >> S[i];
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    for(int j = 0; j < M; j++)
    {
      if('0' <= arr[i][j] && arr[i][j] <= '9')
      {
        q[arr[i][j] - '0'].push({i, j});
        res[arr[i][j] - '0']++;
      }
    }
  }
  int qsum = 1;
  while(qsum)
  {
    qsum = 0;
    for(int p = 1; p <= P; p++)
    {
      for(int s = 0; s < S[p] && q[p].size(); s++)
      {
        int len = q[p].size();
        for(int i = 0; i < len; i++)
        {
          auto iter = q[p].front();
          q[p].pop();
          for(int dir = 0; dir < 4; dir++)
          {
            int ny = iter.first + dy[dir];
            int nx = iter.second + dx[dir];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] != '.') continue;
            arr[ny][nx] = arr[iter.first][iter.second];
            q[p].push({ny, nx});
            res[p]++;
          }
        }
      }
      qsum += q[p].size();
    }
  }
  for(int i = 1; i <= P; i++)
    std::cout << res[i] << ' ';
  return 0;
}