#include <bits/stdc++.h>
using namespace std;
int N, M, K;
std::string nt, na;
std::unordered_map<std::string, std::string> na_nt;
std::unordered_map<std::string, std::set<std::string>> nt_na;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  cin >> N >> M;
  for(int n = 0; n < N; n++)
  {
    std::cin >> nt;
    std::cin >> K;
    for(int k = 0; k < K; k++)
    {
      std::cin >> na;
      nt_na[nt].insert(na);
      na_nt[na] = nt;
    }
  }
  for(int m = 0; m < M; m++)
  {
    std::cin >> na >> K;
    if(K == 0)
    {
      for(const auto& iter : nt_na[na])
        std::cout << iter << '\n';
    }
    else
    {
      std::cout << na_nt[na] << '\n';
    }
  }
  return 0;
}