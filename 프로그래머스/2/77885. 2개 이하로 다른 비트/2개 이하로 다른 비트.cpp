#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> solution(vector<long long> numbers) 
{
    vector<ll> answer;
    for(const auto& iter : numbers)
    {
        ll cur = (ll)1e15 + 1LL;
        
        for(int i = 63; i >= 0; i--)
        {
            ll temp = (1LL << i) ^ iter;
            if(temp > iter)
                cur = std::min(cur, temp);
            for(int j = i-1; j >= 0; j--)
            {
                ll temp2 = (1LL << j) ^ temp;
                if(temp2 > iter)
                    cur = std::min(cur, temp2);
            }
        }
        answer.push_back(cur);
    }
    
    return answer;
}