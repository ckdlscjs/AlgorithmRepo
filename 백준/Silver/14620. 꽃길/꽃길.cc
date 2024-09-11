#include <bits/stdc++.h>
using namespace std;
int n;
const int MaxN = 15;
const int dy[] = {0, 0, 0, 1, -1};
const int dx[] = {0, 1, -1 ,0, 0};
bool used[MaxN][MaxN];
int arr[MaxN][MaxN];
int result = 987654321;
bool ChkUsed(int y, int x)
{
  for(int dir = 0; dir < 5; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(used[ny][nx])
      return false;
  }
  return true;
}
int ToggleUsed(int y, int x, bool chk)
{
  int sum = 0;
  for(int dir = 0; dir < 5; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    used[ny][nx] = chk;
    sum += arr[ny][nx];
  }
  return sum;
}
void Check(int cnt, int sum)
{
  if(cnt >= 3)
  {
    result = std::min(result, sum);
  }
  else
  {
    for(int i = 1; i < n-1; i++)
    {
      for(int j = 1; j < n-1; j++)
      {
        if(!ChkUsed(i, j))
          continue;
        Check(cnt + 1, sum + ToggleUsed(i, j, true));
        ToggleUsed(i, j, false);
      }
    }
  }
}

int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      std::cin >> arr[i][j];
      
  Check(0, 0);
  std::cout << result;
  return 0;
}