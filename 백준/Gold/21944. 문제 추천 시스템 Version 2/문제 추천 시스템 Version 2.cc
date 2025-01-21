#include <bits/stdc++.h>
int N, M, P, L, G, X;
std::string order;
std::pair<int, int> arr[100'005];
std::set<std::pair<int, int>> lists1;
std::set<std::pair<int, int>> lists2[105];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> P >> L >> G;
    arr[P] = std::make_pair(L, G);
    lists1.insert({L, P});
    lists2[G].insert({L, P});
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> order;
    if(order == "recommend")
    {
      std::cin >> G >> X;
      std::cout << (X == 1 ? (*lists2[G].rbegin()).second : (*lists2[G].begin()).second) << '\n';
    }
    else if(order == "recommend2")
    {
      std::cin >> X;
      std::cout << (X == 1 ? (*lists1.rbegin()).second : (*lists1.begin()).second) << '\n';
    }
    else if(order == "recommend3")
    {
      std::cin >> X >> L;
      auto iter = lists1.lower_bound({L, X});
      if(X == 1)
      {
        if(iter == lists1.end())
        {
          std::cout << -1 <<'\n';
          continue;
        }
        std::cout << iter->second << '\n';
      }
      else
      {
        if(iter == lists1.begin())
        {
          std::cout << -1 <<'\n';
          continue;
        }
        std::cout << (--iter)->second << '\n';
      }
    }
    else if(order == "add")
    {
      std::cin >> P >> L >> G;
      arr[P] = std::make_pair(L, G);
      lists1.insert({L, P});
      lists2[G].insert({L, P});
    }
    else
    {
      std::cin >> P;
      lists1.erase({arr[P].first, P});
      lists2[arr[P].second].erase({arr[P].first, P});
    }
  }
  return 0;
}