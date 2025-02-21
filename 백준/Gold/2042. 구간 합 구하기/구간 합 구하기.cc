#include <bits/stdc++.h>
long long int N, M, K, arr[1'000'005], trees[1'000'005 * 4], a, b, c;
long long int init(int s, int e, int cur)
{
  if(s >= e) return trees[cur] = arr[s];
  int mid = (s + e) /2;
  return trees[cur] = init(s, mid, cur*2) + init(mid+1, e, cur*2+1);
}
void update(int s, int e, int idx, int cur, long long int diff)
{
  if(idx < s || e < idx) return;
  trees[cur] += diff;
  if(s == e) return;
  int mid = (s + e) / 2;
  update(s, mid, idx, cur*2, diff);
  update(mid+1, e, idx, cur*2+1, diff);
}
long long int sum(int s, int e, int l, int r, int cur)
{
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return trees[cur];
  int mid = (s+e) / 2;
  return sum(s, mid, l, r, cur*2) + sum(mid+1, e, l, r, cur*2+1);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int n = 1; n <= N; n++) std::cin >> arr[n];
  init(1, N, 1);
  for(int m = 0; m < M + K; m++)
  {
    std::cin >> a >> b >> c;
    if(a == 1)
    {
      long long int diff = c-arr[b];
      arr[b] = c;
      update(1, N, b, 1, diff);
    }
    else
    {
      std::cout << sum(1, N, b, c, 1) << '\n';
    }
  }
  
  return 0;
}
