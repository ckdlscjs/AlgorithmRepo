//https://school.programmers.co.kr/learn/courses/30/lessons/42628
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> operations) 
{
    std::priority_queue<int, std::vector<int>, std::less<int>> hi_low;
    std::priority_queue<int, std::vector<int>, std::greater<int>> low_hi;
    int cnt = 0;
    for(const auto& iter : operations)
    {
        std::string order = iter.substr(0, 1);
        int num = std::stoi(iter.substr(2));
        if(order == "I")
        {
            cnt++;
            hi_low.push(num);
            low_hi.push(num);
        }
        else
        {
            if(cnt > 0)
            {
                if(num == 1)
                    hi_low.pop();
                else
                    low_hi.pop();
                cnt--;
            }
            std::stack<int> st;
            if(hi_low.size() > cnt)
            {
                while(hi_low.size() != 1)
                    st.push(hi_low.top()), hi_low.pop();
                hi_low.pop();
                while(st.size())
                    hi_low.push(st.top()), st.pop();
            }
            if(low_hi.size() > cnt)
            {
                while(low_hi.size() != 1)
                    st.push(low_hi.top()), low_hi.pop();
                low_hi.pop();
                while(st.size())
                    low_hi.push(st.top()), st.pop();
            }
        }
    }

    return cnt <= 0 ? std::vector<int>({0, 0}) : std::vector<int>({hi_low.top(), low_hi.top()});
}