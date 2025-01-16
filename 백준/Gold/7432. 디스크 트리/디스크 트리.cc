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
      for(int i = 0; i < level; i++) std::cout << ' ';
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
    std::string str;
    std::cin >> str;
    std::vector<std::string> routes;
    while(str.find('\\') != std::string::npos)
    {
      auto iter = str.find('\\');
      routes.push_back(str.substr(0, (int)iter));
      str = str.substr((int)iter+1);
    }
    routes.push_back(str);
    /*
    for(const auto& iter : routes)
      std::cout << iter << ' ';
    std::cout << '\n';
    */
    trie.Insert(routes, 0);
  }
  trie.Print();
  return 0;
}