#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    for(left; left <= right; left++)
    {
        long long int i = left / n;
        long long int j = left % n;
        answer.push_back(std::max(i, j) + 1);
    }
    
    return answer;
}