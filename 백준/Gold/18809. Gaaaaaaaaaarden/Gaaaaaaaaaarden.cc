#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, G, R, arr_chk[15], arr[55][55], field[55][55], res;
std::vector<std::pair<int, int>> inputs;
void CheckR(int idx, int cnt)
{
  if(cnt >= R)
  {
    int sum = 0;
    std::queue<std::pair<int, int>> q_green;
    std::queue<std::pair<int, int>> q_red;
    for(int i = 0; i < inputs.size(); i++)
    {
      if(!arr_chk[i]) continue;
      int y = inputs[i].first;
      int x = inputs[i].second;
      field[y][x] = arr_chk[i];
      if(field[y][x] == 3)
        q_green.push({y, x});
      else
        q_red.push({y, x});
    }
    while(q_green.size() || q_red.size())
    {
      int size_green = q_green.size();
      int size_red = q_red.size();
      for(int i = 0; i < size_green; i++)
      {
        int cy = q_green.front().first;
        int cx = q_green.front().second;
        int cc = field[cy][cx];
        q_green.pop();
        if(field[cy][cx] >= 7) continue;
        field[cy][cx] = 7;
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = cy + dy[dir];
          int nx = cx + dx[dir];
          if(ny < 0 || nx < 0 || ny >= N || nx >= M || field[ny][nx] || arr[ny][nx] == 0) continue;
          q_green.push({ny, nx});
          field[ny][nx] = cc;
        }
      }
      for(int i = 0; i < size_red; i++)
      {
        int cy = q_red.front().first;
        int cx = q_red.front().second;
        q_red.pop();
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = cy + dy[dir];
          int nx = cx + dx[dir];
          if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 0) continue;
          if(field[ny][nx] == 3)
          {
            sum++;
            field[ny][nx] = 7;
            continue;
          }
          if(field[ny][nx]) continue;
          q_red.push({ny, nx});
          field[ny][nx] = 4;
        }
      }
    }
    res = std::max(res, sum);
    std::memset(field, 0, sizeof(field));
    return;
  }
  for(int i = idx; i < inputs.size(); i++)
  {
    if(arr_chk[i]) continue;
    arr_chk[i] = 4;
    CheckR(i+1, cnt+1);
    arr_chk[i] = 0;
  }
}
void CheckG(int idx, int cnt)
{
  if(cnt >= G)
  {
    CheckR(0, 0);
    return;
  }
  for(int i = idx; i < inputs.size(); i++)
  {
    if(arr_chk[i]) continue;
    arr_chk[i] = 3;
    CheckG(i+1, cnt+1);
    arr_chk[i] = 0;
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> G >> R;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 2)
        inputs.push_back({i, j});
    }
  }
  CheckG(0, 0);
  std::cout << res;
  return 0;
}