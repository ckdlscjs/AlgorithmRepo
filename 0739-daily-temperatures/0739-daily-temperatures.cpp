auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        std::vector<int> rets(temp.size(), 0);
        std::stack<int> st;
        for(int i = temp.size()-1; i >= 0; i--)
        {
            while(!st.empty() && temp[st.top()] <= temp[i])
                st.pop();
            rets[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return rets;
    }
};