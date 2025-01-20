#include <bits/stdc++.h>
int N, M, P, L;
std::set<std::pair<int, int>> trees;
std::unordered_map<int, int> inputs;
std::string order;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> P >> L;
    trees.insert({L, P});
    inputs[P] = L;
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> order;
    if(order == "recommend")
    {
      std::cin >> P;
      std::cout << (P == 1 ? (*trees.rbegin()).second : (*trees.begin()).second) << '\n';
    }
    else if(order == "solved")
    {
      std::cin >> P;
      trees.erase({inputs[P], P});
      inputs.erase(P);
    }
    else
    {
      std::cin >> P >> L;
      trees.insert({L, P});
      inputs[P] = L;
    }
  }
  return 0;
}