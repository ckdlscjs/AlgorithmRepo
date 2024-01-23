#include <bits/stdc++.h>
using namespace std;
std::stack<int> st;
int solution(vector<int> ingredient) 
{
    int answer = 0;
    for(const auto& val : ingredient)
    {
        st.push(val);
        if(st.size() >= 4 && st.top() == 1)
        {
            int check[4];
            for(int i = 0; i < 4; i++)
            {
                check[i] = st.top();
                st.pop();
            }
            if(check[0] == 1 && check[1] == 3 && check[2] == 2 && check[3] == 1)
                answer++;
            else
            {
                for(int i = 3; i >= 0; i--)
                {
                    st.push(check[i]);
                }
            }
        }
    }
    
    return answer;
}