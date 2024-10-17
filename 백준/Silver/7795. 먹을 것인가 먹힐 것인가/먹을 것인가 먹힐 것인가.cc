#include <bits/stdc++.h>
using namespace std;
int T, N, M;
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N >> M;
    int A[20'005], B[20'005];
    std::memset(A, 0, sizeof(A));
    std::memset(B, 0, sizeof(B));
    for(int i = 0; i < N; i++) std::cin >> A[i];
    for(int i = 0; i < M; i++) std::cin >> B[i]; 
    std::sort(A, A+N, std::greater<>());
    std::sort(B, B+M, std::greater<>());
    int cnt = 0, bidx = 0;
    for(int aidx = 0; aidx < N; aidx++)
    {
      if(A[aidx] > B[bidx])
      {
        cnt += M-bidx;
        continue;
      }
      while(bidx < M && A[aidx] <= B[bidx])
        bidx++;
      if(bidx >= M)
        break;
      cnt += M-bidx;
    }
    std::cout << cnt << '\n';
  }
  return 0;
}