#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int fee[4];
  std::memset(fee, 0, sizeof(fee));
  std::cin >> fee[1] >> fee[2] >> fee[3];
  int times[105];
  std::memset(times, 0, sizeof(times));
  for(int i = 0; i < 3; i++)
  {
    int start, end;
    std::cin >> start >> end;
    for(int j = start; j < end; j++)
      times[j]++;
  }
  int sum = 0;
  for(int i = 1; i <= 100; i++)
    sum += fee[times[i]] * times[i];
  std::cout << sum;
  return 0;
}