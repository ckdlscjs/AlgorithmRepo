#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    std::stack<int> st;
    for(int i = numbers.size()-1; i >= 0; i--)
    {
        if(st.empty()) 
        {
            answer.push_back(-1);
        }
        else
        {
            if(numbers[st.top()] > numbers[i])
            {
                answer.push_back(numbers[st.top()]);
            }
            else
            {
                while(st.size() && numbers[st.top()] <= numbers[i])
                    st.pop();
                if(st.empty()) answer.push_back(-1);
                else answer.push_back(numbers[st.top()]);
            }
        }
        st.push(i);
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}