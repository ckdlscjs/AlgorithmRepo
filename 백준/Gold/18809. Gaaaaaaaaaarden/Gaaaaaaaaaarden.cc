#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, G, R, arr[55][55], field[55][55], res;
std::unordered_set<int> poss;
std::unordered_set<int> chks;
std::vector<std::pair<int, int>> inputs;
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
  for(int i = 1; i < (1 << inputs.size()); i++)
  {
    int cnt = 0;
    for(int j = 0; j < inputs.size(); j++)
      cnt += (i & (1 << j)) ? 1 : 0;
    if(cnt == G+R)
      poss.insert(i);
  }
  for(int i = 1; i < (1 << G+R); i++)
  {
    int gcnt = 0, rcnt = 0;
    for(int j = 0; j < G+R; j++)
    {
      gcnt += (i & (1 << j)) ? 0 : 1;
      rcnt += (i & (1 << j)) ? 1 : 0;
    }
    if(gcnt == G && rcnt == R)
      chks.insert(i);
  }
  for(const auto& pos : poss)
  {
    for(const auto& iter : chks)
    {
      int sum = 0, idx = 0;
      std::queue<std::pair<int, int>> q;
      std::queue<std::pair<int, std::pair<int, int>>> nq;
      for(int i = 0; i < inputs.size(); i++)
      {
        if(!(pos & 1 << i)) continue;
        int y = inputs[i].first;
        int x = inputs[i].second;
        field[y][x] = (iter & 1 << idx++) ? 4 : 3;
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
          if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 0 || field[ny][nx]) continue;
          nq.push({field[cy][cx], {ny, nx}});
        }
        if(q.empty() && nq.size())
        {
          std::set<std::pair<int, int>> nexts;
          while(nq.size())
          {
            int c = nq.front().first;
            int y = nq.front().second.first;
            int x = nq.front().second.second;
            nq.pop();
            field[y][x] += (field[y][x] != c) ? c : 0;
            nexts.insert({y, x});
          }
          for(const auto& iter : nexts)
          {
            if(field[iter.first][iter.second] >= 7)
              sum++;
            else
              q.push({iter.first, iter.second});
          }
        }
      }
      res = std::max(res, sum);
      std::memset(field, 0, sizeof(field));
    }
  }
  std::cout << res;
  return 0;
}