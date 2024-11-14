#include <bits/stdc++.h>
using namespace std;
int T, N, sum, arr[100'005];
bool visited[100'005], finished[100'005];
void DFS(int cur)
{
  visited[cur] = true;
  if(!visited[arr[cur]])
  {
    DFS(arr[cur]);
  }
  else if(!finished[arr[cur]])
  {
    for(int i = arr[cur]; i != cur; i = arr[i]) sum++;
    sum++;
  }
  finished[cur] = true;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N;
    for(int i = 1; i <= N; i++)
    {
      std::cin >> arr[i];
      visited[i] = false;
      finished[i] = false;
    }
      
    for(int i = 1; i <= N; i++)
    {
      if(visited[i]) continue;
      DFS(i);
    }
    std::cout << N - sum << '\n';
    sum = 0;
  }
  return 0;
}