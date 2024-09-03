#include <bits/stdc++.h>
using namespace std;
const int MaxN = 55;
int n, m;
int arr[MaxN][MaxN];
std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> chicken;
int result = 987654321;
void Check(std::vector<std::pair<int, int>> chics, int idx)
{
  if(chics.size() >= m)
  {
    int temp = 0;
    for(const auto& iter : house)
    {
      int mindist = 987654321;
      for(const auto& chi : chics)
      {
        int dist = std::abs(iter.first - chi.first) + std::abs(iter.second - chi.second);
        mindist = std::min(mindist, dist);
      }
      temp += mindist;
    }
    result = std::min(result, temp);
    return;
  }
  for(int i = idx; i < chicken.size(); i++)
  {
    chics.push_back(chicken[i]);
    Check(chics, i+1);
    chics.pop_back();
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> n >> m;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      std::cin >> arr[i][j];
      if(arr[i][j] == 1)
        house.push_back({i, j});
      else if(arr[i][j] == 2)
        chicken.push_back({i, j});
    }
  }
  Check({}, 0);
  std::cout << result;
  return 0;
}