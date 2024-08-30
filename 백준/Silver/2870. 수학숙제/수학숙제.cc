#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  std::vector<std::string> nums;
  for(int i = 0; i < n; i++)
  {
    std::string str;
    std::cin >> str;
    str+='z';
    std::string cur;
    for(const auto& iter : str)
    {
      if('0' <= iter && iter <= '9')
        cur += iter;
      else
      {
        if(cur.empty())
          continue;
        while(cur.size() && cur[0] == '0')
        {
          cur.erase(0, 1);
        }
        if(cur.empty())
          cur = "0";
        nums.push_back(cur);
        cur.clear();
      }
    }
  }
  std::sort(nums.begin(), nums.end(), [](const std::string& a, const std::string& b)
  {
    return a.size() == b.size() ? a < b : a.size() < b.size();
  });
  for(const auto& iter : nums)
    std::cout << iter <<'\n';
  return 0;
}