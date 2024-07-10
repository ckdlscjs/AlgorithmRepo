#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int solution(string s) 
{
    std::unordered_map<char, char> oper;
    oper['('] = ')';
    oper['{'] = '}';
    oper['['] = ']';
    int answer = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        std::stack<char> st;
        int cnt = 0;
        for(int j = 0 + i; j - i < s.size(); j++)
        {
            int idx = j % s.size();
            if(oper.find(s[idx]) != oper.end())
            {
                st.push(s[idx]);
            }
            else
            {
                if(st.empty())
                    break;
                if(oper[st.top()] == s[idx])
                {
                    cnt++;
                    st.pop();
                    continue;
                }
                break;
            }
        }
        if(st.size() || cnt != s.size()/2)
            continue;
        answer++;
    }
    return answer;
}