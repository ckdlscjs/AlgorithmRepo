#include <bits/stdc++.h>
using namespace std;
std::stack<char> st;
int solution(string s)
{
    for(const char& ch : s)
    {
        if(st.size() && st.top() == ch)
        {
            st.pop();
        }
        else
            st.push(ch);
    }

    return st.size() ? 0 : 1;
}