#include <bits/stdc++.h>
using namespace std;
std::unordered_map<std::string, int> cnts;
vector<int> solution(vector<string> gems) 
{
    for(const auto& iter : gems)
    {
        cnts.insert({iter, 0});
    }
    vector<int> answer(2, 0);
    answer[1] = 100'005;
    cnts[gems[gems.size()-1]]++;
    int cnt = 1;
    for(int l = gems.size()-1, r = gems.size()-1; l <= r && 0 <= l;)
    {
        if(cnt >= cnts.size())
        {
            if(r - l <= answer[1] - answer[0])
            {
                answer[0] = l + 1;
                answer[1] = r + 1;
            }
            cnts[gems[r]]--;
            if(cnts[gems[r]] <= 0) cnt--;
            if(l == r)
            {
                l--;
                if(l < 0) break;
                cnts[gems[l]]++;
                if(cnts[gems[l]] == 1) cnt++;
            }
            r--;
        }
        else
        {
            l--;
            if(l < 0) break;
            cnts[gems[l]]++;
            if(cnts[gems[l]] == 1) cnt++;
        }
    }
    return answer;
}