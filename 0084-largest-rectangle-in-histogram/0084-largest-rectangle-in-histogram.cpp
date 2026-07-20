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
    int largestRectangleArea(vector<int>& hs) 
    {
        hs.push_back(-1);
        std::stack<int> st;
        int largest = 0;
        for(int i = 0; i < hs.size(); i++)
        {
            while(!st.empty() && hs[st.top()] > hs[i])
            {
                int height = hs[st.top()]; 
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                largest = std::max(largest, height * width);
            }
            st.push(i);
        }
        return largest;
    }
};