#include <bits/stdc++.h>
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
int N, M, y, x, a, b, res;
bool visited[105][105], light[105][105];
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> switchs;
std::queue<std::pair<int, int>> q;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> y >> x >> a >> b;
    switchs[{y, x}].push_back({a, b});
  }
  light[1][1] = true;
  visited[1][1] = true;
  q.push({1, 1});
  while(q.size())
  {
    auto iter = q.front();
    q.pop();
    for(const auto& ton : switchs[{iter.first, iter.second}])
    {
      if(!light[ton.first][ton.second])
      {
        light[ton.first][ton.second] = true;
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = ton.first + dy[dir];
          int nx = ton.second + dx[dir];
          if(1 <= ny && ny <= N && 1 <= nx && nx <= N && visited[ny][nx] && !visited[ton.first][ton.second])
          {
            visited[ton.first][ton.second] = true;
            q.push(ton);
            break;
          }
        }
      }
    }
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = iter.first + dy[dir];
      int nx = iter.second + dx[dir];
      if(1 <= ny && ny <= N && 1 <= nx && nx <= N && light[ny][nx] && !visited[ny][nx])
      {
        visited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      res += light[i][j] ? 1 : 0;
  std::cout << res;
  return 0;
}