#include <bits/stdc++.h>
int N, M, a, b, arr[100'005], tree_max[4*100'005], tree_min[4*100'005];
int init_max(int s, int e, int cur)
{
  if(s >= e) return tree_max[cur] = arr[s];
  int mid = (s + e) / 2;
  return tree_max[cur] = std::max(init_max(s, mid, cur*2), init_max(mid+1, e, cur*2+1));
}

int init_min(int s, int e, int cur)
{
  if(s >= e) return tree_min[cur] = arr[s];
  int mid = (s + e) / 2;
  return tree_min[cur] = std::min(init_min(s, mid, cur*2), init_min(mid+1, e, cur*2+1));
}

int query_max(int l, int r, int s, int e, int cur)
{
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return tree_max[cur];
  int mid = (s + e) / 2;
  return std::max(query_max(l, r, s, mid, cur*2), query_max(l, r, mid+1, e, cur*2+1));
}
int query_min(int l, int r, int s, int e, int cur)
{
  if(r < s || e < l) return 1'000'000'005;
  if(l <= s && e <= r) return tree_min[cur];
  int mid = (s + e) / 2;
  return std::min(query_min(l, r, s, mid, cur*2), query_min(l, r, mid+1, e, cur*2+1));
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int n = 1; n <= N; n++) std::cin >> arr[n];
  init_max(1, N, 1);
  init_min(1, N, 1);
  for(int m = 0; m < M; m++)
  {
    std::cin >> a >> b;
    std::cout << query_min(a, b, 1, N, 1) << ' ' << query_max(a, b, 1, N, 1) <<'\n';
  }
  return 0;
}
