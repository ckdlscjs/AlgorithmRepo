#include <bits/stdc++.h>
int M, N, arr[10'005], sorted[10'005], cnt;
std::vector<std::string> chks;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> M >> N;
  for(int i = 0; i < M; i++)
  {
    std::string res;
    for(int j = 0; j < N; j++)
    {
      std::cin >> arr[j];
      sorted[j] = arr[j];
    }
    std::sort(sorted, sorted+N);
    int len = std::unique(sorted, sorted+N) - sorted;
    for(int j = 0; j < N; j++)
    {
      int lo = -1, hi = len;
      while(lo + 1 < hi)
      {
        int mid = (lo + hi) / 2;
        if(sorted[mid] == arr[j])
        {
          res += mid + '0';
          break;
        }
        else if(sorted[mid] < arr[j]) lo = mid;
        else hi = mid;
      }
    }
    chks.push_back(res);
  }
  for(int i = 0; i < chks.size(); i++)
    for(int j = i + 1; j < chks.size(); j++)
      if(chks[i] == chks[j]) cnt++;
  std::cout << cnt;
  return 0;
}