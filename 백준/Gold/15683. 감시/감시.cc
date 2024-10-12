#include <bits/stdc++.h>
using namespace std;
int N, M, res = INT_MAX;
int arr[10][10];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
std::vector<std::pair<std::pair<int, int>, std::string>> Cameras;
void Check(int (*maps)[10], int idx)
{
  if(idx >= Cameras.size())
  {
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < M; j++)
      {
        //std::cout << maps[i][j] << ' ';
        if(!maps[i][j])
          cnt++;
      }
      //std::cout << '\n';
    }
    //std::cout << '\n';
    res = std::min(res, cnt);
    return;
  }
  int y = Cameras[idx].first.first;
  int x = Cameras[idx].first.second;
  std::string dir = Cameras[idx].second;
  for(int rot = 0; rot < 4; rot++)
  {
    int temp[10][10];
    std::memcpy(temp, maps, sizeof(temp));
    for(int didx = 0; didx < dir.size(); didx++)
    {
      if(dir[didx] == '0')
        continue;
      int ny = y;
      int nx = x;
      while(0 <= ny && 0 <= nx && ny < N && nx < M)
      {
        ny += dy[didx];
        nx += dx[didx];
        if(temp[ny][nx] == 6)
          break;
        if(temp[ny][nx] != 0)
          continue;
        temp[ny][nx] = 7;
      }
    }
    Check(temp, idx+1);
    dir = dir.substr(1) + dir.substr(0,1);
  }
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  std::cin >> N >> M;
  //std::vector<std::pair<int, int>> cam5s;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 1)
        Cameras.push_back({{i, j}, "1000"});
      else if(arr[i][j] == 2)
        Cameras.push_back({{i, j}, "1010"});
      else if(arr[i][j] == 3)
        Cameras.push_back({{i, j}, "1100"});
      else if(arr[i][j] == 4)
        Cameras.push_back({{i, j}, "1110"});
      else if(arr[i][j] == 5)
        Cameras.push_back({{i, j}, "1111"});
    }
  }
  /*
  for(const auto& iter : cam5s)
  {
    for(int i = 0; i < N; i++)
    {
      if(arr[i][iter.second] == 6)
        break;
      if(i != iter.first && arr[i][iter.second] == 0)
        arr[i][iter.second] = 7;
    };
    for(int j = 0; j < M; j++)
    {
      if(arr[iter.first][j] == 6)
        break;
      if(j != iter.second && arr[iter.first][j] == 0)
        arr[iter.first][j] = 7;
    }
  }
  */
  Check(arr, 0);
  /*
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cout << arr[i][j] << ' ';
    }
    std::cout << '\n';
  }
  */
  std::cout << res;
  return 0;
}