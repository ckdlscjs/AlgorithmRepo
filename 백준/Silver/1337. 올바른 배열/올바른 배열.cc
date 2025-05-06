#include <bits/stdc++.h>
using namespace std;
int N, lis = 5, val;
std::set<int> chks;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> val;
        chks.insert(val);
    }
    for(const auto& iter : chks)
    {
        int cur = 1;
        for(int j = 1; j <= 4; j++)
        {
            if(chks.find(iter + j) != chks.end())
                cur++;
        }
        lis = std::min(lis, 5-cur);
    }
    std::cout << lis;
    return 0;
}
