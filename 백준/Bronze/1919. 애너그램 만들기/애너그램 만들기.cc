#include <bits/stdc++.h>
std::string a, b;
int alp1[26], alp2[26];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> a >> b;
  for(const auto& ch : a) alp1[ch-'a']++;
  for(const auto& ch : b) alp2[ch-'a']++;
  int ans = 0;
  for(int i = 0; i < 26; i++)
    if(alp1[i] != alp2[i])
      ans += std::abs(alp1[i] - alp2[i]);
  std::cout << ans;
  return 0;
}