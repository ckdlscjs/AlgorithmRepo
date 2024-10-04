#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int arr[105];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
      std::cin >> arr[i];
    std::set<int> uses;
    for(int i = 0; i < k; i++)
    {
      if(uses.find(arr[i]) != uses.end())
        continue;
      if(uses.size() >= n)
      {
        int erase, late_idx = 0;
        for(const auto& iter : uses)
        {
          int iter_idx = k;
          for(int j = i+1; j < k; j++)
          {
            if(iter == arr[j])
            {
              iter_idx = j;
              break;
            }
          }
          if(iter_idx > late_idx)
          {
            erase = iter;
            late_idx = iter_idx;
          }
        }
        ans++;
        uses.erase(erase);
      }
      uses.insert(arr[i]);
    }
    std::cout << ans;
    return 0;
}