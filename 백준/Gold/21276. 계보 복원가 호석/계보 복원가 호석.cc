#include <bits/stdc++.h>
int N, M;
std::string str, A, B;
std::unordered_map<std::string, int> cnts;
std::unordered_map<std::string, std::vector<std::string>> inputs;
void TPSort()
{
  std::queue<std::string> q;
  std::vector<std::string> ancestors;
  std::map<std::string, std::vector<std::string>> childs;
  for(const auto& iter : cnts)
  {
    if(!iter.second)
    {
      q.push(iter.first);
      ancestors.push_back(iter.first);
    }
    childs[iter.first] = std::vector<std::string>();
    std::sort(inputs[iter.first].begin(), inputs[iter.first].end(), std::less<>());
  }
  std::cout << ancestors.size() << '\n';
  for(const auto& iter : ancestors) std::cout << iter << ' ';
  std::cout << '\n';
  for(const auto& iter : cnts)
  {
    auto parent = q.front();
    q.pop();
    for(const auto& nxt : inputs[parent])
    {
      cnts[nxt]--;
      if(cnts[nxt] <= 0)
      {
        childs[parent].push_back(nxt);
        q.push(nxt);
      }
    }
  }
  for(const auto& iter : childs)
  {
    std::cout << iter.first << ' '  << iter.second.size() << ' ';
    for(const auto& it : iter.second) std::cout << it << ' ';
    std::cout << '\n';
  }
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> str;
    cnts[str] = 0;
  }
  std::cin >> M;
  for(int m = 0; m < M; m++)
  {
    std::cin >> A >> B;
    cnts[A]++;
    inputs[B].push_back(A);
  }
  TPSort();
  return 0;
}