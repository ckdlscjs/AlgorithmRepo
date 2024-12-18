#include <bits/stdc++.h>
int N, M, arr[10'005], cnt;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    std::cin >> arr[i];
    arr[i] += arr[i-1];
  }
  int l = 0, r = 1;
  while(l <= N && r <= N)
  {
    if(arr[r] - arr[l] <= M)
    {
      if(arr[r] - arr[l] == M) cnt++;
      r++;
    }
    else l++;
  }
  std::cout << cnt;
  return 0;
}