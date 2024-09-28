#include <bits/stdc++.h>
int n;
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n;
  std::set<int> x;
  std::set<int> y;
  for(int i = 0; i < n; i++)
  {
    int a, b;
    std::cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  if(x.size() <= 1 || y.size() <= 1)
    std::cout << 0;
  else 
    std::cout<<(*x.rbegin() - *x.begin()) * (*y.rbegin() - *y.begin());
  return 0;
}