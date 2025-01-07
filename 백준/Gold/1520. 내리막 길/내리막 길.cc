#include <bits/stdc++.h>
int M, N, arr[505][505], dp[505][505];
const int dy[] = {0, 0, -1, 1};
const int dx[] = {-1, 1, 0, 0};
std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::less<std::pair<int, std::pair<int, int>>>> pq;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  dp[1][1] = 1;
  std::cin >> M >> N;
  for(int i = 1; i <= M; i++)
  {
    for(int j = 1; j <= N; j++)
    {
      std::cin >> arr[i][j];
      pq.push({arr[i][j], {i, j}});
    }
  }
  while(pq.size())
  {
    auto iter = pq.top();
    pq.pop();
    int cy = iter.second.first;
    int cx = iter.second.second;
    for(int dir = 0; dir < 4; dir++)
    {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      if(arr[cy][cx] < arr[ny][nx])
        dp[cy][cx] += dp[ny][nx];
    }
  }
  std::cout << dp[M][N];
  return 0;
}