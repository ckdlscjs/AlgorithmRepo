#include <bits/stdc++.h>
int N, val1, val2, A[105], B[105];
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
  {
    std::cin >> val1 >> val2;
    A[val1]++;
    B[val2]++;
    int res = 0, tempA[105], tempB[105], aidx = 1, bidx = 100;
    std::memcpy(tempA, A, sizeof(tempA));
    std::memcpy(tempB, B, sizeof(tempB));
    while(aidx <= 100 && 1 <= bidx)
    {
      while(tempA[aidx] == 0 && aidx <= 100) aidx++;
      while(tempB[bidx] == 0 && 1<= bidx) bidx--;
      if(aidx > 100 || bidx <= 0) break;
      res = std::max(res, aidx + bidx);
      if(tempA[aidx] >= tempB[bidx])
      {
        tempA[aidx] -= tempB[bidx];
        tempB[bidx] = 0;
      }
      else
      {
        tempB[bidx] -= tempA[aidx];
        tempA[aidx] = 0;
      }
    }
    std::cout << res << '\n';
  }
  return 0;
}