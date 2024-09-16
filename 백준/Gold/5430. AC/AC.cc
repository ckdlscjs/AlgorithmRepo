#include <bits/stdc++.h>
const int MaxN = 100005;
int arr[MaxN];
int t, n, idx, ldx, rdx;
std::string orders;
std::string nums;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);
  std::cin >> t;
  for(int tc = 0; tc < t; tc++)
  {
    std::memset(arr, 0, sizeof(arr));
    std::cin >> orders >> n >> nums;
    std::string num;
    idx = ldx = rdx = 0;
    bool error = false;
    bool flag = false;
    for(const auto& iter : nums)
    {
      if('0' <= iter && iter <= '9')
        num += iter;
      else
      {
        if(num.size())
        {
          arr[idx++] = std::stoi(num);
          num.clear();
        }
      }
    }
    rdx = idx-1;
    for(const auto& iter : orders)
    {
      if(iter == 'R')
      {
        flag = !flag;
      }
      if(iter == 'D')
      {
        if(n <= 0)
        {
          error = true;
          break;
        }
        n--;
        if(!flag)
          ldx++;
        else
          rdx--;
      }
    }
    if(error)
    {
      std::cout <<"error"<<'\n';
    }
    else
    {
      std::cout <<'[';
      if(ldx < 0 || rdx < 0 || ldx > rdx)
      {
        
      }
      else if(!flag)
      {
        for(ldx; ldx < rdx; ldx++)
          std::cout << arr[ldx] << ',';
        std::cout <<arr[ldx];
      }
      else
      {
        for(rdx; rdx > ldx; rdx--)
          std::cout << arr[rdx] <<',';
        std::cout <<arr[rdx];
      }
      std::cout<<"]\n";
    }
  }
  return 0;
}