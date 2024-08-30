#include <bits/stdc++.h>
using namespace std;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
  int win[3] = {0, 0, 0};
  int times[3] = {0, 0, 0};
  int prev = 0;
  for(int i = 0; i < n; i++)
  {
    int team = 0, goaltime = 0;
    std::string goal;
    std::cin >> team >> goal;
    std::string cur;
    for(const auto& iter : goal)
    {
      if('0' <= iter && iter <= '9')
        cur += iter;
      else
      {
        goaltime += 60 * std::stoi(cur);
        cur.clear();
      }
    }
    goaltime += std::stoi(cur);
    if(win[1] > win[2])
      times[1] += goaltime - prev;
    else if(win[2] > win[1])
      times[2] += goaltime - prev;
    prev = goaltime;
    win[team]++;
  }
  if(win[1] > win[2])
    times[1] += 48*60 - prev;
  else if(win[2] > win[1])
    times[2] += 48*60 - prev;
  for(int idx = 1; idx <= 2; idx++)
  {
    std::string hour = std::to_string(times[idx] / 60);
      if(hour.size() <= 1)
        hour = "0" + hour;
    std::string minute = std::to_string(times[idx] % 60);
      if(minute.size() <= 1)
        minute = "0" + minute;
    std::cout << hour << ":" << minute << '\n';
  }
  return 0;
}