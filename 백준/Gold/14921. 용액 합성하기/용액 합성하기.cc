#include <bits/stdc++.h>
int arr[100'005], N;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  int lidx = 0, ridx = N-1, sum = INT_MAX, ans =0;
  while(lidx < ridx)
  {
    int temp = arr[lidx] + arr[ridx];
    if(std::abs(temp) < sum)
    {
      sum = std::abs(temp);
      ans = temp;
      if(sum == 0)
        break;
    }
    if(temp > 0) ridx--;
    else lidx++;
  }
  std::cout << ans;
  return 0;
}