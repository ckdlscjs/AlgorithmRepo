#include <bits/stdc++.h>


using namespace std;

int solution(string s) 
{
    int answer = 0;
    for(int i = 0; i < s.size()-1; i++)
    {
        std::stack<char> st;
        for(int j = 0; j < s.size(); j++)
        {
            int idx = (j + i) % s.size();
            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '[') st.push(s[idx]);
            else
            {
                if(st.empty())
                {
                    st.push(s[idx]);
                    break;
                }
                else if(st.top() == '(' && s[idx] != ')') break;
                else if(st.top() == '{' && s[idx] != '}') break;
                else if(st.top() == '[' && s[idx] != ']') break;
                st.pop();
            }
        }
        if(st.empty()) answer++;
    }
    return answer;
}