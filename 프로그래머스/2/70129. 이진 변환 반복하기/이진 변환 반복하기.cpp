#include <bits/stdc++.h>
using namespace std;
vector<int> solution(string s) 
{
    vector<int> answer;
    int cnt_change = 0;
    int cnt_zero = 0;
  
    while(s != "1")
    {
        std::string temps;
        for(const auto& iter : s)
        {
            if(iter == '1')
                temps += iter;
            else
                cnt_zero++;
        }
        int s_size = temps.size();
        s.clear();
        while(s_size > 0)
        {
            s += std::to_string(s_size % 2);
            s_size /= 2;
        }
        std::reverse(s.begin(), s.end());
        cnt_change++;
    }
    answer.push_back(cnt_change);
    answer.push_back(cnt_zero);
    return answer;
}