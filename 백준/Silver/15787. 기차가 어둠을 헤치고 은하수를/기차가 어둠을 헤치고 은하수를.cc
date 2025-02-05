#include <bits/stdc++.h>
using namespace std;
int N, M, n, i, x, t[100'005];
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> n;
    if(n == 1)
    {
      std::cin >> i >> x;
      t[i] |= (1 << (20-x));
    }
    else if(n == 2)
    {
      std::cin >> i >> x;
      if(t[i] & (1 << (20-x)))
        t[i] ^= (1 << (20-x));
    }
    else if(n == 3)
    {
      std::cin >> i;
      t[i] >>= 1;
      t[i] &= ((1 << 20)-1);
    }
    else if(n == 4)
    {
      std::cin >> i;
      t[i] <<= 1;
      t[i] &= ((1 << 20)-1);
    }
  }
  std::unordered_set<int> chks;
  for(int i = 1; i <= N; i++)
  {
    if(chks.find(t[i]) != chks.end()) continue;
    chks.insert(t[i]);
  }
  std::cout << chks.size();
  return 0;
}