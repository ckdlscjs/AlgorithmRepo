#include <bits/stdc++.h>
long long int N, arr[1'000'005], sorted[1'000'005];
std::unordered_map<int, int> inputs;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    sorted[i] = arr[i];
    inputs[arr[i]] = -1;
  }
  std::sort(sorted, sorted+N);
  int cnt = 0;
  for(int i = 0; i < N; i++)
  {
    if(inputs[sorted[i]] != -1) continue;
    inputs[sorted[i]] = cnt++;
  }
  
  for(int i = 0; i < N; i++)
  {
    std::cout << inputs[arr[i]] << ' ';
  }
}