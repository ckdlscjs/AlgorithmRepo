#include <bits/stdc++.h>
int N;
int arr[130][130];
std::pair<int, int> Count(int n, int y, int x)
{
  if(n <= 1)
    return {arr[y][x] ? 0 : 1, arr[y][x] ? 1 : 0};
  std::pair<int, int> lu = Count(n/2, y, x);
  std::pair<int, int> ru = Count(n/2, y, x+n/2);
  std::pair<int, int> ld = Count(n/2, y+n/2, x);
  std::pair<int, int> rd = Count(n/2, y+n/2, x+n/2);
  if(lu == ru && ru == ld && ld == rd && rd == lu && (lu.first == 0 && lu.second == 1 || lu.first == 1 && lu.second == 0))
    return lu;
  else
    return {lu.first + ru.first + ld.first + rd.first, lu.second + ru.second + ld.second + rd.second};
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> arr[i][j];
  std::pair<int, int> res = Count(N, 0, 0);
  std::cout << res.first <<'\n'<< res.second;
    
  return 0;
}