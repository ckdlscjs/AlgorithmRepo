#include <bits/stdc++.h>
using namespace std;
int T, k;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    char Q;
    std::cin >> k;
    int val = 0;
    std::multiset<int> q;
    for(int i = 0; i < k; i++)
    {
      std::cin >> Q >> val;
      if(Q == 'I')
      {
        q.insert(val);
      }
      else
      {
        if(q.size() <= 0) continue;
        if(val == 1)
        {
          q.erase(--q.end());
        }
        else
        {
          q.erase(q.begin());
        }
      }
    }
    if(q.size() <= 0)
    {
      std::cout << "EMPTY" << '\n';
    }
    else
    {
      std::cout << *q.rbegin() << ' ' << *q.begin() << '\n';
    }
  }
  
  return 0;
}