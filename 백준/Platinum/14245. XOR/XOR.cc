#include <bits/stdc++.h>
int N, M, arr[500'005], trees[4*500'005], cache[4*500'005], t, a, b, c;
void init(int s, int e, int cur)
{
  if(s >= e)
  {
    trees[cur] = arr[s];
    return;
  }
  int mid = (s + e) / 2;
  init(s, mid, cur*2);
  init(mid+1, e, cur*2+1);
}
void update_cache(int s, int e, int cur)
{
  if(!cache[cur]) return;
  trees[cur] ^= cache[cur];
  if(s != e)
  {
    cache[cur*2] ^= cache[cur];
    cache[cur*2+1] ^= cache[cur];
  }
  cache[cur] = 0;
}
void update(int l, int r, int val, int s, int e, int cur)
{
  update_cache(s, e, cur);
  if(r < s || e < l) return;
  if(l <= s && e <= r)
  {
    cache[cur] ^= val;
    update_cache(s, e, cur);
    return;
  }
  int mid = (s + e) / 2;
  update(l, r, val, s, mid, cur*2);
  update(l, r, val, mid+1, e, cur*2+1);
}
int query(int idx, int s, int e, int cur)
{
  update_cache(s, e, cur);
  if(idx < s || e < idx) return 0;
  if(idx <= s && e <= idx) return trees[cur];
  int mid = (s + e) / 2;
  return query(idx, s, mid, cur*2) ^ query(idx, mid+1, e, cur*2+1);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 1; n <= N; n++) std::cin >> arr[n];
  init(1, N, 1);
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> t;
    if(t == 1)
    {
      std::cin >> a >> b >> c;
      update(a+1, b+1, c, 1, N, 1);
    }
    else
    {
      std::cin >> a;
      std::cout << query(a+1, 1, N, 1) << '\n';
    }
  }
  return 0;
}
