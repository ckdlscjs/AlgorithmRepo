#include <bits/stdc++.h>
using namespace std;
int N, M;
void Check(int idx, int cnt, int* arr)
{
  if(cnt >= M)
  {
    for(int i = 0; i < cnt; i++)
      std::cout << *(arr+i) << ' ';
    std::cout << '\n';
    return;
  }
  for(int i = idx; i <= N; i++)
  {
    arr[cnt] = i;
    Check(i, cnt+1, arr);
  }
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N >> M;
  int arr[10];
  Check(1, 0, arr);
  return 0;
}