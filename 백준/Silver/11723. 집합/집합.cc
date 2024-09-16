#include <bits/stdc++.h>
int n;
int s;
void Order(const std::string& order)
{
  int num;
  if(order == "add")
  {
    std::cin >> num;
    s |= 1 << num;
  }
  if(order =="remove")
  {
    std::cin >> num;
    s &= ~(1 << num);
  }
  if(order == "check")
  {
    std::cin >> num;
    std::cout << ((s & 1 << num) ? 1 : 0) << '\n';
  }
  if(order == "toggle")
  {
    std::cin >> num;
    s ^= 1 << num;
  }
  if(order == "all")
  {
    s = 2097151;
  }
  if(order == "empty")
  {
    s = 0;
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    std::string order;
    std::cin >> order;
    Order(order);
  }
  return 0;
}