#include <bits/stdc++.h>
using namespace std;
int N;
double multis[10'005], arr[10'005], res;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  arr[0] = multis[0] = 1.0;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> arr[i];
    multis[i] = std::max(multis[i-1] * arr[i], arr[i]);
    res = std::max(res, multis[i]);
  }
  res = std::round(res*1000) / 1000;
  std::cout << fixed << setprecision(3) << res;
  return 0;
}