#include <bits/stdc++.h>
using namespace std;
bool NotPrime[10'005];
int T, N;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    NotPrime[0] = NotPrime[1] = true;
    for(int i = 2; i <= 10'005; i++)
    {
        if(NotPrime[i]) continue;
        for(int j = 2; i * j <= 10'005; j++)
            NotPrime[i*j] = true;
    }
    std::cin >> T;
    while(T--)
    {
        std::cin >> N;
        for(int i = N/2; i >= 2; i--)
        {
            if(!NotPrime[i] && !NotPrime[N-i])
            {
                std::cout << i << ' ' << N-i << '\n';
                break;
            }
        }
    }
    
    return 0;
}
