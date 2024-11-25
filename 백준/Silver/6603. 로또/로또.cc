#include <bits/stdc++.h>
using namespace std;
int k, arr[15];
void Check(int idx, int cnt, int* selects)
{
  if(idx > k)
    return;
  if(cnt >= 6)
  {
    for(int i = 0; i < cnt; i++) std::cout << selects[i] << ' ';
    std::cout << '\n';
    return;
  }
  selects[cnt] = arr[idx];
  Check(idx + 1, cnt + 1, selects);
  Check(idx + 1, cnt, selects);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  while(std::cin >> k && k)
  {
    for(int i = 0; i < k; i++) std::cin >> arr[i];
    int selects[6];
    Check(0, 0,  selects);
    std::cout << '\n';
  }
  return 0;
}