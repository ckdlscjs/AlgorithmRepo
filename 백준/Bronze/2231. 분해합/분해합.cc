#include <bits/stdc++.h>
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  int ans = n;
  for(int i = n; i >= 0; i--)
  {
    int sum = i;
    int temp = i;
    while(temp)
    {
      sum += temp % 10;
      temp /= 10;
    }
    if(sum == n)
      ans = i;
  }
  std::cout << (ans == n ? 0 : ans);
  return 0;
}