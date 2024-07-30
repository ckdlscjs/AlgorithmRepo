#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) 
{
    std::sort(times.begin(), times.end(), std::less<>());
    long long int left = 1;
    long long int right = 1000000000000000000;
    long long int answer = 0;
    while(left <= right)
    {
        long long int mid = (left + right) / 2;
        long long int passed = 0;
        for(int i = 0; i < times.size(); i++)
            passed += mid / (long long int)times[i];
        if(passed >= n)
        {
            right = mid - 1;
            answer = mid;
        }
        else
            left = mid+1;
    }
    return answer;
}