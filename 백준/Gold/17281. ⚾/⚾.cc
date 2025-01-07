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
      std::queue<int> q;
      while(out < 3)
      {
        int cur = arr[i][order[idx++]];
        if(idx >= 9)
          idx = 0;
        if(cur == 0)
        {
          out++;
        }
        else
        {
          int len = q.size();
          for(int j = 0; j < len; j++)
          {
            int p = q.front();
            q.pop();
            p += cur;
            if(p >= 4)
              temp++;
            else
              q.push(p);
          }
          if(cur <= 3)
            q.push(cur);
          else
            temp++;
        }
      }
    }
    res = std::max(res, temp);
  }while(std::next_permutation(ps, ps+8));
  std::cout << res;
  return 0;
}