#include <bits/stdc++.h>
using namespace std;
std::string S, E, Q, chat, name;
int cs, ce, cq, t, res;
std::unordered_map<std::string, int> names;
int convert(const std::string& str)
{
  return std::atoi(str.c_str())*60 + std::atoi(str.c_str()+3);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> S >> E >> Q;
  cs = convert(S);
  ce = convert(E);
  cq = convert(Q);
  std::cin.ignore();
  while(std::getline(std::cin, chat, '\n'))
  {
    auto pos = chat.find(' ');
    t = convert(chat.substr(0, pos));
    name = chat.substr(pos+1);
    if(t <= cs)
      names[name] |= (1 << 1);
    else if(ce <= t && t <= cq)
      names[name] |= (1 << 0);
  }
  for(const auto& iter : names)
    if(iter.second == 0x03)
      res++;
  std::cout << res;
  return 0;
}