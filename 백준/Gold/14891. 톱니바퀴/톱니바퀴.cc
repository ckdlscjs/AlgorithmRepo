#include <bits/stdc++.h>
using namespace std;
std::string gear[4];
int sum, K, idx, dir;
void Rotate(int mask, int cur, int rot)
{
  if(cur < 0 || cur > 3 || mask & 1 << cur) return;
  mask |= 1 << cur;
  if(cur-1 >= 0  && gear[cur-1][2] != gear[cur][6] && !(mask & 1 << (cur-1)))
    Rotate(mask, cur-1, rot*-1);
  if(cur+1 <= 3 && gear[cur][2] != gear[cur+1][6] && !(mask & 1 << (cur+1)))
    Rotate(mask, cur+1, rot*-1);
  if(rot == 1)
  {
    gear[cur].insert(gear[cur].begin(), *gear[cur].rbegin());
    gear[cur].erase(8, 1);
  }
  else
  {
    gear[cur].insert(gear[cur].end(), *gear[cur].begin());
    gear[cur].erase(gear[cur].begin());
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i < 4; i++) std::cin >> gear[i];
  std::cin >> K;
  for(int k = 0; k < K; k++)
  {
    std::cin >> idx >> dir;
    Rotate(0, idx-1, dir);
  }
  for(int i = 0; i < 4; i++)
  {
    if(gear[i][0] == '1')
      sum |= (1 << i);
  }
  std::cout << sum;
  return 0;
}