#include <bits/stdc++.h>

using namespace std;
std::stack<char> st;
bool solution(string s)
{
    for(const char& ch : s)
    {
        if(ch == '(')
            st.push(ch);
        else
            if(st.size())
                st.pop();
            else
                return false;
    }


    return st.size() ? false : true;
}