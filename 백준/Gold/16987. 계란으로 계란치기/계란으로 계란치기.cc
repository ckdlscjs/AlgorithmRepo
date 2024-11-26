#include <bits/stdc++.h>
using namespace std;
int N, res;
std::pair<int, int> eggs[10];
void Check(int cur)
{
  if(cur >= N)
  {
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
      if(eggs[i].first <= 0)
        sum++;
    }
    res = std::max(res, sum);
    return;
  }
  if(eggs[cur].first <= 0)
    Check(cur + 1);
  else
  {
    for(int i = 0; i < N; i++)
    {
      if(i == cur || eggs[i].first <= 0) continue;
      eggs[cur].first -= eggs[i].second;
      eggs[i].first -= eggs[cur].second;
      Check(cur + 1);
      eggs[cur].first += eggs[i].second;
      eggs[i].first += eggs[cur].second;
    }
    Check(N);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> eggs[i].first >> eggs[i].second;
  Check(0);
  std::cout << res;
  return 0;
}