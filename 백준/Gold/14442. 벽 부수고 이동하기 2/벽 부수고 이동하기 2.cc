#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, K, arr[1005][1005];
bool visited[11][1005][1005];
std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int i = 0; i < N; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
      arr[i][j] = str[j] - '0';
  }
  visited[0][0][0] = true;
  q.push({{0, 0}, {1, 0}});
  while(q.size())
  {
    int cy = q.front().first.first;
    int cx = q.front().first.second;
    int cd = q.front().second.first;
    int cc = q.front().second.second;
    q.pop();
    if(cy == N-1 && cx == M-1)
    {
      std::cout << cd;
      return 0;
    }
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if(arr[ny][nx] == 0 && !visited[cc][ny][nx])
      {
        visited[cc][ny][nx] = true;
        q.push({{ny, nx}, {cd+1, cc}});
      }
      else if(arr[ny][nx] == 1 && !visited[cc+1][ny][nx])
      {
        if(cc + 1 > K) continue;
        visited[cc+1][ny][nx] = true;
        q.push({{ny, nx}, {cd+1, cc+1}});
      }
    }
  }
  std::cout << -1;
  return 0;
}