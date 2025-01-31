#include <bits/stdc++.h>
int N, res, costs[25][25], results[25][25];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      std::cin >> costs[i][j];
      results[i][j] = costs[i][j];
    }
  }
  for(int k = 0; k < N; k++)
  {
    for(int i = 0; i < N; i++)
    {
      for(int j = 0; j < N; j++)
      {
        if(i == j || i == k || k == j) continue;
        if(costs[i][j] > costs[i][k] + costs[k][j])
        {
          std::cout << -1;
          return 0;
        }
        if(costs[i][j] == costs[i][k] + costs[k][j])
        {
          results[i][j] = 0;
        }
      }
    }
  }
  
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      res += results[i][j];
    }
  }
  std::cout << res / 2;
  return 0;
}