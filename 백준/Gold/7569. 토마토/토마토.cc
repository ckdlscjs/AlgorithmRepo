#include <bits/stdc++.h>
const int dz[] = {0, 0, 0, 0, -1, 1};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dx[] = {1, -1, 0, 0, 0, 0};
int N, M, H, cnt_zero, dist, arr[105][105][105];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M >> N >> H;
  std::queue<std::pair<int, std::pair<int, int>>> q;
  for(int h = 0; h < H; h++)
  {
    for(int n = 0; n < N; n++)
    {
      for(int m = 0; m < M; m++)
      {
        std::cin >> arr[h][n][m];
        if(arr[h][n][m] == 1)
          q.push({h, {n, m}});
        if(arr[h][n][m] == 0)
          cnt_zero++;
      }
    }
  }
  while(q.size() && cnt_zero)
  {
    int cz = q.front().first;
    int cy = q.front().second.first;
    int cx = q.front().second.second;
    q.pop();
    for(int dir = 0; dir < 6; dir++)
    {
      int nz = cz + dz[dir];
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M || arr[nz][ny][nx] != 0) continue;
      cnt_zero--;
      arr[nz][ny][nx] = arr[cz][cy][cx] + 1;
      q.push({nz,{ny, nx}});
      dist = std::max(dist, arr[nz][ny][nx]);
    }
  }
  std::cout << (cnt_zero ? -1 : std::max(0, dist-1));
  return 0;
}