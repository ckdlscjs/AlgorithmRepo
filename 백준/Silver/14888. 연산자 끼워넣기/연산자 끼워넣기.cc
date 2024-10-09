#include <bits/stdc++.h>
using namespace std;
int n, arr[15], oper[5], res_min = INT_MAX, res_max = INT_MIN;
void Check(int idx, int sum)
{
  if(idx >= n)
  {
    res_min = std::min(res_min, sum);
    res_max = std::max(res_max, sum);
    return;
  }
  for(int i = 0; i < 4; i++)
  {
    if(!oper[i])
      continue;
    oper[i] -= 1;
    Check(idx+1, i == 0 ? sum + arr[idx] : i == 1 ? sum - arr[idx] : i == 2 ? sum * arr[idx] : sum / arr[idx]);
    oper[i] += 1;
  }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
      std::cin >> arr[i];
    std::cin >> oper[0] >> oper[1] >> oper[2] >> oper[3];
    Check(1, arr[0]);
    std::cout << res_max << '\n' <<res_min;
    return 0;
}