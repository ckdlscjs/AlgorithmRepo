#include <bits/stdc++.h>
int N, K, D, M, d, a, res, cnts[35];
std::pair<int, int> students[100'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K >> D;
  for(int i = 0; i < N; i++)
  {
    std::cin >> M >> d;
    students[i].first = d;
    for(int m = 0; m < M; m++)
    {
      std::cin >> a;
      students[i].second |= 1 << a;
    }
  }
  std::sort(students, students+N, [](const std::pair<int, int>& a, const std::pair<int, int>& b){
    return a.first <= b.first;
  });
  int l = 0, r = 0;
  while(l <= r && r < N)
  {
    while(students[r].first - students[l].first > D)
    {
      for(int i = 1; i <= K; i++)
        if(students[l].second & 1 << i)
          cnts[i]--;
      l++;
    }
    int cnt = 0;
    for(int i = 1; i <= K; i++)
      if(students[r].second & 1 << i) cnts[i]++;
    for(int i = 1; i <= K; i++)
      if(0 < cnts[i] && cnts[i] < r-l+1) cnt++;
    res = std::max(res, cnt*(r-l+1));
    r++;
  }
  std::cout << res;
  return 0;
}