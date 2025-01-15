#include <bits/stdc++.h>
int N, M;
std::string str;
struct Trie
{
  bool finish;
  Trie* next[26];
  Trie()
  {
    finish = false;
    for(int i = 0; i < 26; i++) next[i] = nullptr;
  }
  virtual ~Trie()
  {
    for(int i = 0; i < 26; i++)
      if(next[i])
        delete next[i];
  }
  void Insert(const std::string& str, int idx)
  {
    if(idx >= str.size())
    {
      finish = true;
      return;
    }
    int cur = str[idx]-'a';
    if(!next[cur]) next[cur] = new Trie();
    next[cur]->Insert(str, idx+1);
  }
  bool Find(const std::string& str, int idx)
  {
    if(idx >= str.size()) return true;
    int cur = str[idx] - 'a';
    if(!next[cur]) return false;
    return next[cur]->Find(str, idx+1);
  }
};
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  Trie root;
  for(int n = 0; n < N; n++)
  {
    std::cin >> str;
    root.Insert(str, 0);
  }
  int res = 0;
  for(int m = 0; m < M; m++)
  {
    std::cin >> str;
    //std::cout <<  (root.Find(str, 0) ? 1 : 0) << '\n';
    res += (root.Find(str, 0) ? 1 : 0);
  }
  std::cout << res;
  return 0;
}