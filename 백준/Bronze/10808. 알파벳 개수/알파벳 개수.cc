#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::string str;
  std::cin >> str;
  int alp[30];
  std::memset(alp, 0, sizeof(alp));
  for(const auto& iter : str)
    alp[iter-'a']++;
  for(int i = 0; i < 26; i++)
    std::cout << alp[i] << ' ';
  return 0;
}