#include <bits/stdc++.h>
int N, d, k, c, arr[33'005], chk[3'005], s, e, res, cnt;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> d >> k >> c;
  for(int i = 0; i < N; i++) std::cin >> arr[i];
  for(int i = 0; i < k; i++) arr[N + i] = arr[i];
  cnt++;
  chk[c]++;
  for(int i = s; i < k; i++)
  {
    if(chk[arr[i]] == 0) cnt++;
    chk[arr[i]]++;
  }
  e = k-1;
  while(e < N + k)
  {
    res = std::max(res, cnt);
    chk[arr[s]]--;
    if(chk[arr[s]] <= 0) cnt--;
    s++;
    e++;
    if(chk[arr[e]] == 0) cnt++;
    chk[arr[e]]++;
  }
  std::cout << res;
  return 0;
}