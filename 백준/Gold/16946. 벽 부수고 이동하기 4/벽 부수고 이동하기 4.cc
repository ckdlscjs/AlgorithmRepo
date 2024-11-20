#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, areas[1005][1005];
std::unordered_map<int, int> areas_width;
std::string arr[1005];
int DFS(int y, int x, int area)
{
  int ret = 1;
  areas[y][x] = area;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == '1' || areas[ny][nx]) continue;
    ret += DFS(ny, nx, area);
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  int idx = 1;
  std::queue<std::pair<int, int>> walls;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      if(arr[i][j] == '1')
      {
        walls.push({i, j});
      }
      else if(arr[i][j] == '0' && areas[i][j] == 0)
      {
        int sum = DFS(i, j, idx);
        areas_width[idx++] = sum;
      }
    }
  }
  while(walls.size())
  {
    int y = walls.front().first;
    int x = walls.front().second;
    walls.pop();
    std::set<int> sums;
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = y + dy[dir];
      int nx = x + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M || !areas[ny][nx]) continue;
      sums.insert(areas[ny][nx]);
    }
    int sum = 0;
    for(const auto& iter : sums)
      sum += areas_width[iter];
    arr[y][x] = ((sum+1) % 10) + '0';
  }
  for(int i = 0; i < N; i++)
    std::cout << arr[i] << '\n';
  return 0;
}