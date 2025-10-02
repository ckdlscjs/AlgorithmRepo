#include <bits/stdc++.h>
using namespace std;
std::stack<char> st;
int solution(string s)
{
    for(const auto& ch : s)
    {
        if(st.size() && st.top() == ch) st.pop();
        else st.push(ch);
    }
    return st.empty() ? 1 : 0;
}