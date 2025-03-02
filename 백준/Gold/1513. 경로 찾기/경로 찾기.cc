#include <bits/stdc++.h>
const long long int mod = 1'000'007;
int y, x;
long long int N, M, C, arr[52][52], dp[52][52][52][52];
long long int Check(int cy, int cx, int cnt, int prev) //topdown
{
  //std::cout << cy << ' ' << cx << '\n';
  if(cy > N || cx > M) return 0;
  if(cy == N && cx == M)
  {
    if(cnt == 0 && arr[cy][cx] == 0) return 1;
    if(cnt == 1 && arr[cy][cx] > prev) return 1;
    else return 0;
  }
  if(dp[cy][cx][cnt][prev] != -1) return dp[cy][cx][cnt][prev];
  dp[cy][cx][cnt][prev] = 0;
  if(arr[cy][cx] == 0) dp[cy][cx][cnt][prev] = (Check(cy+1, cx, cnt, prev) + Check(cy, cx+1, cnt, prev)) % mod;
  else if(cnt && arr[cy][cx] > prev) dp[cy][cx][cnt][prev] = (Check(cy+1, cx, cnt-1, arr[cy][cx]) + Check(cy, cx+1, cnt-1, arr[cy][cx])) % mod;
  return dp[cy][cx][cnt][prev];
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M >> C;
  for(int c = 1; c <= C; c++)
  {
    std::cin >> y >> x;
    arr[y][x] = c;
  }
  std::fill_n(&dp[0][0][0][0], 52*52*52*52, -1);
  for(int c = 0; c <= C; c++) std::cout << Check(1, 1, c, 0) << '\n';
  return 0;
}