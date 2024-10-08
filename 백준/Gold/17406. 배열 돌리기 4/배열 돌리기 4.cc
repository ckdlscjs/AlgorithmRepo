#include <bits/stdc++.h>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, r, c, s;
std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> ks;
int src[55][55];
bool used[10];
int res = 987654321;
void Check(int arr[][55], int idx)
{
  if(idx >= ks.size())
  {
    for(int i = 1; i <= n; i++)
    {
      int sum = 0;
      for(int j = 1; j <= m; j++)
          sum += arr[i][j];
      res = std::min(res, sum);
    }
    return;
  }
  for(int i = 0; i < ks.size(); i++)
  {
    if(used[i])
      continue;
    used[i] = true;
    int temp[55][55];
    std::memcpy(temp, arr, sizeof(temp));
    int ly = ks[i].first.first;
    int lx = ks[i].first.second;
    int ry = ks[i].second.first;
    int rx = ks[i].second.second;
    while(ly < ry && lx < rx)
    {
      int ny = ly, nx = lx, dir = 0;
      do
      {
        int ty = ny + dy[dir];int tx = nx + dx[dir];
        temp[ty][tx] = arr[ny][nx];
        if((ty == ly && tx == rx) || (ty == ry && tx == rx) || (ty == ry && tx == lx))
          dir++;
        ny = ty;nx = tx;
      }while(!(ny == ly && nx == lx));
      ly++;lx++;ry--;rx--;
    }
    Check(temp, idx+1);
    used[i] = false;
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      std::cin >> src[i][j];
  for(int kidx = 0; kidx < k; kidx++)
  {
    std::cin >> r >> c >> s;
    ks.push_back({{r-s, c-s},{r+s, c+s}});
  }
  Check(src, 0);
  std::cout << res;
  return 0;
}