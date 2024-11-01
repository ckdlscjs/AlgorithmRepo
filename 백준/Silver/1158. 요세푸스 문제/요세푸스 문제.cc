#include <bits/stdc++.h>
using namespace std;
std::string input;
int N, K;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N >> K;
  std::list<int> lists;
  for(int i = 1; i <= N; i++)
    lists.push_back(i);
  std::list<int>::iterator iter = lists.begin();
  for(int i = 1; i < K; i++)
    iter++;
  std::vector<int> ans;
  while(N--)
  {
    ans.push_back(*iter);
    iter = lists.erase(iter);
    if(iter == lists.end())
      iter = lists.begin();
    for(int i = 1; i < K; i++)
    {
      iter++;
      if(iter == lists.end())
        iter = lists.begin();
    }
  }
  std::cout << '<';
  for(int i = 0; i < ans.size() - 1; i++)
    std::cout << ans[i] << ", ";
  std::cout << *ans.rbegin() <<'>';
  return 0;
}