#include <bits/stdc++.h>
int N, M, psums[100'005], tree[4*100'005], cache[4*100'005], O, S, T;
void update_cache(int s, int e, int cur)
{
  if(cache[cur] % 2 == 0) return;
  tree[cur] = (e-s+1) - tree[cur];
  if(s != e)
  {
    cache[cur*2] += cache[cur];
    cache[cur*2+1] += cache[cur];
  }
  cache[cur] = 0;
}
int update(int l, int r, int s, int e, int cur)
{
  update_cache(s, e, cur);
  if(r < s || e < l) return tree[cur];
  if(l <= s && e <= r)
  {
    cache[cur] += 1;
    update_cache(s, e, cur);
    return tree[cur];
  }
  int mid = (s + e) / 2;
  return tree[cur] = update(l, r, s, mid, cur*2) + update(l, r, mid+1, e, cur*2+1);
}
int query(int l, int r, int s, int e, int cur)
{
  update_cache(s, e, cur);
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return tree[cur];
  int mid = (s + e) / 2;
  return query(l, r, s, mid, cur*2) + query(l, r, mid+1, e, cur*2+1);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> O >> S >> T;
    if(O == 0) update(S, T, 1, N, 1);
    else if(O == 1) std::cout << query(S, T, 1, N, 1) << '\n';
  }
  return 0;
}