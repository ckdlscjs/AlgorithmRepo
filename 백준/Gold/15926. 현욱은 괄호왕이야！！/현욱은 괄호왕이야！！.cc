#include <bits/stdc++.h>
int n;
std::string str;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> str;
    std::stack<int> st;
    st.push(-1);
    int len = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
        {
            st.push(i);
        }
        else
        {   
            st.pop();
            if(st.size()) len = std::max(len, i-st.top());
            else st.push(i);
        }
       
    }   
    std::cout << len;
    return 0;
}