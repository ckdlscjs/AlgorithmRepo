#include <bits/stdc++.h>
int N, M, K, val1, val2, res;
std::vector<int> arr;
bool chk[400'005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> K;
  for(int i = 0; i < M + 1; i++)
  {
    std::cin >> val1 >> val2;
    chk[val1] = chk[val2] = true;
  }
  for(int i = 1; i <= 4*N; i++)
  {
    if(chk[i]) continue;
    arr.push_back(i%K);
  }
    
  std::sort(arr.begin(), arr.end());
  K = std::abs(val1%K - val2%K);
  int l = 0, r = arr.size()/2;
  while(r < arr.size())
  {
    if(arr[r] - arr[l] > K)
    {
      l++;
      r++;
      res++;
    }
    else
      r++;
    
  }
  std::cout << std::min(res, M-1);
  return 0;
}