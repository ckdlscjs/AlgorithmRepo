//https://school.programmers.co.kr/learn/courses/30/lessons/154539
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> numbers) 
{
    std::stack<int> st;
    vector<int> answer(numbers.size(), -1);
    for(int i = 0; i < numbers.size(); i++)
    {
        while(st.size() && numbers[st.top()] < numbers[i])
            answer[st.top()] = numbers[i], st.pop();
        st.push(i);
    }
   
    return answer;
}