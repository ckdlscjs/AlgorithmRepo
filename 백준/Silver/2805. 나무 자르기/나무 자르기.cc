#include <bits/stdc++.h>
const int MaxN = 1000005;
int n, m, ans, left, right;
int arr[MaxN];
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
      std::cin >> arr[i];
      right = std::max(right, arr[i]);
    }
    while(left <= right)
    {
      int mid = (left + right) / 2;
      long long int sum = 0;
      for(int i = 0; i < n; i++)
      {
        if(arr[i] > mid)
          sum += arr[i] - mid;
      }
      if(sum >= m)
      {
        left = mid + 1;
        ans = std::max(ans, mid);
      }
      else
        right = mid - 1;
    }
    std::cout << ans;
    return 0;
}