#include <bits/stdc++.h>
int N;
std::string a, b;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> a >> b;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::cout << (a == b ? "Possible" : "Impossible") << '\n';
  }
  return 0;
}