#include <bits/stdc++.h>
long long int n, start, end, sum, cnt;
const int MaxN = 4'000'005;
const int bitMaskN = (MaxN/32) + 1;
int NotPrime[bitMaskN];
std::vector<int> primes;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 2; i <= MaxN; i++)
    {
      if(NotPrime[i / 32] & (1 << (i%32)))
        continue;
      primes.push_back(i);
      //std::cout << i <<'\n';
      for(int j = 2; i*j <= MaxN; j++)
        NotPrime[i*j / 32] |= (1 << (i*j % 32));
    }
    while(end <= primes.size() && start <= end)
    {
      if(sum < n) sum += primes[end++];
      else sum -= primes[start++];
      if(sum == n) cnt++;
    }
    std::cout << cnt;
    return 0;
}