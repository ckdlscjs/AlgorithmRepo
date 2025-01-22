#include <bits/stdc++.h>
int N, K, P, arr[10'005], cnts[10'005], dp[10'005], res;
std::vector<int> graph[10'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 1; n <= N; n++)
  {
    std::cin >> arr[n];
    std::cin >> K;
    for(int k = 0; k < K; k++)
    {
      std::cin >> P;
      graph[P].push_back(n);
      cnts[n]++;
    }
  }
  std::queue<int> q;
  for(int n = 1; n <= N; n++)
  {
    if(cnts[n] == 0)
    {
      q.push(n);
      dp[n] = arr[n];
    }
  }
      
  for(int n = 1; n <= N; n++)
  {
    int cur = q.front();
    q.pop();
    res = std::max(res, dp[cur]);
    for(const auto& iter : graph[cur])
    {
      cnts[iter]--;
      dp[iter] = std::max(dp[iter], dp[cur] + arr[iter]);
      if(cnts[iter] <= 0)
        q.push(iter);
    }
  }
  std::cout << res;
  return 0;
}