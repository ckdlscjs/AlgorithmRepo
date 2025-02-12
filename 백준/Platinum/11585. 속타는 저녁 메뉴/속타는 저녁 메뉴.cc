#include <bits/stdc++.h>
int N;
char input;
std::vector<char> eats, circle;
std::vector<int> MakeTable(const std::vector<char>& pattern)
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
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> input;
    eats.push_back(input);
  }
  for(int n = 0; n < N; n++)
  {
    std::cin >> input;
    circle.push_back(input);
  }
  std::vector<int> table = MakeTable(circle);
  int repeat = N - table[N-1];
  if(N == repeat) std::cout << 1 << '/' << N;
  else std::cout << 1 << '/' << N/(N/repeat);
  return 0;
}
