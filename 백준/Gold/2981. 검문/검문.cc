#include <bits/stdc++.h>
using namespace std;
int N, arr[105];
std::vector<int> gaps;
std::set<int> ret;
int GCD(int large, int small)
{
    return large % small ? GCD(small, large%small) : small;
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    std::sort(arr, arr+N);
    for(int n = 0; n < N-1; n++)
    {
        gaps.push_back(arr[n+1] - arr[n]);
    }
    int M = gaps[0];
    for(int i = 1; i < gaps.size(); i++)
    {
        M = GCD(std::max(gaps[i], M), std::min(gaps[i], M));
    }
    ret.insert(M);
    for(int i = 2; i*i <= M; i++)
    {
        if(M % i == 0)
        {
            ret.insert(i);
            ret.insert(M/i);
        }
    }
        
    for(const auto& iter : ret)
        std::cout << iter << ' ';
    return 0;
}
