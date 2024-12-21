#include <bits/stdc++.h>
int N, M, val, st, en, cnt, ans = INT_MAX;
std::pair<int, int> arr[1'000'005];
int chks[1'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      std::cin >> val;
      arr[M * i + j].first = val;
      arr[M * i + j].second = i;
    }
  }
  std::sort(arr, arr+N*M);
  /*
  for(int i = 0; i < N*M; i++)
    std::cout << arr[i].first << ' ';
  std::cout << '\n';
  for(int i = 0; i < N*M; i++)
    std::cout << arr[i].second << ' ';
  */
  while(en < N*M)
  {
    if(!chks[arr[en].second]) cnt++;
    chks[arr[en].second]++;
    en++;
    while(cnt >= N)
    {
      ans = std::min(ans, arr[en-1].first - arr[st].first);
      chks[arr[st].second]--;
      if(!chks[arr[st].second]) cnt--;
      st++;
    }
  }
  //std::cout << '\n';
  std::cout << ans;
  return 0;
}