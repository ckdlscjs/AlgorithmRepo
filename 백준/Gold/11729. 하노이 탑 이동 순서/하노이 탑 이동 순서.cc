#include <bits/stdc++.h>
using namespace std;
int n;
void Hanoi(int s, int d, int e, int n)
{
  if(n <= 0)
    return;
  Hanoi(s, e, d, n-1);
  std::cout << s << ' ' << d << '\n';
  Hanoi(e, d, s, n-1);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::cout << (1 << n) - 1 << '\n';
  Hanoi(1, 3, 2, n);
  
  return 0;
}