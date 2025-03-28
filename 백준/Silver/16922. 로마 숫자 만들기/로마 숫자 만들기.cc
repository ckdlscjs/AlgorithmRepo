#include <bits/stdc++.h>
using namespace std;
int N, arr[] = {1, 5, 10, 50};
std::set<int> dp[22];
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    dp[0].insert(0);
    for(int n = 1; n <= N; n++)
    {
        for(int i = 0; i < 4; i++)
        {
            for(const auto& iter : dp[n-1])
                dp[n].insert(iter + arr[i]);
        }
    }
    std::cout << dp[N].size();
    return 0;
}
