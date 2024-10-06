//https://school.programmers.co.kr/learn/courses/30/lessons/133502
#include <bits/stdc++.h>
using namespace std;
std::string chk = "1321";
int solution(vector<int> ingredient) 
{
    int answer = 0;
    std::stack<int> st;
    for(const auto& iter : ingredient)
    {
        st.push(iter);
        if(st.size() < 4 || st.top() != 1)
            continue;
        std::string temp = "";
        for(int i = 0; i < 4; i++)
        {
            temp += std::to_string(st.top());
            st.pop();
        }
        if(temp == chk)
        {
            answer++;
            continue;
        } 
       for(auto iter = temp.rbegin(); iter != temp.rend(); iter++)
           st.push(*iter - '0');
    }
    return answer;
}