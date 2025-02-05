#include <bits/stdc++.h>
using namespace std;
long long int N, M;
int res;
std::string str;
std::vector<long long int> masks;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  res = N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> str >> str;
    long long int mask = 0;
    for(int i = 0; i < str.size(); i++)
    {
      long long int pos = str.size()-1-i;
      if(str[pos] == 'Y')
        mask |= (1L << pos);
    }
    masks.push_back(mask);
  }
  for(int i = 0; i < (1L << N); i++)
  {
    long long int test = 0;
    int cur = 0;
    for(int j = 0; j < N; j++)
    {
      if(i & (1L << j))
      {
        cur++;
        test |= masks[j];
      }
    }
    int cnt = 0;
    for(int j = 0; j < N; j++)
    {
      if((test & masks[j]) == masks[j])
        cnt++;
    }
    if(cnt >= N)
      res = std::min(res, cur);
  }
  std::cout << (res <= 0 ? -1 : res);
  return 0;
}