#include <bits/stdc++.h>

using namespace std;
long long cnts[1'002];
long long solution(vector<int> weights) 
{
    long long answer = 0;
    for(const auto& iter : weights)
        cnts[iter]++;
    for(const auto& iter : weights)
    {
        if(iter * 2 <= 1'000) answer += cnts[iter*2];
        if(iter % 2 == 0 && iter / 2 * 3 <= 1'000) answer += cnts[iter / 2 * 3];
        if(iter % 3 == 0 && iter / 3 * 4 <= 1'000) answer += cnts[iter / 3 * 4];
    }
    for(int i = 100; i <= 1'000; i++)
        answer += cnts[i] * (cnts[i] - 1) / 2;
   
    return answer;
}