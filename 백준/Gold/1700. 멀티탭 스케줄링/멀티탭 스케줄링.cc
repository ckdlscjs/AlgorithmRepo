#include <bits/stdc++.h>
int N, K, arr[105], res;
std::set<int> uses;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> K;
  for(int i = 0; i < K; i++) std::cin >> arr[i];
  for(int i = 0; i < K; i++)
  {
    if(uses.find(arr[i]) != uses.end()) continue;
    if(uses.size() >= N)
    {
      int erase, idx_late = 0;
      for(const auto& iter : uses)
      {
        int idx = K;
        for(int j = i + 1; j < K; j++)
        {
          if(arr[j] == iter)
          {
            idx = j;
            break;
          }
        }
        if(idx > idx_late)
        {
          erase = iter;
          idx_late = idx;
        }
      }
      res++;
      uses.erase(erase);
    }
    uses.insert(arr[i]);
  }
  std::cout << res;
  return 0;
}