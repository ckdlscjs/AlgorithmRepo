#include <bits/stdc++.h>
using namespace std;
int N, arr[100'005];
std::map<int, int> cnts;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++)
    {
        std::cin >> arr[n];
        cnts[arr[n]] = 0;
    }
    for(const auto& iter : cnts)
    {
        for(int s = 2; iter.first * s <= (--cnts.end())->first; s++)
        {
            if(cnts.find(iter.first * s) != cnts.end())
            {
                cnts[iter.first]++;
                cnts[iter.first*s]--;
            }
        }
    }
    for(int n = 0; n < N; n++)
    {
        std::cout << cnts[arr[n]] << ' ';
    }
    
    return 0;
}