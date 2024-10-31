//https://school.programmers.co.kr/learn/courses/30/lessons/154539
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) 
{
    std::stack<int> st;
    vector<int> answer;
    for(int i = numbers.size() - 1; i >= 0; i--)
    {
        if(st.empty())
        {
            answer.push_back(-1);
            st.push(numbers[i]);
        }
        else
        {
            while(st.size() && st.top() <= numbers[i])
                st.pop();
            if(st.size())
                answer.push_back(st.top());
            else
                answer.push_back(-1);
            st.push(numbers[i]);
        }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}