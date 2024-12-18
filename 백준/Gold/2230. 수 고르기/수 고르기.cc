#include <bits/stdc++.h>
int N, M, arr[100'005], ans = INT_MAX;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  std::sort(arr, arr+N);
  int l = 0, r = 0;
  while(l < N && r < N)
  {
    int temp = arr[r] - arr[l];
    if(temp < M) r++;
    else
    {
        ans = std::min(ans, std::abs(temp));
        l++;
    }
  }
  std::cout << ans;
  return 0;
}