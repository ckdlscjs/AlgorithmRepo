#include <bits/stdc++.h>
using namespace std;
int N, cnt = 0;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  int temp = ~N + 1;
  for(int i = 0; i < 32; i++)
    if((N & 1 << i) ^ (temp & 1 << i))
      cnt++;
  std::cout << cnt;
  return 0;
}