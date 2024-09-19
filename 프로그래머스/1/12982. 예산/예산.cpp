#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> d, int budget) 
{
    std::sort(d.begin(), d.end(), std::less<>());
    int answer = 0;
    for(const auto& iter : d)
    {
        if(iter > budget)
            break;
        budget -= iter;
        answer++;
    }
    return answer;
}