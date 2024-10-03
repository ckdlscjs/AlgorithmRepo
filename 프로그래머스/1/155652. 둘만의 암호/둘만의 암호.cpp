//https://school.programmers.co.kr/learn/courses/30/lessons/155652
#include <bits/stdc++.h>
using namespace std;
bool skips[26];
string solution(string s, string skip, int index) 
{
    for(const auto& ch : skip)
        skips[ch-'a'] = true;
    for(auto& iter : s)
    {
        int cnt = index;
        while(cnt)
        {
            iter++;
            if(iter > 'z')
                iter = 'a';
            if(skips[iter-'a'])
                continue;
            cnt--;
        }
    }
    return s;
}