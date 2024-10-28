#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    char res[] = {'D', 'C', 'B', 'A', 'E'};
    for(int i = 0; i < 3; i ++)
    {
      int sum = 0;
      for(int j = 0; j < 4; j++)
      {
        int val;
        std::cin >> val;
        sum += val;
      }
      std::cout << res[sum] << '\n';
    }
    return 0;
}