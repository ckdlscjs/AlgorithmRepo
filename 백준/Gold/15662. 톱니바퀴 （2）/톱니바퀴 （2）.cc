#include <bits/stdc++.h>
using namespace std;
int t, k;
std::vector<std::string> gears;
bool visited[1005];
void RotateGears(int idx, int rot)
{
  visited[idx] = true;
  if(!visited[idx-1] && 1 <= idx && gears[idx-1][2] != gears[idx][6])
    RotateGears(idx-1, rot * -1);
  if(!visited[idx+1] && idx < gears.size() - 1 && gears[idx][2] != gears[idx+1][6])
    RotateGears(idx+1, rot * -1);
  if(rot == 1)
    gears[idx] = gears[idx][7] + gears[idx].substr(0, 7);
  else
    gears[idx] = gears[idx].substr(1, 7) + gears[idx][0];
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> t;
  for(int i = 0; i < t; i++)
  {
    std::string str;
    std::cin >> str;
    gears.push_back(str);
  }
  std::cin >> k;
  for(int i = 0; i < k; i++)
  {
    int idx, rot;
    std::cin >> idx >> rot;
    std::memset(visited, false, sizeof(visited));
    RotateGears(idx-1, rot);
  }
  int ans = 0;
  for(int i = 0; i < t; i++)
    ans += gears[i][0] == '1' ? 1 : 0;
  std::cout << ans;
  return 0;
}