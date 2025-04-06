#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
std::vector<long long> primes;
std::map<long long, long long> factorizeA, factorizeB;
long long N, M, num, ret = 1, NotPrimes[40000];
bool bigInt = false;
void Factorization(long long num, std::map<long long, long long>& factorize)
{
    for(const auto& iter : primes)
    {
        if(iter*iter > num) break;
        while(num % iter == 0)
        {
            factorize[iter]++;
            num /= iter;
        }
    }
    if(num > 1) factorize[num]++;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    NotPrimes[0] = NotPrimes[1] = true;
    for(int i = 2; i <= 31700; i++)
    {
        if(NotPrimes[i]) continue;
        primes.push_back(i);
        for(int j = 2; i*j <= 31700; j++)
            NotPrimes[i*j] = true;
    }
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> num;
        Factorization(num, factorizeA);
    }
    std::cin >> M;
    for(int m = 0; m < M; m++)
    {
        std::cin >> num;
        Factorization(num, factorizeB);
    }
    
    for(const auto& iter : factorizeA)
    {
        if(factorizeB.find(iter.first) == factorizeB.end()) continue;
        long long cnt = std::min(iter.second, factorizeB[iter.first]);
        while(cnt--)
        {
            ret *= iter.first;
            if(ret >= INF)
            {
                bigInt = true;
                ret %= INF;
            }
        }
    }
    if(bigInt)
        std::cout << std::setw(9) << std::setfill('0');
    std::cout << ret;
    return 0;
}
