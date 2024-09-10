#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 22;
int r, c;
char arr[MaxN][MaxN];
bool alps[30];
bool visited[MaxN][MaxN];
int result = 0;
void Check(int y, int x, int cnt)
{
  result = std::max(result, cnt);
  if(cnt >= r*c)
    return;
  for(int dir = 0; dir < 4; dir++)
  {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || nx < 0 || ny >= r || nx >= c || alps[arr[ny][nx] - 'A'] || visited[ny][nx])
      continue;
    alps[arr[ny][nx] - 'A'] = true;
    visited[ny][nx] = true;
    Check(ny, nx, cnt+1);
    visited[ny][nx] = false;
    alps[arr[ny][nx] - 'A'] = false;
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
  alps[arr[0][0] - 'A'] = true;
  visited[0][0] = true;
  Check(0, 0, 1);
  std::cout << result;
  return 0;
}