auto fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> st;
        for(const auto& iter : tokens)
        {
            if(iter.size() >= 2 || std::isdigit(iter[0]))
            {
                st.push(std::stoi(iter));
            }
            else
            {
                int lval = st.top(); st.pop();
                int rval = st.top(); st.pop();
                int num = 0;
                switch(iter[0])
                {
                    case '+' :
                    {
                        num = rval + lval;
                        break;
                    }
                    case '-' :
                    {
                        num = rval - lval;
                        break;
                    }
                    case '*' :
                    {
                        num = rval * lval;
                        break;
                    }
                    case '/' :
                    {
                        num = rval / lval;
                        break;
                    }
                }
                st.push(num);
            }   
        }
        return st.top();
    }
};