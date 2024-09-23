#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> arr) 
{
    std::sort(arr.begin(), arr.end(), std::less<>());
    int small = 1;
    int answer = 0;
    for(const auto& iter : arr)
    {
        int big = std::max(iter, small);
        int gcd = std::min(iter, small);
        while(big % gcd)
        {
            int temp = big % gcd;
            big = gcd;
            gcd = temp;
        }
        answer = iter * small / gcd;
        small = answer;
    }
    
    return answer;
}