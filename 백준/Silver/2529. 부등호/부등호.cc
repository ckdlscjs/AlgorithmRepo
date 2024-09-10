#include <bits/stdc++.h>
using namespace std;
int n;
std::vector<char> opers;
bool chkfirst = true;
std::string result;
void Check(std::string nums, int uses)
{
  if(nums.size() > n)
  {
    result = nums;
    if(chkfirst)
      std::cout << result <<'\n';
    chkfirst = false;
    return;
  }
  char ch = opers[nums.size()-1];
  for(int i = 9; i >= 0; i--)
  {
    if(uses & (1 << i))
      continue;
    if(ch == '>' && nums[nums.size()-1] - '0' < i)
      continue;
    if(ch == '<' && nums[nums.size()-1] - '0' > i)
      break;
    Check(nums + std::to_string(i), uses | 1 << i);
  }  
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    char ch;
    std::cin >> ch;
    opers.push_back(ch);
  }
  for(int i = 9; i >= 0; i--)
    Check(""+std::to_string(i), 1 << i);
  std::cout << result;
  return 0;
}