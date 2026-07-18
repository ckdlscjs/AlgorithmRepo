
class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        std::vector<int> rets(temp.size(), 0);
        std::stack<int> st;
        for(int i = temp.size()-1; i >= 0; i--)
        {
            while(st.size() && temp[st.top()] <= temp[i])
                st.pop();
            rets[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return rets;
    }
};