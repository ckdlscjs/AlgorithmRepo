#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, m, k;
  std::cin >> n >> m;
  int left = 1;
  int right = left + m - 1;;
  std::cin >> k;
  int result = 0;
  for(int i = 0; i < k; i++)
  {
    int j;
    std::cin >> j;
    if(left <= j && j <= right)
      continue;
    if(j < left)
    {
      int diff = left - j;
      left -= diff;
      right -= diff;
      result += diff;
    }
    else if(j > right)
    {
      int diff = j - right;
      left += diff;
      right += diff;
      result += diff;
    }
  }
  std::cout << result;
  return 0;
}