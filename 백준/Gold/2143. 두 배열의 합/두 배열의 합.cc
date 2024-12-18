#include <bits/stdc++.h>
int T, N, M, A[1'005], B[1'005];
long long int res = 0;
std::vector<int> psumsA, psumsB;

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> T;
  std::cin >> N;
  for (int i = 1; i <= N; i++) {
    std::cin >> A[i];
    psumsA.push_back(A[i]);
    A[i] += A[i - 1];
  }
  for (int len = N; len >= 2; len--)
    for (int i = N; i - len >= 0; i--)
      psumsA.push_back(A[i] - A[i - len]);

  std::cin >> M;
  for (int i = 1; i <= M; i++) {
    std::cin >> B[i];
    psumsB.push_back(B[i]);
    B[i] += B[i - 1];
  }
  for (int len = M; len >= 2; len--)
    for (int i = M; i - len >= 0; i--)
      psumsB.push_back(B[i] - B[i - len]);

  std::sort(psumsA.begin(), psumsA.end());
  std::sort(psumsB.begin(), psumsB.end());

  int p1 = 0, p2 = psumsB.size() - 1;
  while (p1 < psumsA.size() && p2 >= 0) {
    int sum = psumsA[p1] + psumsB[p2];
    if (sum == T) {
      // psumsA[p1]의 동일한 값 개수
      int countA = 1, countB = 1;
      while (p1 + 1 < psumsA.size() && psumsA[p1] == psumsA[p1 + 1]) {
        p1++;
        countA++;
      }
      // psumsB[p2]의 동일한 값 개수
      while (p2 - 1 >= 0 && psumsB[p2] == psumsB[p2 - 1]) {
        p2--;
        countB++;
      }
      // 조합의 개수 더하기
      res += 1LL * countA * countB;
      p1++;
      p2--;
    } else if (sum < T) {
      p1++;
    } else {
      p2--;
    }
  }

  std::cout << res;
  return 0;
}