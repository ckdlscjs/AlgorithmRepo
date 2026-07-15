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
    vector<string> buildArray(vector<int>& target, int n) 
    {
        std::vector<std::string> rets;
        int cur = 1;
        int top = 0;
        for(const auto& iter : target)
        {
            while(cur <= iter)
            {
                rets.push_back("Push");
                top = cur;
                cur++;
                if(top != iter)
                    rets.push_back("Pop");
            }
        }
        return rets;
    }
};