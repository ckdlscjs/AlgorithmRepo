#include <bits/stdc++.h>
using namespace std;
int N, val;
bool lr[22], rl[22];
std::vector<std::pair<int, int>> inputs[2];
int Check(const std::vector<std::pair<int, int>>& board, int idx, int cnt)
{
  int res = 0;
  if(idx >= board.size())
    return cnt;
  int y = board[idx].first, x = board[idx].second;
  if(!lr[y-x+N] && !rl[y+x])
  {
    lr[y-x+N] = rl[y+x] = true;
    res = std::max(res, Check(board, idx+1, cnt+1));
    lr[y-x+N] = rl[y+x] = false;
  }
  res = std::max(res, Check(board, idx+1, cnt));
  return res;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      std::cin >> val;
      if(!val) continue;
      inputs[(i+j)%2].push_back({i, j});
    }
  }
  std::cout << Check(inputs[0], 0, 0) + Check(inputs[1], 0, 0);
  return 0;
}