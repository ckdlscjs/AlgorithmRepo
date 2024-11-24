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
    int size = 0, val = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> mins;
    std::priority_queue<int, std::vector<int>, std::less<int>> maxs;
    std::unordered_map<int, int> cnts;
    for(int i = 0; i < k; i++)
    {
      std::cin >> Q >> val;
      if(Q == 'I')
      {
        mins.push(val);
        maxs.push(val);
        cnts[val]++;
        size++;
      }
      else
      {
        if(size <= 0) continue;
        size--;
        if(val == 1)
        {
          while(cnts[maxs.top()] == 0)
            maxs.pop();
          cnts[maxs.top()]--;
          maxs.pop();
        }
        else
        {
          while(cnts[mins.top()] == 0)
            mins.pop();
          cnts[mins.top()]--;
          mins.pop();
        }
        while(size <= 0 && maxs.size())
          maxs.pop();
        while(size <= 0 && mins.size())
          mins.pop();
      }
    }
    if(size <= 0)
    {
      std::cout << "EMPTY" << '\n';
    }
    else
    {
      while(cnts[maxs.top()] == 0)
        maxs.pop();
      std::cout << maxs.top() << ' ';
      while(cnts[mins.top()] == 0)
        mins.pop();
      std::cout << mins.top() << '\n';
    }
  }
  
  return 0;
}