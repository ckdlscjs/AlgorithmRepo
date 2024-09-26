#include <bits/stdc++.h>
int n, m;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  std::vector<int> arr(n, 0);
  for(int i = 0; i < n; i++)
    std::cin >> arr[i];
  int ans = 0;
  for(int i = 0; i < arr.size(); i++)
  {
    for(int j = i+1; j < arr.size(); j++)
    {
      for(int k = j + 1; k < arr.size(); k++)
      {
        if(arr[i] + arr[j] + arr[k] <= m)
        {
          ans = std::max(ans, arr[i] + arr[j] + arr[k]);
        }
      }
    }
  }
  std::cout << ans;
  return 0;
}