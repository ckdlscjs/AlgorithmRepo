#include <bits/stdc++.h>
std::string str;
int M, psums[100'005], trees[4*100'005], cache[4*100'005], q, res;
int init(int s, int e, int cur)
{
  if(s >= e) return trees[cur] = psums[s];
  int mid = (s + e) / 2;
  return trees[cur] = std::min(init(s, mid, cur*2), init(mid+1, e, cur*2+1));
}
void update_cache(int s, int e, int cur)
{
  if(!cache[cur]) return;
  trees[cur] += cache[cur];
  if(s != e)
  {
    cache[cur*2] += cache[cur];
    cache[cur*2+1] += cache[cur];
  }
  cache[cur] = 0;
}
int update(int val, int l, int r, int s, int e, int cur)
{
  update_cache(s, e, cur);
  if(r < s || e < l) return trees[cur];
  if(l <= s && e <= r)
  {
    cache[cur] += val;
    update_cache(s, e, cur);
    return trees[cur];
  }
  int mid = (s + e) / 2;
  return trees[cur] = std::min(update(val, l, r, s, mid, cur*2), update(val, l, r, mid+1, e, cur*2+1));
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  for(int i = 1; i <= str.size(); i++)
  {
    psums[i] = (str[i-1] == '(' ? 1 : -1);
    psums[i] += psums[i-1];
  }
  init(1, str.size(), 1);
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> q;
    int diff = (str[q-1] == '(' ? -2 : 2);
    str[q-1] = (str[q-1] == '(' ? ')' : '(');
    psums[str.size()] += diff;
    //std::cout << str << '\n';
    if(update(diff, q, str.size(), 1, str.size(), 1) == 0 && psums[str.size()] == 0) res++;
  }
  std::cout << res;
  return 0;
}
