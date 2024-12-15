#include <bits/stdc++.h>
long long int N, arr[1'000'005];
std::set<int> inputs;
std::unordered_map<int, int> outputs;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> arr[i];
    inputs.insert(arr[i]);
  }
  int cnt = 0;
  for(const auto& iter : inputs)
    outputs[iter] = cnt++;
  for(int i = 0; i < N; i++)
    std::cout << outputs[arr[i]] << ' ';
}