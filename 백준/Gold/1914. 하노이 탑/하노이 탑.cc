#include <bits/stdc++.h>
using namespace std;
int n;
void Hanoi(int s, int d, int e, int cur)
{
  if(cur <= 0)
    return;
  Hanoi(s, e, d, cur-1);
  std::cout << s << ' ' << d << '\n';
  Hanoi(e, d, s, cur-1);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::string str = std::to_string(std::pow(2, n));
  str = str.substr(0, str.find('.'));
  *str.rbegin() -= 1;
  std::cout << str << '\n';
  if(n <= 20)
    Hanoi(1, 3, 2, n);
  return 0;
}