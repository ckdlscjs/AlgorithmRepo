#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, arr[105][105], cnts[105][105];
bool visited[105][105];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      std::cin >> arr[i][j];
  int res = 0;
  std::queue<std::pair<int, int>> q;
  std::queue<std::pair<int, int>> dels;
  q.push({0, 0});
  visited[0][0] = true;
  while(q.size())
  {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx]) continue;
      if(arr[ny][nx] == 1)
      {
        cnts[ny][nx]++;
        if(cnts[ny][nx] >= 2)
          dels.push({ny, nx});
      }
      else
      {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
    if(q.empty() && dels.size())
    {
      res++;
      while(dels.size())
      {
        visited[dels.front().first][dels.front().second] = true;
        arr[dels.front().first][dels.front().second] = 0;
        q.push(dels.front());
        dels.pop();
      }
    }
  }
  std::cout << res;
  return 0;
}