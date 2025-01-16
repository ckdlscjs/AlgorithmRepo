#include <bits/stdc++.h>
int N;
struct Trie
{
  int level;
  std::map<std::string, Trie*> nodes;
  virtual ~Trie()
  {
    for(auto& iter : nodes)
      delete iter.second;
  }
  void Insert(const std::vector<std::string>& strs, int cur)
  {
    level = cur;
    if(cur >= strs.size()) return;
    if(nodes.find(strs[cur]) == nodes.end()) nodes[strs[cur]] = new Trie();
    nodes[strs[cur]]->Insert(strs, cur+1);
  }
  void Print()
  {
    for(const auto& iter : nodes)
    {
      for(int i = 0; i < level; i++) std::cout << "--";
      std::cout << iter.first << '\n';
      iter.second->Print();
    }
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  Trie trie;
  for(int n = 0; n < N; n++)
  {
    int M;
    std::cin >> M;
    std::vector<std::string> routes;
    for(int m = 0; m < M; m++)
    {
      std::string str;
      std::cin >> str;
      routes.push_back(str);
    }
    trie.Insert(routes, 0);
  }
  trie.Print();
  return 0;
}