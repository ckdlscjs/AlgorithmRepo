#include <bits/stdc++.h>
int N, sum;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> sum;
    std::cout << "Pairs for " <<sum<<":";
    int l = 1, r = 2, cnt = 0;
    while(l < sum)
    {
      int temp = l + r;
      if(temp >= sum)
      {
        if(temp == sum)
        {
          if(cnt >= 1)
            std::cout << ",";
          std::cout << " " << l << " " << r;
          cnt++;
        }
        l++;
        r = l+1;
      }
      else
        r++;
    }
    std::cout << '\n';
  }
  return 0;
}