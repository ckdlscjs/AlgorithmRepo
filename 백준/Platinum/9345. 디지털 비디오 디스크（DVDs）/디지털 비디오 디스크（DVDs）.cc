#include <bits/stdc++.h>
int T, N, K, Q, A, B;
std::pair<int, int> init(const std::vector<int>& inputs, std::vector<std::pair<int, int>>& tree, int s, int e, int cur)
{
  if(s >= e) return tree[cur] = std::make_pair(inputs[s], inputs[s]);
  int mid = (s + e) / 2;
  std::pair<int, int> left = init(inputs, tree, s, mid, cur*2);
  std::pair<int, int> right = init(inputs, tree, mid+1, e, cur*2 + 1);
  return tree[cur] = std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

std::pair<int, int> update(const int idx, const int change, std::vector<std::pair<int, int>>& tree, int s, int e, int cur)
{
  if(idx < s || e < idx) return tree[cur];
  if(s == e) return tree[cur] = std::make_pair(change, change);
  int mid = (s + e) / 2;
  std::pair<int, int> left = update(idx, change, tree, s, mid, cur*2);
  std::pair<int, int> right = update(idx, change, tree, mid+1, e, cur*2 + 1);
  return tree[cur] = std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

std::pair<int, int> query(const int l, const int r, std::vector<std::pair<int, int>>& tree, int s, int e, int cur)
{
  if(r < s || e < l) return std::make_pair(100'005, -1);
  if(l <= s && e <= r) return tree[cur];
  int mid = (s + e) / 2;
  std::pair<int, int> left = query(l, r, tree, s, mid, cur*2);
  std::pair<int, int> right = query(l, r, tree, mid+1, e, cur*2 + 1);
  return std::make_pair(std::min(left.first, right.first), std::max(left.second, right.second));
}

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> T;
  for(int t = 0; t < T; t++)
  {
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> tree(4*(N+1), {100'005, -1});
    std::vector<int> inputs(N+1, 0);
    for(int i = 1; i <= N; i++) inputs[i] = i;
    init(inputs, tree, 1, N, 1);
    for(int k = 0; k < K; k++)
    {
      std::cin >> Q >> A >> B;
      A++;
      B++;
      if(Q == 1)
      {
        std::pair<int, int> result = query(A, B, tree, 1, N, 1);
        if(result.first == A && result.second == B)
          std::cout << "YES";
        else
          std::cout << "NO";
        std::cout << '\n';
      }
      else
      {
        update(A, inputs[B], tree, 1, N, 1);
        update(B, inputs[A], tree, 1, N, 1);
        std::swap(inputs[A], inputs[B]);
      }
    }
  }
  return 0;
}
