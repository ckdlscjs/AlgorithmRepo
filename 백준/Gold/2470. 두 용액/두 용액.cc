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
  int res = INT_MAX;
  std::pair<int, int> ans;
  for(int i = 0; i < N; i++)
  {
    int l = i+1, r = N-1;
    while(l <= r)
    {
      int mid = (l+r) / 2;
      int sum = arr[i] + arr[mid];
      if(std::abs(sum) < res)
      {
        res = std::abs(sum);
        ans.first = arr[i];
        ans.second = arr[mid];
        if(res == 0)
        break;
      }
      if(sum > 0)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if(res == 0)
      break;
  }
  std::cout << ans.first << ' ' << ans.second;
  return 0;
}
