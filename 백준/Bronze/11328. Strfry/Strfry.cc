#include <bits/stdc++.h>
int N;
std::string a, b;
int alp1[26], alp2[26];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::memset(alp1, 0, sizeof(alp1));
    std::memset(alp2, 0, sizeof(alp2));
    std::cin >> a >> b;
    for(const auto& ch : a)
      alp1[ch-'a']++;
    for(const auto& ch : b)
      alp2[ch-'a']++;
    bool chk = true;
    for(int j = 0; j < 26; j++)
      if(alp1[j] != alp2[j])
        chk = false;
    std::cout << (chk ? "Possible" : "Impossible") << '\n';
  }
  return 0;
}