#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    std::vector<int> answer;
    std::stack<int> st;
    for(int i = 0; i < arr.size(); i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
        }
        else
        {
            if(st.top() == arr[i])
            {
                 continue;
            }
            else
            {
                int num = st.top();
                st.pop();
                st.push(arr[i]);
                answer.push_back(num);
            }
        }
    }
    answer.push_back(st.top());
    return answer;
}