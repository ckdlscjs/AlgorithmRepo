#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;
    for(left; left <= right; left++)
        answer.push_back(std::max(left / n, left % n) + 1);
    
    return answer;
}