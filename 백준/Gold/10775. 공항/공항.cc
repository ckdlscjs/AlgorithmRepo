#include <bits/stdc++.h>
int G, P, g[100'005], cnt, parents[100'005];
int Find(int node)
{
  if(parents[node] == node) return node;
  return parents[node] = Find(parents[node]);
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cin >> G >> P;
  for(int i = 1; i <= G; i++) parents[i] = i;
  for(int p = 1; p <= P; p++) std::cin >> g[p];
  for(int p = 1; p <= P; p++)
  {
    int parent = Find(g[p]);
    //std::cout << parent << '\n';
    if(parent != 0)
    {
      parents[parent]--;
      cnt++;
    }
    else
    {
      break;
    }
  }
  std::cout << cnt;
	return 0;
}