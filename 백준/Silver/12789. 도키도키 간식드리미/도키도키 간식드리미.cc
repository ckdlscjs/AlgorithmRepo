#include <bits/stdc++.h>
int n, idx;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    idx = 1;
    std::stack<int> st;
    for(int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        st.push(input);
        while(st.size() && st.top() == idx)
        {
          idx++;
          st.pop();
        }
    }
    while(st.size())
    {
        if(st.top() == idx)
        {
            st.pop();
            idx++;
            continue;
        }
        std::cout << "Sad";
        return 0;
    }
    std::cout << "Nice";
    return 0;
}