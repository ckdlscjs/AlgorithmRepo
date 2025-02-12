#include <bits/stdc++.h>
int N;
std::string A, W, S;
std::vector<int> MakeTable(const std::string& pattern)
{
  std::vector<int> table(pattern.size(), 0);
  int j = 0;
  for(int i = 1; i < pattern.size(); i++)
  {
    while(j > 0 && pattern[i] != pattern[j])
      j = table[j-1];
    if(pattern[i] == pattern[j])
      table[i] = ++j;
  }
  return table;
}
int KMP(const std::string& parent, const std::string& pattern)
{
  int cnt = 0;
  std::vector<int> table = MakeTable(pattern);
  int j = 0;
  for(int i = 0; i < parent.size(); i++)
  {
    while(j > 0 && parent[i] != pattern[j])
      j = table[j-1];
    if(parent[i] == pattern[j])
    {
      if(j == pattern.size()-1)
      {
        cnt++;
        j = table[j];
      }
      else
        j++;
    }
  }
  return cnt;
}
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int n = 0; n < N; n++)
  {
    std::cin >> A >> W >> S;
    std::vector<int> chks;
    std::string RW = W;
    std::vector<char> chars;
    std::unordered_map<char, int> idxs;
    for(int i = 0; i < A.size(); i++)
    {
      chars.push_back(A[i]);
      idxs[A[i]] = i;
    }
    for(int i = 0; i < A.size(); i++)
    {
      if(i > 0)
        for(int j = 0; j < RW.size(); j++) RW[j] = chars[(idxs[RW[j]] + 1)%A.size()];
      int cnt = KMP(S, RW);
      if(cnt == 1) chks.push_back(i);
    }
    if(chks.empty())
    {
      std::cout << "no solution\n";
    }
    else if(chks.size() == 1)
    {
      std::cout << "unique: " << chks[0] << '\n';
    }
    else
    {
      std::cout << "ambiguous: ";
      for(const auto& iter : chks)
        std::cout << iter << ' ';
      std::cout << '\n';
    }
  }
  return 0;
}
