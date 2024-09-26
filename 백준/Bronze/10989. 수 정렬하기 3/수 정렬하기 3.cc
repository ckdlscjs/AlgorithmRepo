#include <bits/stdc++.h>
int counts[10005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    int input;
    std::cin >> input;
    counts[input]++;
  }
  for(int i = 0; i < 10005; i++)
    for(int j = 0; j < counts[i]; j++)
      std::cout << i <<'\n';
  return 0;
}