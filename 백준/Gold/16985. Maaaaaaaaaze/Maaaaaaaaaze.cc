#include <bits/stdc++.h>
using namespace std;
const int dk[] = {0, 0, 0, 0, -1, 1};
const int dy[] = {0, 0, -1, 1, 0, 0};
const int dx[] = {-1, 1, 0, 0, 0, 0};
const int INF = 987654321;
int dist[7][7][7];
int arr[5][7][7][7];
int res = INF;
void Rotate90(int idx, int k)
{
  for(int i = 0; i < 5; i++)
    for(int j = 0; j < 5; j++)
      arr[idx][k][i][j] = arr[idx-1][k][5-1-j][i];
}

void Check(int mask, int idx, std::pair<int, int>* order)
{
  if(res <= 13)
    return;
  if(idx >= 5)
  {
    std::queue<std::pair<int, std::pair<int, int>>> q;
    if(arr[order[0].first][order[0].second][0][0] == 1 && arr[order[4].first][order[4].second][4][4] == 1)
    {
      std::fill_n(&dist[0][0][0], 7 * 7 * 7, 0);
      q.push({0, {0, 0}});
      dist[0][0][0] = 1;
      while(q.size())
      {
        int ck = q.front().first;
        int cy = q.front().second.first;
        int cx = q.front().second.second;
        q.pop();
        for(int dir = 0; dir < 6; dir++)
        {
          int nk = ck + dk[dir];
          int ny = cy + dy[dir];
          int nx = cx + dx[dir];
          if(nk < 0 || ny < 0 || nx < 0 || nk >= 5 || ny >= 5 || nx >= 5 || dist[nk][ny][nx] || arr[order[nk].first][order[nk].second][ny][nx] == 0) continue;
          dist[nk][ny][nx] = dist[ck][cy][cx] + 1;
          q.push({nk, {ny, nx}});
        }
      }
      if(dist[4][4][4] > 0)
        res = std::min(res, dist[4][4][4]);
    }
    return;
  }
  for(int i = 0; i < 5; i++)
  {
    if(mask & (1 << i)) continue;
    order[idx].second = i;
    for(int rot = 0; rot < 4; rot++)
    {
      order[idx].first = rot;
      Check(mask | (1 << i), idx+1, order);
    }
  }
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int k = 0; k < 5; k++)
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 5; j++)
        std::cin >> arr[0][k][i][j];
        
  for(int rot = 1; rot < 4; rot++)
    for(int k = 0; k < 5; k++)
      Rotate90(rot, k);
 
  std::pair<int, int> order[5] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
  Check(0, 0, order);
  std::cout << (res == INF ? -1 : res - 1);
  return 0;
}