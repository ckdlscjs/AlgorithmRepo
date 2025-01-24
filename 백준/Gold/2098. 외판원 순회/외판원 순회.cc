#include <bits/stdc++.h>
const int INF = 987654321;
int N, W[17][17], costs[17][1<<17];
int Check(int cur, int mask)
{
  if(mask == (1 << N) - 1)
    return W[cur][0] ? W[cur][0] : INF;
  int& ret = costs[cur][mask];
  if(ret != -1) return ret;
  ret = INF;
  for(int i = 0; i < N; i++)
  {
    if(mask & (1 << i)) continue;
    if(!W[cur][i]) continue;
    ret = std::min(ret, Check(i, mask | 1 << i) + W[cur][i]);
  }
  return ret;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> W[i][j];
  std::fill_n(&costs[0][0], 17 * 1 << 17, -1);
  std::cout << Check(0, 1);
  return 0;
}