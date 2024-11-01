#include <bits/stdc++.h>
using namespace std;
struct Trie
{
  std::unordered_map<int, Trie*> nodes;
  void Insert(const std::string& str, int idx)
  {
    if(idx >= str.size()) return;
    if(nodes.find(str[idx]) == nodes.end())
      nodes[str[idx]] = new Trie();
    nodes[str[idx]]->Insert(str, idx+1);
  }
  bool Find(const std::string& str, int idx)
  {
    if(idx >= str.size()) return true;
    if(nodes.find(str[idx]) == nodes.end()) return false;
    return nodes[str[idx]]->Find(str, idx+1);
  }
};
int t, n;
std::string number;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> t;
  for(int test = 0; test < t; test++)
  {
    std::cin >> n;
    std::vector<std::string> strs;
    for(int i = 0; i < n; i++)
    {
      std::cin >> number;
      strs.push_back(number);
    }
    std::sort(strs.begin(), strs.end(), [](const std::string& a, const std::string& b)
    {
      return a.size() == b.size() ? a > b : a.size() > b.size();
    });
    Trie trie;
    bool chk = true;
    for(const auto& iter : strs)
    {
      if(trie.Find(iter, 0))
      {
        chk = false;
        break;
      }
      trie.Insert(iter, 0);
    }
    std::cout << (chk ? "YES" : "NO") << '\n';
  }
  return 0;
}