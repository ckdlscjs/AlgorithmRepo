#include <bits/stdc++.h>
int n, m, input;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  std::vector<int> a;
  std::vector<int> b;
  for(int i = 0; i < n; i++)
  {
    std::cin >> input;
    a.push_back(input);
  }
  for(int i = 0; i < m; i++)
  {
    std::cin >> input;
    b.push_back(input);
  }
  std::sort(a.begin(), a.end(), std::less<>());
  std::sort(b.begin(), b.end(), std::less<>());
  int aidx, bidx, duplecnt;
  aidx = bidx = duplecnt = 0;
  while(aidx < a.size() && bidx < b.size())
  {
    if(a[aidx] > b[bidx])
    {
      bidx++;
    }
    else if(a[aidx] < b[bidx])
    {
      aidx++;
    }
    else
    {
      aidx++;
      bidx++;
      duplecnt++;
    }
  }
  std::cout << n + m - duplecnt*2;
  return 0;
}