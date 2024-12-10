#include <bits/stdc++.h>
using namespace std;
int N, A[55], B[55], res;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++) std::cin >> A[i];
  std::sort(A, A+N);
  for(int i = 0; i < N; i++) std::cin >> B[i];
  std::sort(B, B+N, std::greater<>());
  for(int i = 0; i < N; i++)
    res += A[i] * B[i];
  std::cout << res;
  return 0;
}