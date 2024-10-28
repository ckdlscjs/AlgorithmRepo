#include <bits/stdc++.h>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::map<int, int> inputs;
    for(int i = 0; i < 3; i++)
    {
      int val;
      std::cin >> val;
      inputs[val]++;
    }
    if(inputs.size() >= 3)
    {
      std::cout << (*--inputs.end()).first * 100;
    }
    else if(inputs.size() >= 2)
    {
      int val = inputs.begin()->second >= 2 ? (*inputs.begin()).first : inputs.rbegin()->first;
      std::cout << 1'000 + val * 100;
    }
    else if(inputs.size() >= 1)
    {
      std::cout << 10'000 + (--inputs.end())->first * 1000;
    }
    return 0;
}