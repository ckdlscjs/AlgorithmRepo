#include <bits/stdc++.h>
int n, m;
const int MaxN = 5;
const int dy[] = {0, 1};
const int dx[] = {1, 0};
int arr[MaxN][MaxN];
bool used[MaxN][MaxN];
int mask[MaxN];
int res;
int calc(int y, int x, int dir)
{
  int ret = 0;
  int ny = y, nx = x;
  while(ny < n && nx < m && (mask[ny] & 1 << nx ? 1 : 0) == dir)
  {
    used[ny][nx] = true;
    ret = ret* 10 + arr[ny][nx];
    ny += dy[dir];
    nx += dx[dir];
  }
  return ret;
}
void Check(int y)
{
  if(y >= n)
  {
    std::memset(used, false, sizeof(used));
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        if(used[i][j])
          continue;
        sum += calc(i, j, mask[i] & 1 << j ? 1 : 0);
      }
    }
    res = std::max(res, sum);
    return;
  }
  for(int j = 0; j < 1 << m; j++)
  {
    mask[y] = j;
    Check(y+1);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < m; j++)
    {
      arr[i][j] = str[j] - '0';
    }
  }
  Check(0);
  std::cout << res;
  return 0;
}