#include <bits/stdc++.h>
const int dy[] = {0, 0, 1, 1, 1};
const int dx[] = {-1, 1, 0, 0, 0};
int N;
std::string str;
int arr[1005][1005];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> N;
  std::pair<int, int> head(0, 0);
  for(int i = 0; i < N; i++)
  {
    std::cin >> str;
    for(int j = 0; j < str.size(); j++)
    {
      arr[i][j] = (str[j] == '*' ? 1 : 0);
      if((head.first | head.second) == 0 && arr[i][j])
        head.first = i, head.second = j;
    }
  }
  head.first += 1;
  std::cout << head.first+1 << ' ' << head.second+1 << '\n';
  std::pair<int, int> bodys[5] = 
  {{head.first, head.second - 1},
  {head.first, head.second +1},
  {head.first + 1, head.second}, 
  {head.first + 1, head.second-1}, 
  {head.first + 1, head.second+1}};
  std::vector<int> ans;
  for(int dir = 0; dir < 5; dir++)
  {
    int cnt = 0;
    int ny = bodys[dir].first;
    int nx = bodys[dir].second;
    while(0 <= ny && 0 <= nx && ny < N && nx < N)
    {
      if(arr[ny][nx])
        cnt++;
      ny += dy[dir];
      nx += dx[dir];
    }
    ans.push_back(cnt);
  }
  for(const auto& iter : ans)
    std::cout << iter << ' ';
  return 0;
}