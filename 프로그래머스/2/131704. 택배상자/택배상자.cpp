#include <bits/stdc++.h>
using namespace std;
std::stack<int> st;
int solution(vector<int> order) 
{
    int answer = 0;
    int idx = 1;
    for(const auto& iter : order)
    {
        while(iter >= idx)
        {
            st.push(idx++);
        }
        if(iter == st.top())
        {
            st.pop();
            answer++;
        }
        else
        {
            break;
        }
    }
    return answer;
}