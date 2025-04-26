#include <bits/stdc++.h>
using namespace std;
int N, arr[100'005];
bool chks[1'000'005];
int cnts[1'000'005];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        chks[arr[n]] = true;
    }
    for(int i = 1; i <= 1'000'000; i++)
    {
        if(!chks[i]) continue;
        for(int s = 2; i * s <= 1'000'000; s++)
        {
            if(chks[i*s])
            {
                cnts[i]++;
                cnts[i*s]--;
            }
        }
    }
    for(int n = 0; n < N; n++)
    {
        std::cout << cnts[arr[n]] << ' ';
    }
    
    return 0;
}