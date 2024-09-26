#include <bits/stdc++.h>
std::string str;
std::unordered_set<std::string> chk;
void check(std::string st, int idx)
{
  if(st.size())
    chk.insert(st);
  if(st.size() >= str.size() || idx >= str.size())
    return;
  check(st + str[idx], idx+1);
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> str;
  for(int i = 0; i < str.size(); i++)
    check({str[i]}, i+1);
  std::cout << chk.size();
  return 0;
}