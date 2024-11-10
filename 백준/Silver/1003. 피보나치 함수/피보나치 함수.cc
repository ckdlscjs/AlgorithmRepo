#include <bits/stdc++.h>
int T, N;
std::unordered_map<int, std::pair<int, int>> fibos;
std::pair<int, int> Fibo(int n)
{
  if(n <= 0)
    return {1, 0};
  if(n <= 1)
    return {0, 1};
  if(fibos.find(n) != fibos.end())
    return fibos[n];
  std::pair<int, int> ret1 = Fibo(n-1);
  std::pair<int, int> ret2 = Fibo(n-2);
  ret1.first += ret2.first;
  ret1.second += ret2.second;
  fibos[n] = ret1;
  return fibos[n];
}
int main(void)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  Fibo(40);
  for(int t = 0; t < T; t++)
  {
    std::cin >> N;
    std::cout << Fibo(N).first << ' ' << Fibo(N).second<< '\n';
  }
 
  return 0;
}