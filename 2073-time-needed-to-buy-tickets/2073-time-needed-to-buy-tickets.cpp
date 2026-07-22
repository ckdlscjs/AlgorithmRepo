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
        std::queue<int> q;
        for(int i = 0; i < tickets.size(); i++)
            q.push(i);
        int ret = 0;
        while(tickets[k] > 0)
        {
            int cur = q.front(); q.pop();
            tickets[cur]--;
            if(tickets[cur] > 0)
                q.push(cur);
            ret++;
        }
        return ret;
    }
};