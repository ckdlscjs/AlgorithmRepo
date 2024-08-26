#include <bits/stdc++.h>
using namespace std;
std::vector<int> inputs;
std::vector<int> result;
void check(std::vector<int> results, int idx, int sum)
{
  if(results.size() >= 7)
  {
    if(sum == 100)
      result = results;
    return; 
  }
  for(int i = idx; i < inputs.size(); i++)
  {
    if(sum + inputs[i] > 100)
      return;
    results.push_back(inputs[i]);
    check(results, i+1, sum + inputs[i]);
    results.pop_back();
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 0; i < 9; i++)
  {
    int input;
    std::cin >> input;
    inputs.push_back(input);
  }
  std::sort(inputs.begin(), inputs.end(), std::less<>());
  check({}, 0, 0);
  for(const auto& iter : result)
    std::cout << iter <<'\n';

  return 0;
}