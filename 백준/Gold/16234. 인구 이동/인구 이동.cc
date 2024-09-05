#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 55;
int arr[MaxN][MaxN];
int n, l, r;
bool Moves()
{
  bool ret = false;
  bool visited[MaxN][MaxN];
  std::memset(visited, false, sizeof(visited));
  std::queue<std::pair<int, int>> q;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(visited[i][j])
        continue;
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = i + dy[dir];
        int nx = j + dx[dir];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
          continue;
        int diff = std::abs(arr[ny][nx] - arr[i][j]);
        if(l <= diff && diff <= r)
        {
          ret = true;
          q.push({i, j});
          visited[i][j] = true;
          break;
        }
      }
      if(q.empty())
        continue;
      int sum = 0;
      std::vector<std::pair<int, int>> poss;
      while(q.size())
      {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        sum += arr[y][x];
        poss.push_back({y, x});
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = y + dy[dir];
          int nx = x + dx[dir];
          if(ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx])
            continue;
          int diff = std::abs(arr[ny][nx] - arr[y][x]); 
          if(!(l <= diff && diff <= r))
            continue;
          visited[ny][nx] = true;
          q.push({ny, nx});
        }
      }
      sum /= poss.size();
      for(const auto& iter : poss)
        arr[iter.first][iter.second] = sum;
    }
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> l >> r;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cin >> arr[i][j];
    }
  }
  int cnt = 0;
  while(Moves())
    cnt++;
  std::cout << cnt;
  return 0;
}