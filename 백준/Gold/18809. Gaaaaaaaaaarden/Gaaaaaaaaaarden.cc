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
    std::queue<std::pair<int, int>> q;
    std::queue<std::pair<int, std::pair<int, int>>> nq;
    for(int i = 0; i < inputs.size(); i++)
    {
      if(!arr_chk[i]) continue;
      int y = inputs[i].first;
      int x = inputs[i].second;
      field[y][x] = arr_chk[i];
      q.push({y, x});
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
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || field[ny][nx] || arr[ny][nx] == 0) continue;
        nq.push({field[cy][cx], {ny, nx}});
      }
      if(q.empty() && nq.size())
      {
        std::set<std::pair<int, int>> chks;
        while(nq.size())
        {
          int cc = nq.front().first;
          int cy = nq.front().second.first;
          int cx = nq.front().second.second;
          nq.pop();
          field[cy][cx] += (field[cy][cx] != cc ? cc : 0);
          chks.insert({cy, cx});
        }
        for(const auto& iter : chks)
        {
          if(field[iter.first][iter.second] < 7)
          {
            q.push({iter.first, iter.second});
            continue;
          }
          sum++;
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