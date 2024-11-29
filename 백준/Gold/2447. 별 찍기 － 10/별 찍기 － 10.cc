#include <bits/stdc++.h>
using namespace std;
int N;
void Check(int n, int y, int x)
{
  if((y/n) % 3 == 1 && (x/n) % 3 == 1) std::cout << ' ';
  else if(n <= 1) std::cout << '*';
  else Check(n/3, y, x);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N; j++)
    {
      Check(N, i, j);
    }
    std::cout << '\n';
  }
  return 0;
}