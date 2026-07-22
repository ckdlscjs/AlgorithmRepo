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
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int ret = 0;
        for(int i = 0; i < tickets.size(); i++)
        {
            if(tickets[i] < tickets[k]) ret += tickets[i];
            else
            {
                if(i <= k) ret += tickets[k];
                else ret += tickets[k] - 1;
            }
        }
       
        return ret;
    }
};