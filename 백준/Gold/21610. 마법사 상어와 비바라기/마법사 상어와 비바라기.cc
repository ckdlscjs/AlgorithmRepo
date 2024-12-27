#include <bits/stdc++.h>
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dgy[] = {-1, -1, 1, 1};
const int dgx[] = {-1, 1, -1, 1};
int N, M, arr[55][55], d, s;
std::queue<std::pair<int, int>> q;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  q.push({N-2, 0});
  q.push({N-2, 1});
  q.push({N-1, 0});
  q.push({N-1, 1});
  for(int m = 0; m < M; m++)
  {
    std::cin >> d >> s;
    std::set<std::pair<int, int>> chks;
    int len = q.size();
    for(int cnt = 0; cnt < len; cnt++)
    {
      auto cloud = q.front();
      q.pop();
      cloud.first += dy[d-1] * (s%N);
      if(cloud.first < 0) cloud.first += N;
      if(cloud.first >= N) cloud.first -= N;
      cloud.second += dx[d-1] * (s%N);
      if(cloud.second < 0) cloud.second += N;
      if(cloud.second >= N) cloud.second -= N;
      arr[cloud.first][cloud.second] += 1;
      chks.insert(cloud);
    }
    for(const auto& iter : chks)
    {
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = iter.first + dgy[dir];
        int nx = iter.second + dgx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || !arr[ny][nx]) continue;
        arr[iter.first][iter.second]++;
      }
    }
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        if(arr[i][j] < 2) continue;
        if(chks.find({i, j}) != chks.end()) continue;
        q.push({i, j});
        arr[i][j] -= 2;
      }
    }
  }
  int res = 0;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      res += arr[i][j];
  std::cout << res;
  return 0;
}