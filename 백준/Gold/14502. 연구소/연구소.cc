#include <bits/stdc++.h>
using namespace std;
const int MaxN = 10;
int n, m;
int arr[MaxN][MaxN];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
std::vector<std::pair<int, int>> emptys;
std::vector<std::pair<int, int>> viruss;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 0)
        emptys.push_back({i, j});
      if(arr[i][j] == 2)
        viruss.push_back({i, j});
    }
  }
  for(int i = 0; i < emptys.size(); i++)
  {
    for(int j = i + 1; j < emptys.size(); j++)
    {
      for(int k = j + 1; k < emptys.size(); k++)
      {
        arr[emptys[i].first][emptys[i].second] = 1;
        arr[emptys[j].first][emptys[j].second] = 1;
        arr[emptys[k].first][emptys[k].second] = 1;
        bool visited[10][10];
        std::memset(visited, 0, sizeof(visited));
        std::queue<std::pair<int, int>> q;
        for(const auto& iter : viruss)
        {
          q.push(iter);
          visited[iter.first][iter.second] = true;
        }
        while(q.size())
        {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();
          for(int dir = 0; dir < 4; dir++)
          {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || arr[ny][nx])
              continue;
            visited[ny][nx] = true;
            q.push({ny, nx});
          }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
          for(int j = 0; j < m; j++)
          {
            if(arr[i][j] == 0 && !visited[i][j])
              cnt++;
          }
        }
        result = std::max(result, cnt);
        arr[emptys[i].first][emptys[i].second] = 0;
        arr[emptys[j].first][emptys[j].second] = 0;
        arr[emptys[k].first][emptys[k].second] = 0;
      }
    }
  }
  std::cout << result;
  return 0;
}