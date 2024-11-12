#include <bits/stdc++.h>
using namespace std;
int N, K;
int cnt[100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::fill_n(cnt, 100'005, INT_MAX);
  std::cin >> N >> K;
  std::queue<int> q;
  cnt[K] = 1;
  q.push(K);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    if(cur-1 >= 0 && cnt[cur] + 1 < cnt[cur-1] )
      q.push(cur-1), cnt[cur-1] = cnt[cur] + 1;
    if(cur+1 <= 100'000 && cnt[cur] + 1 < cnt[cur+1])
      q.push(cur+1), cnt[cur+1] = cnt[cur] + 1;
    if(cur%2 == 0 && cnt[cur] < cnt[cur/2])
      q.push(cur/2), cnt[cur/2] = cnt[cur];
  }
  std::cout << cnt[N] - 1;
  return 0;
}