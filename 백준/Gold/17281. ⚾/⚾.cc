#include <bits/stdc++.h>
int N, arr[55][11], res;
int ps[] = {2,3,4,5,6,7,8,9};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    for(int j = 1; j <= 9; j++)
      std::cin >> arr[i][j];
  do
  {
    int order[] = {ps[0], ps[1], ps[2], 1, ps[3], ps[4], ps[5], ps[6], ps[7]};
    int temp = 0;
    int idx = 0;
    for(int i = 0; i < N; i++)
    {
      int out = 0;
      bool chks[10];
      std::memset(chks, true, sizeof(chks));
      std::queue<std::pair<int, int>> q;
      while(out < 3)
      {
        int player = order[idx++];
        idx %= 9;
        int cur = arr[i][player];
        if(!chks[player]) 
          continue;
        if(cur == 0)
        {
          out++;
        }
        else
        {
          int len = q.size();
          if(cur <= 3)
          {
            q.push({cur, player});
            chks[player] = false;
          }
          else
            temp++;
          for(int j = 0; j < len; j++)
          {
            auto iter = q.front();
            q.pop();
            iter.first += cur;
            if(iter.first >= 4)
            {
              temp++;
              chks[iter.second] = true;
            }
            else
              q.push(iter);
          }
        }
      }
    }
    res = std::max(res, temp);
  }while(std::next_permutation(ps, ps+8));
  std::cout << res;
  return 0;
}