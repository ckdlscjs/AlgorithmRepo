#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, K;
struct Pos
{
  int y;
  int x;
  int d;
  int c;
  bool day;
  Pos(int _y, int _x, int _d, int _c, bool _day) : y(_y), x(_x), d(_d), c(_c), day(_day) {}
};
int arr[1005][1005];
bool visited[11][1005][1005];
std::queue<Pos> q;
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
  q.push(Pos(0, 0, 1, 0, true));
  while(q.size())
  {
    auto pos = q.front();
    q.pop();
    if(pos.y == N-1 && pos.x == M-1)
    {
      std::cout << pos.d;
      return 0;
    }
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = pos.y + dy[dir];
      int nx = pos.x + dx[dir];
      if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
      if(arr[ny][nx] == 1 && !visited[pos.c+1][ny][nx])
      {
        if(pos.c+1 > K) continue;
        if(pos.day)
        {
          q.push(Pos(ny, nx, pos.d+1, pos.c+1, false));
          visited[pos.c+1][ny][nx] = true;
        }
        else
        {
          q.push(Pos(pos.y, pos.x, pos.d+1, pos.c, true));
        }
      }
      else if(arr[ny][nx] == 0 && !visited[pos.c][ny][nx])
      {
        visited[pos.c][ny][nx] = true;
        q.push(Pos(ny, nx, pos.d+1, pos.c, !pos.day));
      }
    }
  }
  std::cout << -1;
  return 0;
}