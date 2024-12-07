#include <bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
int N, M, r, c, d, arr[55][55], res;
bool visited[55][55];
void DFS(int cd, int cy, int cx)
{
  res += visited[cy][cx] ? 0 : 1;
  visited[cy][cx] = true;
  bool move = false;
  for(int dd = 1; dd <= 4; dd++)
  {
    int dir = (cd + dd) % 4;
    int ny = cy + dy[dir];
    int nx = cx + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || arr[ny][nx] == 1) continue;
    move = true;
    DFS(dir, ny, nx);
    return;
  }
  if(!move)
  {
    int ny = cy - dy[cd];
    int nx = cx - dx[cd];
    if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 1) return;
    DFS(cd, ny, nx);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> r >> c >> d;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      std::cin >> arr[i][j];
  if(d == 1) d = 3;
  else if(d == 3) d = 1;
  DFS(d, r, c);
  std::cout << res;
  return 0;
}