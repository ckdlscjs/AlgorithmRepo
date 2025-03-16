#include <bits/stdc++.h>
using namespace std;
vector<long long> solution(vector<long long> numbers) 
{
    vector<long long> answer;
    for(const auto& iter : numbers)
    {
        long long int bit = 1;
        while((bit & iter)) bit <<= 1;
        answer.push_back(iter + bit - (bit>>1));
    }
    return answer;
}