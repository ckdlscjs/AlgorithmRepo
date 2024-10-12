#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
bool visited[55][55];
int arr[55][55];
int N, M, T, x, d, k, res;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> N >> M >> T;
  for(int i = 1; i <= N; i++)
    for(int j = 0; j < M; j++)
      std::cin >> arr[i][j];
  for(int t = 0; t < T; t++)
  {
    std::cin >> x >> d >> k;
    d = d ? M-1 : 1;
    std::queue<std::pair<int, std::pair<int, int>>> q;
    for(int m = 1; m*x <= N; m++)
    {
      int xidx = m*x;
      int temp[55];
      std::memset(temp, 0, sizeof(temp));
      for(int j = 0; j < M; j++) temp[(j+k*d) % M] = arr[xidx][j];
      for(int j = 0; j < M; j++) arr[xidx][j] = temp[j];
    }
    int sum = 0;
    std::vector<std::pair<int, int>> nums;
    bool chk = false;
    for(int i = 1; i <= N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        if(!arr[i][j])
          continue;
        q.push({arr[i][j], {i, j}});
        sum += arr[i][j];
        nums.push_back({i, j});
      }
    }
    while(q.size())
    {
      int value = q.front().first;
      int y = q.front().second.first;
      int x = q.front().second.second;
      q.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(nx < 0)
          nx = M-1;
        if(nx >= M)
          nx = 0;
        if(ny <= 0 || ny > N || visited[ny][nx] || arr[ny][nx] != value)
          continue;
        chk = true;
        visited[ny][nx] = true;
        q.push({value, {ny, nx}});
        arr[ny][nx] = arr[y][x] = 0;
      }
    }
    if(!chk)
    {
      for(const auto& iter : nums)
      {
        if(arr[iter.first][iter.second] && arr[iter.first][iter.second] > sum / (float)nums.size())
          arr[iter.first][iter.second] -= 1;
        else if(arr[iter.first][iter.second] && arr[iter.first][iter.second] < sum / (float)nums.size())
          arr[iter.first][iter.second] += 1;
      }
    }
    std::memset(visited, false, sizeof(visited));
  }
  for(int i = 1; i <= N; i++)
    for(int j = 0; j < M; j++)
      res += arr[i][j];
  std::cout << res;
  return 0;
}