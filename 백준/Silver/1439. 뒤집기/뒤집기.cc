#include <bits/stdc++.h>
using namespace std;
int cnt0, cnt1;
char cur;
std::string str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  cur = str[0];
  cnt0 += cur == '0' ? 1 : 0;
  cnt1 += cur == '1' ? 1 : 0;
  for(const auto& ch : str)
  {
    if(cur != ch)
    {
      cur = ch;
      cnt0 += cur == '0' ? 1 : 0;
      cnt1 += cur == '1' ? 1 : 0;
    }
  }
  std::cout << std::min(cnt0, cnt1);
  return 0;
}