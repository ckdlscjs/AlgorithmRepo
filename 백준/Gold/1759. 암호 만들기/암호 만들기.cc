#include <bits/stdc++.h>
using namespace std;
int L, C;
char arr[20];
void Check(int idx, int cnt, int mask, int vowel, int consonant, char* word)
{
  if(idx > C)
    return;
  if(cnt >= L)
  {
    if(vowel < 1 || consonant < 2)
      return;
    for(int i = 0; i < cnt; i++)
      std::cout << word[i];
    std::cout << '\n';
    return;
  }
  bool chk = false;
  if(arr[idx] == 'a' || arr[idx] == 'e' || arr[idx] == 'i' || arr[idx] == 'o' || arr[idx] == 'u')
    chk = true;
  word[cnt] = arr[idx];
  Check(idx+1, cnt+1, mask | (1 << idx), vowel + (chk ? 1 : 0), consonant + (chk ? 0 : 1), word);
  Check(idx+1, cnt, mask, vowel, consonant, word);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> L >> C;
  for(int i = 0; i < C; i++) 
    std::cin >> arr[i];
  std::sort(arr, arr+C, std::less<>());
  char word[20];
  Check(0, 0, 0, 0, 0, word);
  return 0;
}