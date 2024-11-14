#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, arr[105][105], dist[105][105], cdist[105][105];
std::unordered_map<int, std::set<std::pair<int, int>>> starts;
void DFS(int y, int x, int c)
{
  dist[y][x] = c;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= N || dist[ny][nx]) continue;
    if(arr[ny][nx] == 1) DFS(ny, nx, c);
    else starts[c].insert({ny, nx});
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
  int c = 1;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(arr[i][j] == 0 || dist[i][j]) continue;
      DFS(i, j, c++);
    }
  }
  int distance = INT_MAX;
  for(const auto& iter : starts)
  {
    std::queue<std::pair<int, int>> q;
    for(const auto& it : iter.second)
    {
      q.push(it);
      cdist[it.first][it.second] = 1;
    }
    while(q.size())
    {
      int cy = q.front().first;
      int cx = q.front().second;
      q.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || cdist[ny][nx] || dist[ny][nx] == iter.first) continue;
        if(arr[ny][nx] == 0)
        {
          cdist[ny][nx] = cdist[cy][cx] + 1;
          q.push({ny, nx});
        }
        else if(dist[ny][nx] != iter.first)
        {
          distance = std::min(distance, cdist[cy][cx]);
        }
      }
    }
    std::memset(cdist, 0, sizeof(cdist));
  }
  std::cout <<distance;
  return 0;
}