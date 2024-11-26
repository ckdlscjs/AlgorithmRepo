#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
std::string arr[5];
bool visited[5][5];
int Check(int num, std::vector<int> combi)
{
  int ret = 0;
  if(combi.size() >= 7)
  {
    std::memset(visited, true, sizeof(visited));
    int scnt = 0, ycnt = 0;
    for(const auto& iter : combi)
    {
      int y = iter/5;
      int x = iter%5;
      scnt += arr[y][x] == 'S' ? 1 : 0;
      ycnt += arr[y][x] == 'Y' ? 1 : 0;
      visited[y][x] = false;
    }
    if(ycnt > scnt)
      return 0;
    int visitcnt = 1;
    std::queue<std::pair<int, int>> q;
    q.push({combi[0]/5, combi[0]%5});
    visited[combi[0]/5][combi[0]%5] = true;
    while(q.size())
    {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || visited[ny][nx]) 
          continue;
        visited[ny][nx] = true;
        visitcnt++;
        q.push({ny, nx});
      }
    }
    if(visitcnt < 7)
      return 0;
    return 1;
  }
  for(int i = num; i < 25; i++)
  {
    combi.push_back(i);
    ret += Check(i+1, combi);
    combi.pop_back();
  }
  return ret;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i < 5; i++)
    std::cin >> arr[i];
  std::cout << Check(0, {});
  return 0;
}