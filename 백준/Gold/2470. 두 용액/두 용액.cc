#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  std::sort(arr, arr+N, std::less<>());
  int l = 0, r = N-1, res = INT_MAX;
  std::pair<int, int> ans;
  while(l < r)
  {
    int sum = arr[l] + arr[r];
    if(std::abs(sum) < res)
    {
      res = std::abs(sum);
      ans.first = arr[l];
      ans.second = arr[r];
      if(res == 0)
      break;
    }
    if(sum > 0)
      r--;
    else
      l++;
  }
  std::cout << ans.first << ' ' << ans.second;
  return 0;
}
