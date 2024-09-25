#include <bits/stdc++.h>
int n;
int trees[100005];
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  int cur, prev;
  for(int i = 0; i < n; i++)
  {
    std::cin >> trees[i];
    if(i == 2)
    {
      cur = trees[i] - trees[i-1];
      prev = trees[i-1] - trees[i-2];
      while(cur % prev)
      {
        int temp = cur % prev;
        cur = prev;
        prev = temp;
      }
    }
    else if(i >= 3)
    {
      cur = trees[i] - trees[i-1];
      while(cur % prev)
      {
        int temp = cur % prev;
        cur = prev;
        prev = temp;
      }
    }
  }
  std::cout << ((trees[n-1] - trees[0]) / prev) - n + 1;
  
  return 0;
}