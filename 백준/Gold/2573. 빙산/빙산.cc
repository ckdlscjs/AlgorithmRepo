#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, M, bfscnt, cnt, arr[305][305];
bool visited[305][305];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  std::deque<std::pair<int, int>> dq;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j]) dq.push_back({i, j});
    }
  }
  while(dq.size() && bfscnt <= 1)
  {
    cnt++;
    std::memset(visited, false, sizeof(visited));
    bfscnt = 0;
    int len = dq.size();
    std::vector<std::pair<int, std::pair<int, int>>> amounts;
    for(int i = 0; i < len; i++)
    {
      std::pair<int, int> cur = dq.front();
      dq.pop_front();
      int amount = 0;
      for(int dir = 0; dir < 4; dir++)
      {
        if(arr[cur.first][cur.second] == 0) break;
        int ny = cur.first + dy[dir];
        int nx = cur.second + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx]) continue;
        amount++;
      }
      amounts.push_back({amount, cur});
      if(amount < arr[cur.first][cur.second])
        dq.push_back(cur);
    }
    for(const auto& iter : amounts) 
      arr[iter.second.first][iter.second.second] = std::max(0, arr[iter.second.first][iter.second.second] - iter.first);
    for(int i = 0; i < dq.size(); i++)
    {
      if(visited[dq[i].first][dq[i].second]) continue;
      bfscnt++;
      std::queue<std::pair<int, int>> q;
      visited[dq[i].first][dq[i].second] = true;
      q.push({dq[i].first, dq[i].second});
      while(q.size())
      {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
          int ny = cy + dy[dir];
          int nx = cx + dx[dir];
          if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 0 || visited[ny][nx]) continue;
          q.push({ny, nx});
          visited[ny][nx] = true;
        }
      }
    }
  }
  std::cout << (bfscnt >= 2 ? cnt : 0);
  return 0;
}