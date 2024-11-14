#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, arr[105][105], area[105][105], dist[105][105];
void DFS(int y, int x, int c)
{
  arr[y][x] = c;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= N || arr[ny][nx] == 0) continue;
    if(arr[ny][nx] == 1) DFS(ny, nx, c);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  int c = 2;
  std::queue<std::pair<int, int>> q;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(arr[i][j] == 1)
        DFS(i, j, c++);
      area[i][j] = arr[i][j];
      if(area[i][j])
        q.push({i, j});
    }
  }
  int distance = INT_MAX;
  while(q.size())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= N || arr[ny][nx]) continue;
      if(area[ny][nx] == 0)
      {
        dist[ny][nx] = dist[cy][cx] + 1;
        area[ny][nx] = area[cy][cx];
        q.push({ny, nx});
      }
      else if(area[ny][nx] != area[cy][cx])
        distance = std::min(distance, dist[ny][nx] + dist[cy][cx]);
    }
  }
  std::cout << distance;
  return 0;
}