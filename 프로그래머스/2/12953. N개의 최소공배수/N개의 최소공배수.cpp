#include <bits/stdc++.h>
using namespace std;
int gcd(int large, int small)
{
    if(large % small == 0) return small;
    return gcd(small, large % small);
}
int solution(vector<int> arr) 
{
    std::sort(arr.begin(), arr.end());
    int _lcm = 1;
    for(const auto& iter : arr)
    {
        int large = std::max(iter, _lcm);
        int small = std::min(iter, _lcm);
        int _gcd = gcd(large, small);
        _lcm = iter * _lcm / _gcd;
    }
    return _lcm;
}