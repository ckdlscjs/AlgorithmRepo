#include <bits/stdc++.h>
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, r, c, m, s, d;
struct FB
{
  int r;
  int c;
  int m;
  int s;
  int d;
  FB(int _r, int _c, int _m, int _s, int _d) : r(_r), c(_c), m(_m), s(_s), d(_d) {}
  FB(const FB& _fb)
  {
    r = _fb.r;
    c = _fb.c;
    m = _fb.m;
    s = _fb.s;
    d = _fb.d;
  }
  FB& operator=(const FB& _fb)
  {
    r = _fb.r;
    c = _fb.c;
    m = _fb.m;
    s = _fb.s;
    d = _fb.d;
    return *this;
  }
};
std::queue<FB> q;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int i = 0; i < M; i++)
  {
    std::cin >> r >> c >> m >> s >> d;
    q.push(FB(r, c, m, s, d));
  }
  for(int k = 0; k < K; k++)
  {
    std::map<std::pair<int, int>, std::queue<FB>> FBS;
    while(q.size())
    {
      FB fb = q.front();
      q.pop();
      fb.r += dy[fb.d] * (fb.s % N);
      if(fb.r <= 0)
        fb.r += N;
      if(fb.r > N)
        fb.r -= N;
      fb.c += dx[fb.d] * (fb.s % N);
      if(fb.c <= 0)
        fb.c += N;
      if(fb.c > N)
        fb.c -= N;
      //std::cout << k << ": " <<fb.r << ' ' << fb.c << ' ' << fb.m << ' ' << fb.s << ' ' <<fb.d << '\n';
      FBS[{fb.r, fb.c}].push(fb);
    }
    for(auto& iter : FBS)
    {
      if(iter.second.size() >= 2)
      {
        FB sums(iter.first.first, iter.first.second, 0, 0, 0);
        int odd = 0, even = 0, cnt = iter.second.size();
        while(iter.second.size())
        {
          FB fb = iter.second.front();
          iter.second.pop();
          odd += fb.d % 2 ? 1 : 0;
          even += fb.d % 2 ? 0 : 1;
          sums.m += fb.m;
          sums.s += fb.s;
        }
        if((double)sums.m / 5 < 1.0f)
          continue;
        sums.m = std::floor((double)sums.m / 5);
        sums.s = std::floor((double)sums.s / cnt);
        if(odd && even)
        {
          sums.d = 1;
          q.push(sums);
          sums.d = 3;
          q.push(sums);
          sums.d = 5;
          q.push(sums);
          sums.d = 7;
          q.push(sums);
        }
        else
        {
          sums.d = 0;
          q.push(sums);
          sums.d = 2;
          q.push(sums);
          sums.d = 4;
          q.push(sums);
          sums.d = 6;
          q.push(sums);
        }
      }
      else
      {
        q.push(iter.second.front());
      }
    }
  }
  int res = 0;
  while(q.size())
  {
    res += q.front().m;
    q.pop();
  }
  std::cout << res;
  return 0;
}