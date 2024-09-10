#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 22;
int r, c;
char arr[MaxN][MaxN];
int dp[MaxN][MaxN];
bool visited[MaxN][MaxN];
int result = 0;
void Check(int y, int x, int cnt, int alps)
{
  result = std::max(result, cnt);
  if(dp[y][x] == alps)
    return;
  dp[y][x] = alps;
  if(cnt >= r*c)
    return;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    int use_alp = 1<<(int)(arr[ny][nx] - 'A');
    if(ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || alps & use_alp)
      continue;
    visited[ny][nx] = true;
    Check(ny, nx, cnt+1, alps | use_alp);
    visited[ny][nx] = false;
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> r >> c;
  for(int i = 0; i < r; i++)
  {
    std::string str;
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
    {
      arr[i][j] = str[j];
    }
  }
  visited[0][0] = true;
  Check(0, 0, 1, 1 << (int)(arr[0][0] - 'A'));
  std::cout << result;
  return 0;
}