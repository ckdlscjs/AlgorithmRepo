#include <bits/stdc++.h>
const long long int mod = 1'000'000'007;
long long int N, M, K, arr[1'000'005], trees[4*1'000'005], a, b, c;
long long int init(const int s, const int e, const int cur)
{
  if(s >= e) return trees[cur] = arr[s];
  int mid = (s + e) / 2;
  trees[cur] = (init(s, mid, cur*2) * init(mid+1, e, cur*2 + 1));
  if(trees[cur]) 
    trees[cur] %= mod;
  return trees[cur];
}
long long int update(const int s, const int e, const int cur, const int idx, long long int diff)
{
  if(idx < s || e < idx) return trees[cur];
  if(s >= e) return trees[cur] = diff;
  int mid = (s + e) / 2;
  return trees[cur] = (update(s, mid, cur*2, idx, diff) * update(mid+1, e, cur*2+1, idx, diff)) % mod;
}
long long int multiply(const int s, const int e, const int cur, const int l, const int r)
{
  if(r < s || e < l) return 1;
  if(l <= s && e <= r) return trees[cur];
  int mid = (s + e) / 2;
  long long int left = multiply(s, mid, cur*2, l, r);
  long long int right = multiply(mid+1, e, cur*2+1, l, r);
  long long int result = left * right;
  if(result)
    result %= mod;
  return result;
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
      update(1, N, 1, b, c);
      arr[b] = c;
    }
    else
    {
      std::cout << multiply(1, N, 1, b, c) << '\n';
    }
  }
  return 0;
}
