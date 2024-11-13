#include <bits/stdc++.h>
using namespace std;
const int INF = 1'000'005;
int dist[1'000'005];
int F,S,G,U,D;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> F >> S >> G >> U >> D;
  std::fill_n(dist, 1'000'005, INF);
  dist[G] = 1;
  std::queue<int> q;
  q.push(G);
  while(q.size())
  {
    int cur = q.front();
    q.pop();
    for(const auto& iter : {cur+D, cur-U})
    {
      if(iter < 1 || iter > F || dist[iter] <= dist[cur] + 1 ) continue;
      q.push(iter);
      dist[iter] = dist[cur]+1;
    }
  }
  if(dist[S] < INF)
    std::cout << dist[S]-1;
  else
    std::cout <<"use the stairs";
  return 0;
}