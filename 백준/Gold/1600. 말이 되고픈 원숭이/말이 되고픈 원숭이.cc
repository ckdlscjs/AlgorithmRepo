#include <bits/stdc++.h>
using namespace std;
const int kdy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int kdx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int K, H, W, arr[205][205];
bool visited[35][205][205];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> K >> W >> H;
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      std::cin >> arr[i][j];
  std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
  q.push({{0, 0}, {0, 0}});
  visited[0][0][0] = true;
  int res = INT_MAX;
  while(q.size())
  {
    int dist = q.front().first.first;
    int ck = q.front().first.second;
    int cy = q.front().second.first;
    int cx = q.front().second.second;
    q.pop();
    if(cy == H-1 && cx == W-1)
    {
      res = std::min(res, dist);
      continue;
    }
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= H || nx >= W || arr[ny][nx] || visited[ck][ny][nx]) continue;
      visited[ck][ny][nx] = true;
      q.push({{dist+1, ck}, {ny, nx}});
    }
    if(ck >= K) continue;
    for(int dir = 0; dir < 8; dir++)
    {
      int ny = cy + kdy[dir];
      int nx = cx + kdx[dir];
      if(ny < 0 || nx < 0 || ny >= H || nx >= W || arr[ny][nx] || visited[ck+1][ny][nx]) continue;
      visited[ck+1][ny][nx] = true;
      q.push({{dist+1, ck+1}, {ny, nx}});
    }
  }
  std::cout << (res == INT_MAX ? -1 : res);
  return 0;
}