#include <bits/stdc++.h>
using namespace std;
int N, arr[6], T, P, res;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < 6; i++)
    std::cin >> arr[i];
  std::cin >> T >> P;
  for(int i = 0; i < 6; i++)
    res += arr[i]/T + (arr[i]%T ? 1 :0);
  std::cout << res << '\n' << N/P << ' ' << N%P;
  return 0;
}