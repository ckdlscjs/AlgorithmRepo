#include <bits/stdc++.h>
using namespace std;
int N;
char a, b, c;
std::pair<int, int> nodes[26];
void PreOrder(int cur)
{
  std::cout << (char)(cur+'A');
  if(nodes[cur].first != -1)
    PreOrder(nodes[cur].first);
  if(nodes[cur].second != -1)
    PreOrder(nodes[cur].second);
}
void InOrder(int cur)
{
  if(nodes[cur].first != -1)
    InOrder(nodes[cur].first);
  std::cout << (char)(cur+'A');
  if(nodes[cur].second != -1)
    InOrder(nodes[cur].second);
}
void PostOrder(int cur)
{
  if(nodes[cur].first != -1)
    PostOrder(nodes[cur].first);
  if(nodes[cur].second != -1)
    PostOrder(nodes[cur].second);
  std::cout << (char)(cur+'A');
  
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::fill_n(nodes, 26, std::make_pair(-1, -1));
  for(int i = 0; i < N; i++)
  {
    std::cin >> a >> b >> c;
    nodes[a-'A'].first = (b == '.' ? -1 : b-'A');
    nodes[a-'A'].second = (c == '.' ? -1 : c-'A');
  }
  PreOrder(0); std::cout << '\n';
  InOrder(0); std::cout << '\n';
  PostOrder(0);
  return 0;
}