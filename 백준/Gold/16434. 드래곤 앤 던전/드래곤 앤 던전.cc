#include <bits/stdc++.h>
using namespace std;
long long int N, Hatk;
struct d
{
  long long int t;
  long long int a;
  long long int h;
};
d dungeons[123'460];
bool Check(long long int maxHP)
{
  long long int curAtk = Hatk;
  long long int curHP = maxHP;
  for(int i = 0; i < N; i++)
  {
    if(dungeons[i].t == 1)
    {
      long long int cntP = dungeons[i].h / curAtk + (dungeons[i].h % curAtk ? 1 : 0);
      long long int cntE = curHP / dungeons[i].a + (curHP % dungeons[i].a ? 1 : 0);
      if(cntE < cntP)
        return false;
      curHP -= dungeons[i].a * (cntP - 1);
    }
    else
    {
      curAtk += dungeons[i].a;
      curHP = std::min(maxHP, curHP + dungeons[i].h);
    }
  }
  return true;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> Hatk;
  for(int i = 0; i < N; i++)
    std::cin >> dungeons[i].t >> dungeons[i].a >> dungeons[i].h;
  long long int lo = 0, hi = 1'000'000'000'000'000'005;
  while(lo + 1 < hi)
  {
    long long int mid = (lo + hi) / 2;
    if(Check(mid)) hi = mid;
    else lo = mid;
  }
  std::cout << hi;
  return 0;
}