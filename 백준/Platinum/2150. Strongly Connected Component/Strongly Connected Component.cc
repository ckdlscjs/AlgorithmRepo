#include <bits/stdc++.h>
int V, E, u, v;
std::vector<int> graphUV[10'005];
std::vector<int> graphVU[10'005];
std::stack<int> st;
std::vector<std::vector<int>> sccs;
bool visited[10'005];
void dfsUV(int cur)
{
  visited[cur] = true;
  for(const auto& iter : graphUV[cur])
  {
    if(visited[iter]) continue;
    dfsUV(iter);
  }
  st.push(cur);
}
void dfsVU(int cur)
{
  visited[cur] = false;
  sccs[sccs.size()-1].push_back(cur);
  for(const auto& iter : graphVU[cur])
  {
    if(!visited[iter]) continue;
    dfsVU(iter);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> V >> E;
  for(int e = 0; e < E; e++)
  {
    std::cin >> u >> v;
    graphUV[u].push_back(v);
    graphVU[v].push_back(u);
  }
  for(int i = 1; i <= V; i++)
    if(!visited[i]) 
      dfsUV(i);
  while(st.size())
  {
    int cur = st.top();
    st.pop();
    if(!visited[cur]) continue;
    sccs.push_back(std::vector<int>());
    dfsVU(cur);
    std::sort(sccs[sccs.size()-1].begin(), sccs[sccs.size()-1].end());
    sccs[sccs.size()-1].push_back(-1);
  }
  std::sort(sccs.begin(), sccs.end(), [](const std::vector<int>& a, const std::vector<int>& b) -> bool {
    return a[0] < b[0];
  });
  std::cout << sccs.size() <<'\n';
  for(int i = 0; i < sccs.size(); i++)
  {
    for(const auto& iter : sccs[i])
      std::cout << iter << ' ';
    std::cout << '\n';
  }
  return 0;
}