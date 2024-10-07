#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    std::stack<int> st;
    vector<int> answer(prices.size(), 0);
    for(int i = 0; i < prices.size(); i++)
    {
        while(st.size() && prices[st.top()] > prices[i])
        {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while(st.size())
    {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
        
    return answer;
}