#include <bits/stdc++.h>
using namespace std;
std::string str;
int idx, cnt;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(std::cin>>str)
    {
        if(str[0] == '-') break;
        std::stack<char> st;
        cnt = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(st.size() && st.top() == '{' && str[i] == '}') st.pop();
            else st.push(str[i]);
        }
        while(st.size())
        {
            char c1 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            if(c1 != c2) cnt += 2;
            else cnt += 1;
        }
        std::cout << idx++ + 1 <<". " << cnt << '\n';
    }
    return 0;
}
