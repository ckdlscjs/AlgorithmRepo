#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int MaxN = 1505;
char arr[MaxN][MaxN];
bool visit_swan[MaxN][MaxN];
bool visit_water[MaxN][MaxN];
int r, c, LIdx;
std::pair<int, int> L[2];
std::queue<std::pair<int, int>> move_swan, next_swan;
std::queue<std::pair<int, int>> expand_water, next_water;
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
    for(int j = 0; j < c; j++)
    {
      arr[i][j] = str[j];
      if(arr[i][j] == 'L')
      {
        L[LIdx++] = std::make_pair(i, j);
      }
      if(arr[i][j] == '.' || arr[i][j] == 'L') //백조가있는공간도 Water
      {
        expand_water.push({i, j});
        visit_water[i][j] = true;
      }
    }
  }
  move_swan.push(L[0]);
  visit_swan[L[0].first][L[0].second] = true;
  int cnt = 0;
  while(!visit_swan[L[1].first][L[1].second])
  {
    while(move_swan.size())
    {
      int y = move_swan.front().first;
      int x = move_swan.front().second;
      move_swan.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visit_swan[ny][nx])
          continue;
        visit_swan[ny][nx] = true;
        if(arr[ny][nx] == '.')
          move_swan.push({ny, nx});
        else
          next_swan.push({ny, nx});
      }
    }
    if(visit_swan[L[1].first][L[1].second])
      continue;
    
    while(expand_water.size())
    {
      int y = expand_water.front().first;
      int x = expand_water.front().second;
      expand_water.pop();
      for(int dir = 0; dir < 4; dir++)
      {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c || visit_water[ny][nx] || arr[ny][nx] != 'X')
          continue;
        visit_water[ny][nx] = true;
        next_water.push({ny, nx});
        arr[ny][nx] = '.';
      }
    }
    while(next_swan.size())
    {
      move_swan.push(next_swan.front());
      next_swan.pop();
    }
    while(next_water.size())
    {
      expand_water.push(next_water.front());
      next_water.pop();
    }
    cnt++;
  }
  
  std::cout << cnt;
  return 0;
}