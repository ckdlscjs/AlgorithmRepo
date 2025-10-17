#include <bits/stdc++.h>
using namespace std;
char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
string solution(int n, int t, int m, int p) 
{
    p--;
    int idx = 0;
    int num = 0;
    string answer = "";
    while(answer.size() < t)
    {
        std::stack<char> st;
        int cur = num;
        while(cur)
        {
            st.push(ch[cur % n]);
            //std::cout << ch[cur%n];
            cur /= n;
        }
        if(num == 0)
            st.push(ch[0]);
        while(st.size())
        {
            if(idx == p)
                answer += st.top();
            st.pop();
            idx++;
            idx %= m;
        }
        num++;
    }
    
    return answer.substr(0, t);
}