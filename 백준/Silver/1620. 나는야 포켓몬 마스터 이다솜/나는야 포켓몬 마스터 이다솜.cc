#include <bits/stdc++.h>
using namespace std;
int N, M;
std::unordered_map<std::string, int> input_str;
std::unordered_map<int, std::string> input_num;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  for(int i = 1; i <= N; i++)
  {
    std::string str;
    std::cin >> str;
    input_str[str] = i;
    input_num[i] = str;
  }
  for(int i = 0; i < M; i++)
  {
    std::string str;
    std::cin >> str;
    if(input_str.find(str) == input_str.end())
      std::cout << input_num[std::stoi(str)];
    else
      std::cout << input_str[str];
    std::cout <<'\n';
  }
  return 0;
}