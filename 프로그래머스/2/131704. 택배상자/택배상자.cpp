#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> order) 
{
    std::stack<int> st;
    int answer = 0;
    int start = 1;
    for(const auto& iter : order)
    {
        while(start <= iter)
            st.push(start++);
        if(st.size() && st.top() == iter)
        {
            st.pop();
            answer++;
        }
        else break;
    }
    return answer;
}