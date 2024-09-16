#include <bits/stdc++.h>
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  while(str.find("pi") != std::string::npos || str.find("ka") != std::string::npos || str.find("chu") != std::string::npos)
  { 
    if(str.find("pi") != std::string::npos)
      str.replace(str.find("pi"), 2, "..");
    else if(str.find("ka") != std::string::npos)
      str.replace(str.find("ka"), 2, "..");
    else
      str.replace(str.find("chu"), 3, "...");
  }
  for(const auto& iter : str)
  {
    if(iter == '.')
      continue;
    std::cout << "NO";
    return 0;
  }
  std::cout <<"YES";
  return 0;
}