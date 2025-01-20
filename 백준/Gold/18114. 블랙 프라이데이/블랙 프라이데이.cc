#include <bits/stdc++.h>
long long int N, C, W[5005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> C;
  for(int n = 0; n < N; n++)
  {
    std::cin >> W[n];
    if(W[n] == C)
    {
      std::cout << 1;
      return 0;
    }
  }
  std::sort(W, W + N, std::less<>());
  int left = 0, right = N-1;
  while(left < right)
  {
    if(W[left] + W[right] > C)
    {
      right--;
      continue;
    }
    else if(W[left] + W[right] == C)
    {
      std::cout << 1;
      return 0;
    }
    int lo = 0, hi = N;
    while(lo + 1 < hi)
    {
      int mid = (lo + hi) / 2;
      if(W[left] + W[right] + W[mid] >= C) hi = mid;
      else lo = mid;
    }
    if(W[left] + W[right] + W[hi] == C && hi != left && hi != right)
    {
      std::cout << 1;
      return 0;
    }
    left++;
  }
  std::cout << 0;
  return 0;
}