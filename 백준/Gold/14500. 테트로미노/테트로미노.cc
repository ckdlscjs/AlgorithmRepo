#include <bits/stdc++.h>
using namespace std;
int N, M, arr[505][505], res;
std::vector<std::vector<std::vector<int>>> blocks;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  blocks.push_back({{1, 1, 1, 1}});
  blocks.push_back({{1}, {1}, {1}, {1}});
  
  blocks.push_back({{1, 1}, {1, 1}});
  
  blocks.push_back({{1, 0}, {1, 0}, {1, 1}});
  blocks.push_back({{1, 1, 1}, {1, 0, 0}});
  blocks.push_back({{1, 1}, {0, 1}, {0, 1}});
  blocks.push_back({{0, 0, 1}, {1, 1, 1}});
  blocks.push_back({{0, 1}, {0, 1}, {1, 1}});//rev
  blocks.push_back({{1, 0, 0}, {1, 1, 1}});
  blocks.push_back({{1, 1}, {1, 0}, {1, 0}});
  blocks.push_back({{1, 1, 1}, {0, 0, 1}});
  
  blocks.push_back({{1, 0}, {1, 1}, {0, 1}});
  blocks.push_back({{0, 1, 1}, {1, 1, 0}});
  blocks.push_back({{0, 1}, {1, 1}, {1, 0}});//rev
  blocks.push_back({{1, 1, 0}, {0, 1, 1}});
  
  blocks.push_back({{1, 1, 1}, {0, 1, 0}});
  blocks.push_back({{0, 1}, {1, 1}, {0, 1}});
  blocks.push_back({{0, 1, 0}, {1, 1, 1}});
  blocks.push_back({{1, 0}, {1, 1}, {1, 0}});
  
  std::cin >> N >> M;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < M; j++)
      std::cin >> arr[i][j];
      
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < M; j++)
    {
      for(const auto& iter : blocks)
      {
        int temp = 0;
        int h = iter.size();
        int w = iter[0].size();
        if(i + h > N || j + w > M) continue;
        for(int ii = 0; ii < h; ii++)
        {
          for(int jj = 0; jj < w; jj++)
          {
            if(iter[ii][jj] == 1)
              temp += arr[ii+i][jj+j];
          }
        }
        res = std::max(res, temp);
      }
    }
  }
  std::cout << res;
  return 0;
}