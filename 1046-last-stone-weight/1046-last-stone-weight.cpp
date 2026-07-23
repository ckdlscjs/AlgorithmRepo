auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
};
class Solution 
{
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        std::priority_queue<int, std::vector<int>, std::less<>> pq(stones.begin(), stones.end());
        while(pq.size() > 1)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x == y) continue;
            else if(x < y) pq.push(y - x);
            else pq.push(x - y);
        }
        pq.push(0);
        return pq.top();
    }
};