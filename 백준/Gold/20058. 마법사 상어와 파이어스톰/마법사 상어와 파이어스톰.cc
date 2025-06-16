#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
int N, Q, L, arr[65][65], temp[65][65], sum, res;
bool visited[65][65];
void SplitRotate(const int L, int cur, int y, int x)
{
  if(cur <= L) //rotate
  {
    for(int i = 0; i < cur; i++)
      for(int j = 0; j < cur; j++)
        temp[y+i][x+j] = arr[y+cur-1-j][x+i];
    for(int i = 0; i < cur; i++)
      for(int j = 0; j < cur; j++)
        arr[y+i][x+j] = temp[y+i][x+j];
  }
  else //split
  {
    SplitRotate(L, cur/2, y, x);
    SplitRotate(L, cur/2, y, x + cur/2);
    SplitRotate(L, cur/2, y + cur/2, x);
    SplitRotate(L, cur/2, y + cur/2, x + cur/2);
  }
}
void Calc()
{
  std::queue<std::pair<int, int>> q;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(!arr[i][j]) continue;
      int cnt = 0;
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = i + dy[dir];
        int nx = j + dx[dir];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || !arr[ny][nx]) continue;
        cnt++;
      }
      if(cnt < 3)
        q.push({i, j});
    }
  }
  while(q.size())
  {
    auto iter = q.front();
    q.pop();
    arr[iter.first][iter.second] -= 1;
  }
}
std::pair<int, int> dfs(int y, int x)
{
  std::pair<int, int> ret(1, arr[y][x]);
  visited[y][x] = true;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= N || nx >= N || !arr[ny][nx] || visited[ny][nx]) continue;
    std::pair<int, int> temp = dfs(ny, nx);
    ret.first += temp.first;
    ret.second += temp.second;
  }
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> Q;
  N = 1 << N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  for(int i = 0; i < Q; i++)
  {
    std::cin >> L;
    SplitRotate(1 << L, N, 0, 0);
    /*
    for(int ii = 0; ii < N; ii++)
    {
      for(int jj = 0; jj < N; jj++)
      {
        std::cout << arr[ii][jj] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';  
    */
    Calc();
  }
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      if(arr[i][j] == 0 || visited[i][j]) continue;
      std::pair<int, int> temp = dfs(i, j);
      sum += temp.second;
      res = std::max(res, temp.first);
    }
  }
  std::cout << sum << '\n' << res;
  return 0;
}