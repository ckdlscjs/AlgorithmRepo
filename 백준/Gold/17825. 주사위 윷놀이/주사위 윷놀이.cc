#include <bits/stdc++.h>
using namespace std;
std::unordered_map<int, std::pair<int, std::vector<int>>> maps;
std::vector<int> arr(10, 0);
int res;
void Check(int idx, int sum, long long int mask, std::vector<int> players)
{
  if(idx >= arr.size())
  {
    res = std::max(res, sum);
    return;
  }
  for(int i = 0; i < players.size(); i++)
  {
    if(players[i] >= 32)
      continue;
    int cur = players[i];
    for(int j = 0; j < arr[idx]; j++)
    {
      if(j == 0 && maps[players[i]].second.size() >= 2)
        players[i] = maps[players[i]].second[1];
      else
        players[i] = maps[players[i]].second[0];
      if(players[i] >= 32)
        break;
    }
    if(players[i] >= 32 || !(mask & 1LL << players[i]))
    {
      mask ^= 1 << cur;
      Check(idx+1, sum + maps[players[i]].first, mask | 1LL << players[i], players);
      mask ^= 1 << cur;
    }
    players[i] = cur;
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  maps[0] = {0, {1}};
  maps[1] = {2, {2}};
  maps[2] = {4, {3}};
  maps[3] = {6, {4}};
  maps[4] = {8, {5}};
  maps[5] = {10, {6, 21}};
  maps[6] = {12, {7}};
  maps[7] = {14, {8}};
  maps[8] = {16, {9}};
  maps[9] = {18, {10}};
  maps[10] = {20, {11, 24}};
  maps[11] = {22, {12}};
  maps[12] = {24, {13}};
  maps[13] = {26, {14}};
  maps[14] = {28, {15}};
  maps[15] = {30, {16, 26}};
  maps[16] = {32, {17}};
  maps[17] = {34, {18}};
  maps[18] = {36, {19}};
  maps[19] = {38, {20}};
  maps[20] = {40, {32}};
  maps[21] = {13, {22}};
  maps[22] = {16, {23}};
  maps[23] = {19, {29}};
  maps[24] = {22, {25}};
  maps[25] = {24, {29}};
  maps[26] = {28, {27}};
  maps[27] = {27, {28}};
  maps[28] = {26, {29}};
  maps[29] = {25, {30}};
  maps[30] = {30, {31}};
  maps[31] = {35, {20}};
  maps[32] = {0, {}};
  for(int i = 0; i < 10; i++)
    std::cin >> arr[i];
  Check(0, 0, 0, {0, 0, 0, 0});
  std::cout << res;
  return 0;
}