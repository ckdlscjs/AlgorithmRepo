#include <bits/stdc++.h>
int L;
std::string N;
std::vector<int> makeTable(const std::string& pattern)
{
  std::vector<int> table(pattern.size(), 0);
  int j = 0;
  for(int i = 1; i < pattern.size(); i++)
  {
    while(j > 0 && pattern[i] != pattern[j])
      j = table[j-1];
    if(pattern[i] == pattern[j])
      table[i] = ++j;
  }
  return table;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> L >> N;
  std::vector<int> table = makeTable(N);
  std::cout << L - table[L-1];
  return 0;
}
