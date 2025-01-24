#include <bits/stdc++.h>
int N, M;
std::string password, str;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> password;
  for(int m = 0; m < M; m++)
  {
    std::cin >> str;
    if(str.size() < password.size())
    {
      std::cout << "false" << '\n';
      continue;
    }
    int idx = 0;
    for(int i = 0; i < str.size(); i++)
    {
      if(str[i] == password[idx])
        idx++;
    }
    std::cout << (idx >= N ? "true":"false") << '\n';
  }
  return 0;
}